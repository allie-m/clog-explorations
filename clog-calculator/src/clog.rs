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

// nonspeculative;
// an lft can never become stuck at a decision boundary
// the way that a blft can
pub fn lft<X>(x: X, mat: [BigInt; 4]) -> impl Stream
where
    X: Stream,
{
    #[derive(Clone)]
    struct Lft<X: Stream> {
        x: X,
        mat: [BigInt; 4],
    }
    impl<X: Stream> Iterator for Lft<X> {
        type Item = Term;
        fn next(&mut self) -> Option<Term> {
            if self.mat[2] == 0.into() && self.mat[3] == 0.into() {
                return None;
            }
            // keep ingesting until you can egest
            loop {
                // ingest from x
                match self.x.next() {
                    Some(Term::Ord | Term::OrdSpec | Term::OrdSingularity) => {
                        self.mat[0] <<= 1;
                        self.mat[2] <<= 1;
                    }
                    Some(Term::DRec | Term::DRecSpec) => {
                        //
                    }
                    Some(Term::Rec | Term::RecSpec) => {
                        //
                    }
                    Some(Term::Neg) => {
                        self.mat[0] = -self.mat[0].clone();
                        self.mat[2] = -self.mat[2].clone();
                    }
                    None => {
                        self.mat[1] = self.mat[0].clone();
                        self.mat[3] = self.mat[2].clone();
                    }
                }
                // egest check
                if (self.mat[0] < 0.into() && self.mat[1] < 0.into())
                    ^ (self.mat[2] < 0.into() && self.mat[3] < 0.into())
                {
                    if self.mat[0] < 0.into() {
                        self.mat[0] = -self.mat[0].clone();
                        self.mat[1] = -self.mat[1].clone();
                    } else {
                        self.mat[2] = -self.mat[2].clone();
                        self.mat[3] = -self.mat[3].clone();
                    }
                    return Some(Term::Neg);
                } else if (self.mat[0].clone() >> 1) >= self.mat[2]
                    && (self.mat[1].clone() >> 1) >= self.mat[3]
                {
                    if !self.mat[0].bit(0) && !self.mat[1].bit(0) {
                        self.mat[0] >>= 1;
                        self.mat[1] >>= 1;
                    } else {
                        self.mat[2] <<= 1;
                        self.mat[3] <<= 1;
                    }
                    return Some(Term::Ord);
                } else if self.mat[0] >= self.mat[2] && self.mat[1] >= self.mat[3] {
                    return Some(Term::DRec);
                } else if self.mat[0] < self.mat[2] && self.mat[1] < self.mat[3] {
                    return Some(Term::Rec);
                }
            }
        }
    }
    impl<X: Stream> Stream for Lft<X> {}
    Lft { x, mat }
}

// speculative
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
