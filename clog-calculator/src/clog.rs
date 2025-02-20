use std::mem::swap;

use num_bigint::{BigInt, BigUint};

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

pub trait Stream: Iterator<Item = Term> + Clone {}

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
                if !self.den.bit(0) {
                    self.den <<= 1;
                } else {
                    self.num >>= 1;
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

pub fn lft<X, Y>(x: X, y: Y, mat: [BigInt; 4]) -> impl Stream
where
    X: Stream,
    Y: Stream,
{
    #[derive(Clone)]
    struct Lft<X: Stream, Y: Stream> {
        x: X,
        y: Y,
        mat: [BigInt; 4],
    }
    impl<X: Stream, Y: Stream> Iterator for Lft<X, Y> {
        type Item = Term;
        fn next(&mut self) -> Option<Term> {
            None
        }
    }
    impl<X: Stream, Y: Stream> Stream for Lft<X, Y> {}
    Lft { x, y, mat }
}

pub fn blft<X, Y>(x: X, y: Y, mat: [BigInt; 8]) -> impl Stream
where
    X: Stream,
    Y: Stream,
{
    #[derive(Clone)]
    struct Blft<X: Stream, Y: Stream> {
        x: X,
        y: Y,
        mat: [BigInt; 8],
    }
    impl<X: Stream, Y: Stream> Iterator for Blft<X, Y> {
        type Item = Term;
        fn next(&mut self) -> Option<Term> {
            None
        }
    }
    impl<X: Stream, Y: Stream> Stream for Blft<X, Y> {}
    Blft { x, y, mat }
}

pub fn nlft<X, Y>(x: X, y: Y, mat: [BigInt; 8]) -> impl Stream
where
    X: Stream,
    Y: Stream,
{
    #[derive(Clone)]
    struct Nlft<X: Stream, Y: Stream> {
        x: X,
        y: Y,
        mat: [BigInt; 8],
    }
    impl<X: Stream, Y: Stream> Iterator for Nlft<X, Y> {
        type Item = Term;
        fn next(&mut self) -> Option<Term> {
            None
        }
    }
    impl<X: Stream, Y: Stream> Stream for Nlft<X, Y> {}
    Nlft { x, y, mat }
}
