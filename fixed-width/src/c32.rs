//! This module contains a proof-of-concept software implementation of the c32
//! a fixed-width, 32-bit continued logarithm type.
//! 
//! See c32-spec.txt
//!
//! Aims to have approximate feature parity with f32.
//! 
//! Analogous in concept to a fixed-radix number;
//! see d32-spec.txt for a floating-point clog analog

use core::fmt::Debug;
use core::fmt::Formatter;

use bitflags::bitflags;

#[allow(non_camel_case_types)]
#[derive(Clone, Copy, Hash)]
pub struct c32(pub(crate) u32);

// internal helpers
impl c32 {
    pub(crate) fn unset_neg(&mut self) {
        self.0 &= !(1 << 31);
    }
    pub(crate) fn unset_rec(&mut self) {
        self.0 &= !(1 << 30)
    }
    pub(crate) fn unset_term(&mut self, index: u32) {
        self.0 &= !(1 << (29 - index));
    }
    pub(crate) fn set_neg(&mut self) {
        self.0 |= 1 << 31;
    }
    pub(crate) fn set_rec(&mut self) {
        self.0 |= 1 << 30;
    }
    pub(crate) fn set_ord(&mut self, index: u32) {
        self.0 |= 1 << (29 - index);
    }
}

pub mod consts {
    use super::c32;

    pub const UNDEFINED: c32 = c32(0b_11_00_0000_0000_0000_0000_0000_0000_0000);
    pub const ZERO: c32 = c32(0b_01_00_0000_0000_0000_0000_0000_0000_0000);
    pub const ONE: c32 = c32(0b_00_00_0000_0000_0000_0000_0000_0000_0000);
    pub const NEG_ONE: c32 = c32(0b_10_00_0000_0000_0000_0000_0000_0000_0000);
    pub const TWO: c32 = c32(0b_00_10_0000_0000_0000_0000_0000_0000_0000);
    pub const MAX: c32 = c32(0b_00_11_1111_1111_1111_1111_1111_1111_1111);
    pub const MIN: c32 = c32(0b_10_11_1111_1111_1111_1111_1111_1111_1111);
    pub const EPSILON: c32 = c32(0b_01_11_1111_1111_1111_1111_1111_1111_1111);
}

impl Debug for c32 {
    fn fmt(&self, f: &mut Formatter) -> Result<(), core::fmt::Error> {
        if self.0 == consts::ZERO.0 {
            return write!(f, "oo");
        }
        if (self.0 >> 31) & 1 == 1 {
            write!(f, "-")?
        }
        if (self.0 >> 30) & 1 == 1 {
            write!(f, "/")?
        }
        let word = (self.0 & 0x3fffffff) >> self.0.trailing_zeros();
        write!(f, "{:b}0oo", word)
    }
}

#[repr(u8)]
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum FromRationalFlag {
    EXACT = 0,
    TRUNCATED = 1,
}

#[allow(non_camel_case_types)]
pub struct m_srat {
    //
}

pub fn from_srat(mut num: i32, mut den: i32) -> (c32, FromRationalFlag) {
    if den == 0 {
        return (consts::UNDEFINED, FromRationalFlag::EXACT);
    }
    if num == 0 {
        return (consts::ZERO, FromRationalFlag::EXACT);
    }
    let mut out = c32(0);
    let mut index = 0;
    let mut mode = FromRationalFlag::EXACT;
    if num.signum() != den.signum() {
        out.set_neg();
    }
    num = num.abs();
    den = den.abs();
    if num < den {
        out.set_rec();
        core::mem::swap(&mut num, &mut den);
    }
    while den != 0 {
        if index == 30 {
            mode = FromRationalFlag::TRUNCATED;
            break;
        }
        if num >= den << 2 {
            out.set_ord(index);
            if num & 1 == 0 {
                num >>= 1;
            } else {
                den <<= 1;
            }
        } else if num >= den {
            num -= den;
            core::mem::swap(&mut num, &mut den);
        } // there's no other possibility
        index += 1;
    }
    (out, mode)
}

bitflags! {
    #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
    pub struct FtCompletionFlags: u8 {
        const EXACT         = 0b000;
        const TRUNCATED     = 0b001;
        const MAT_SATURATED = 0b010;
        const DIV_BY_ZERO   = 0b100;
    }
}

/// an opaque 128 bit type representing the coefficients
/// a, b, c, d in the lft
/// ```
/// ax + b
/// ======
/// cx + d
/// ```
/// with clog x
#[allow(non_camel_case_types)]
pub struct m_lft32(pub(crate) [i32; 4]);

