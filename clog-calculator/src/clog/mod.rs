mod blfts;
mod cmp;
mod log;
mod sqrt;
pub use blfts::*;
pub use cmp::*;
pub use log::*;
pub use sqrt::*;

use num_bigint::{BigInt, BigUint};
use std::mem::swap;

#[derive(Debug, Clone, Copy)]
pub enum Term {
    Ord,
    OrdSpec,
    OrdSingularity,
    DRec,
    DRecSpec,
    Rec,
    RecSpec,
    Neg,
}

// impl Term {
//     pub fn is_speculative(&self) -> bool {
//         match self {
//             Term::OrdSpec | Term::OrdSingularity | Term::DRecSpec | Term::RecSpec => true,
//             _ => false,
//         }
//     }
// }

pub trait Stream: Iterator<Item = Term> {}
impl Stream for Box<dyn Stream> {}

// pi
// e

// rational
// radix

// lft
// blft
// nlft
// log/exp
// log_b/pow
// sin/cos/tan/sinh/cosh/tanh

// rational conversions

pub fn terms_to_rational<S>(mut stream: S, count: u32) -> (BigInt, BigInt)
where
    S: Stream,
{
    let mut mat: [BigInt; 4] = [1.into(), 0.into(), 0.into(), 1.into()];
    for _ in 0..count {
        let term = stream.next();
        match term {
            Some(Term::Ord | Term::OrdSpec | Term::OrdSingularity) => {
                mat[0] <<= 1;
                mat[2] <<= 1;
            }
            Some(Term::DRec | Term::DRecSpec) => {
                mat.swap(0, 1);
                mat.swap(2, 3);
                mat[0] += mat[1].clone();
                mat[2] += mat[3].clone();
            }
            Some(Term::Rec | Term::RecSpec) => {
                mat.swap(0, 1);
                mat.swap(2, 3);
            }
            Some(Term::Neg) => {
                mat[0] = -mat[0].clone();
                mat[2] = -mat[2].clone();
            }
            None => {
                mat[1] = mat[0].clone();
                mat[3] = mat[2].clone();
                break;
            }
        }
    }
    let g = mat[0]
        .trailing_zeros()
        .unwrap_or(0)
        .min(mat[2].trailing_zeros().unwrap_or(0));
    if mat[0] < 0.into() && mat[2] < 0.into() {
        mat[0] *= -1;
        mat[2] *= -1;
    }
    if mat[0] == 0.into() {
        (0.into(), 1.into())
    } else {
        (mat[0].clone() >> g, mat[2].clone() >> g)
    }
}

// nonspeculative
pub fn rational(num: BigUint, den: BigUint, sign: i8) -> impl Stream {
    #[derive(Clone)]
    struct Rational {
        num: BigUint,
        den: BigUint,
        sign: i8,
    }
    impl Iterator for Rational {
        type Item = Term;
        fn next(&mut self) -> Option<Term> {
            if self.den == BigUint::from(0u32) {
                None
            } else if self.sign < 0 {
                self.sign = 1;
                Some(Term::Neg)
            } else if (self.num.clone() >> 1) >= self.den {
                if !self.num.bit(0) {
                    self.num >>= 1;
                } else {
                    self.den <<= 1;
                }
                Some(Term::Ord)
            } else if self.num >= self.den {
                self.num -= self.den.clone();
                swap(&mut self.num, &mut self.den);
                Some(Term::DRec)
            } else {
                swap(&mut self.num, &mut self.den);
                Some(Term::Rec)
            }
        }
    }
    impl Stream for Rational {}
    Rational { num, den, sign }
}

// // nonspeculative;
// // an lft can never become stuck at a decision boundary
// // the way that a blft can
// pub fn lft<X>(x: X, mat: [BigInt; 4]) -> impl Stream
// where
//     X: Stream,
// {
//     #[derive(Clone, Debug)]
//     struct Lft<X: Stream> {
//         x: X,
//         mat: [BigInt; 4],
//     }
//     impl<X: Stream> Iterator for Lft<X> {
//         type Item = Term;
//         fn next(&mut self) -> Option<Term> {
//             if self.mat[2] == 0.into() && self.mat[3] == 0.into() {
//                 return None;
//             }
//             // keep ingesting until you can egest
//             loop {
//                 // ingest from x
//                 match self.x.next() {
//                     Some(Term::Ord | Term::OrdSpec | Term::OrdSingularity) => {
//                         self.mat[0] <<= 1;
//                         self.mat[2] <<= 1;
//                     }
//                     Some(Term::DRec | Term::DRecSpec) => {
//                         self.mat.swap(0, 1);
//                         self.mat.swap(2, 3);
//                         self.mat[0] += self.mat[1].clone();
//                         self.mat[2] += self.mat[3].clone();
//                     }
//                     Some(Term::Rec | Term::RecSpec) => {
//                         self.mat.swap(0, 1);
//                         self.mat.swap(2, 3);
//                     }
//                     Some(Term::Neg) => {
//                         self.mat[0] = -self.mat[0].clone();
//                         self.mat[2] = -self.mat[2].clone();
//                     }
//                     None => {
//                         self.mat[1] = self.mat[0].clone();
//                         self.mat[3] = self.mat[2].clone();
//                     }
//                 }
//                 // egest check
//                 if (self.mat[0] < 0.into()) != (self.mat[2] < 0.into()) {
//                     self.mat[0] = -self.mat[0].clone();
//                     self.mat[1] = -self.mat[1].clone();
//                     return Some(Term::Neg);
//                 } else if (self.mat[0].clone() >> 1) >= self.mat[2]
//                     && (self.mat[1].clone() >> 1) >= self.mat[3]
//                 {
//                     if !self.mat[0].bit(0) && !self.mat[1].bit(0) {
//                         self.mat[0] >>= 1;
//                         self.mat[1] >>= 1;
//                     } else {
//                         self.mat[2] <<= 1;
//                         self.mat[3] <<= 1;
//                     }
//                     return Some(Term::Ord);
//                 } else if self.mat[0] >= self.mat[2]
//                     && self.mat[1] >= self.mat[3]
//                     && (self.mat[0].clone() >> 1) < self.mat[2]
//                     && (self.mat[1].clone() >> 1) < self.mat[3]
//                 {
//                     self.mat[0] -= self.mat[2].clone();
//                     self.mat[1] -= self.mat[3].clone();
//                     self.mat.swap(0, 2);
//                     self.mat.swap(1, 3);
//                     return Some(Term::DRec);
//                 } else if self.mat[0] < self.mat[2] && self.mat[1] < self.mat[3] {
//                     self.mat.swap(0, 2);
//                     self.mat.swap(1, 3);
//                     return Some(Term::Rec);
//                 }
//             }
//         }
//     }
//     impl<X: Stream> Stream for Lft<X> {}
//     Lft { x, mat }
// }