pub fn lft32(mat: &mut m_lft32, x: c32) -> (c32, FtCompletionFlags) {
    todo!()
    // if mat.0[2] == 0 && mat.0[3] == 0 {
    //     return (consts::UNDEFINED, FtCompletionFlags::DIV_BY_ZERO);
    // }
    // let mut completion_mode = FtCompletionFlags::empty();
    // let mut out = c32(1 << 31);
    // let mut x_idx = 29;
    // let mut out_idx = 30i32;

    // // ingest the foreword if it's - or /
    // match x.0 >> 30 {
    //     0b00 => mat.0[0] = -mat.0[0], // '-'
    //     0b01 => {
    //         // '/'
    //         mat.0.swap(0, 1);
    //         mat.0.swap(2, 3);
    //     }
    //     _ => x_idx = 30,
    // };
    // while !(mat.0[2] == 0 && mat.0[3] == 0) {
    //     if x_idx > 0 {
    //         // ingestion
    //         match (x.0 >> x_idx) & 1 {
    //             0 => {
    //                 // '0'
    //                 if let Some(v) = mat.0[1].checked_add(mat.0[0]) {
    //                     mat.0[1] = v;
    //                 } else {
    //                     mat.0[1] = i32::MAX;
    //                     completion_mode |= FtCompletionFlags::MAT_SATURATED;
    //                 }
    //                 if let Some(v) = mat.0[3].checked_add(mat.0[2]) {
    //                     mat.0[3] = v;
    //                 } else {
    //                     mat.0[3] = i32::MAX;
    //                     completion_mode |= FtCompletionFlags::MAT_SATURATED;
    //                 }
    //                 // now we recip
    //                 mat.0.swap(0, 1);
    //                 mat.0.swap(2, 3);
    //             }
    //             1 => {
    //                 // '1'
    //                 if mat.0[1] & 1 == 0 && mat.0[3] & 1 == 0 {
    //                     mat.0[1] >>= 1;
    //                     mat.0[3] >>= 1;
    //                 } else {
    //                     if let Some(v) = mat.0[0].checked_mul(2) {
    //                         mat.0[0] = v;
    //                     } else {
    //                         mat.0[0] = i32::MAX;
    //                         completion_mode |= FtCompletionFlags::MAT_SATURATED;
    //                     }
    //                     if let Some(v) = mat.0[2].checked_mul(2) {
    //                         mat.0[2] = v;
    //                     } else {
    //                         mat.0[2] = i32::MAX;
    //                         completion_mode |= FtCompletionFlags::MAT_SATURATED;
    //                     }
    //                 }
    //             }
    //             _ => unreachable!(),
    //         }
    //         x_idx -= 1;
    //     }
    //     // egestion
    //     // we test at a/c and (a + b)/(c + d) since x is between 1 and oo
    //     // since we've already ingested the foreword
    //     let ocase_num = mat.0[0] + mat.0[1];
    //     let ocase_den = mat.0[2] + mat.0[3];
    //     if mat.0[0] >> 1 >= mat.0[2] && ocase_num >> 1 >= ocase_den {
    //         // egest 1
    //         if mat.0[0] & 1 == 0 && mat.0[1] & 1 == 0 {
    //             mat.0[0] >>= 1;
    //             mat.0[1] >>= 1;
    //         } else {
    //             if let Some(v) = mat.0[2].checked_mul(2) {
    //                 mat.0[2] = v;
    //             } else {
    //                 mat.0[2] = i32::MAX;
    //                 completion_mode |= FtCompletionFlags::MAT_SATURATED;
    //             }
    //             if let Some(v) = mat.0[3].checked_mul(2) {
    //                 mat.0[3] = v;
    //             } else {
    //                 mat.0[3] = i32::MAX;
    //                 completion_mode |= FtCompletionFlags::MAT_SATURATED;
    //             }
    //         }
    //         out.0 |= 1 << out_idx;
    //         if out_idx == 1 {
    //             completion_mode |= FtCompletionFlags::TRUNCATED;
    //             break;
    //         }
    //         out_idx -= 1;
    //     } else if mat.0[0] >= mat.0[2] && ocase_num >= ocase_den {
    //         // egest 0
    //         mat.0[0] -= mat.0[2];
    //         mat.0[1] -= mat.0[3];
    //         mat.0.swap(0, 2);
    //         mat.0.swap(1, 3);
    //         if out_idx == 1 {
    //             completion_mode |= FtCompletionFlags::TRUNCATED;
    //             break;
    //         }
    //         out_idx -= 1;
    //     } else if mat.0[0] < mat.0[2] && ocase_num < ocase_den {
    //         // egest '/'
    //         // CAN ONLY HAPPEN ONCE, AS THE FIRST OUT TERM
    //         mat.0.swap(0, 2);
    //         mat.0.swap(1, 3);
    //         out.0 = 0b01 << 30;
    //         if out_idx == 1 {
    //             completion_mode |= FtCompletionFlags::TRUNCATED;
    //             break;
    //         }
    //         out_idx = 29;
    //     } else if (mat.0[0] < 0 && mat.0[1] < 0) ^ (mat.0[2] < 0 && mat.0[3] < 0) {
    //         // egest '-'
    //         // CAN ONLY HAPPEN ONCE, AS THE FIRST OUT TERM
    //         if mat.0[0] < 0 && mat.0[1] < 0 {
    //             mat.0[0] = mat.0[0].abs();
    //             mat.0[1] = mat.0[1].abs();
    //         } else {
    //             mat.0[2] = mat.0[2].abs();
    //             mat.0[3] = mat.0[3].abs();
    //         }
    //         out.0 = 0;
    //         out_idx = 29;
    //     }
    // }

    // (out, completion_mode)
}

// #[allow(non_camel_case_types)]
// pub struct blft32([i32; 8]);
// #[allow(non_camel_case_types)]
// pub struct nlft32([i32; 8]);

// no speculative redundancy here
// too finite for that :)

// make sure to write these functions in the style of asm instructions and give ample info on time/space complexity etc
// TODO: USE FINE-GRAINED PROFILE LOGGING TO DOUBLE CHECK THE COMPLEXITY OF STUFF
// we need:
// DONE print (as clog terms)
// f32 <==> c32
// f64 <==> c32
// rational (32 bit) <==> c32
// cmp c32 c32
// cmp c32 f32
// cmp c32 f64
// TODO: what mat resolution needed? u32? u64 only for outputting c64
// need to smartly alternate between ingesting and egesting
// might end up lossy otherwise...
// lft mat c32 => mat c32
// blft mat c32 c32 => mat c32
// nlft mat c32 => mat c32
// pow c32 c32 => c32
// log c32 => c32
// TODO put the rest of the things you derive from log
// abs
// recip
// round/floor/ceil

// TODO examine where the c32 precision is clustered
