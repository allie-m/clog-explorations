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
    #[derive(Clone, Debug)]
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
                        self.mat.swap(0, 1);
                        self.mat.swap(2, 3);
                        self.mat[0] += self.mat[1].clone();
                        self.mat[2] += self.mat[3].clone();
                    }
                    Some(Term::Rec | Term::RecSpec) => {
                        self.mat.swap(0, 1);
                        self.mat.swap(2, 3);
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
                if (self.mat[0] < 0.into()) != (self.mat[2] < 0.into()) {
                    self.mat[0] = -self.mat[0].clone();
                    self.mat[1] = -self.mat[1].clone();
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
                } else if self.mat[0] >= self.mat[2]
                    && self.mat[1] >= self.mat[3]
                    && (self.mat[0].clone() >> 1) < self.mat[2]
                    && (self.mat[1].clone() >> 1) < self.mat[3]
                {
                    self.mat[0] -= self.mat[2].clone();
                    self.mat[1] -= self.mat[3].clone();
                    self.mat.swap(0, 2);
                    self.mat.swap(1, 3);
                    return Some(Term::DRec);
                } else if self.mat[0] < self.mat[2] && self.mat[1] < self.mat[3] {
                    self.mat.swap(0, 2);
                    self.mat.swap(1, 3);
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
        singularity: bool,
    }
    impl<X: Stream, Y: Stream> Iterator for Blft<X, Y> {
        type Item = Term;
        fn next(&mut self) -> Option<Term> {
            if self.mat[4] == 0.into()
                && self.mat[5] == 0.into()
                && self.mat[6] == 0.into()
                && self.mat[7] == 0.into()
            {
                return None;
            }

            loop {
                // ingest from x
                match self.x.next() {
                    Some(Term::Ord | Term::OrdSpec | Term::OrdSingularity) => {
                        self.mat[0] <<= 1;
                        self.mat[1] <<= 1;
                        self.mat[4] <<= 1;
                        self.mat[5] <<= 1;
                    }
                    Some(Term::DRec | Term::DRecSpec) => {
                        self.mat.swap(0, 2);
                        self.mat.swap(1, 3);
                        self.mat.swap(4, 6);
                        self.mat.swap(5, 7);
                        self.mat[0] += self.mat[2].clone();
                        self.mat[1] += self.mat[3].clone();
                        self.mat[4] += self.mat[6].clone();
                        self.mat[5] += self.mat[7].clone();
                    }
                    Some(Term::Rec | Term::RecSpec) => {
                        self.mat.swap(0, 2);
                        self.mat.swap(1, 3);
                        self.mat.swap(4, 6);
                        self.mat.swap(5, 7);
                    }
                    Some(Term::Neg) => {
                        self.mat[0] = -self.mat[0].clone();
                        self.mat[1] = -self.mat[1].clone();
                        self.mat[4] = -self.mat[4].clone();
                        self.mat[5] = -self.mat[5].clone();
                    }
                    None => {
                        self.mat[2] = self.mat[0].clone();
                        self.mat[3] = self.mat[1].clone();
                        self.mat[6] = self.mat[4].clone();
                        self.mat[7] = self.mat[5].clone();
                    }
                }
                // ingest from y
                match self.y.next() {
                    Some(Term::Ord | Term::OrdSpec | Term::OrdSingularity) => {
                        self.mat[0] <<= 1;
                        self.mat[2] <<= 1;
                        self.mat[4] <<= 1;
                        self.mat[6] <<= 1;
                    }
                    Some(Term::DRec | Term::DRecSpec) => {
                        self.mat.swap(0, 1);
                        self.mat.swap(2, 3);
                        self.mat.swap(4, 5);
                        self.mat.swap(6, 7);
                        self.mat[0] += self.mat[1].clone();
                        self.mat[2] += self.mat[3].clone();
                        self.mat[4] += self.mat[5].clone();
                        self.mat[6] += self.mat[7].clone();
                    }
                    Some(Term::Rec | Term::RecSpec) => {
                        self.mat.swap(0, 1);
                        self.mat.swap(2, 3);
                        self.mat.swap(4, 5);
                        self.mat.swap(6, 7);
                    }
                    Some(Term::Neg) => {
                        self.mat[0] = -self.mat[0].clone();
                        self.mat[2] = -self.mat[2].clone();
                        self.mat[4] = -self.mat[4].clone();
                        self.mat[6] = -self.mat[6].clone();
                    }
                    None => {
                        self.mat[1] = self.mat[0].clone();
                        self.mat[3] = self.mat[1].clone();
                        self.mat[5] = self.mat[4].clone();
                        self.mat[7] = self.mat[6].clone();
                    }
                }
                // egest check

                // singularity management
                let s1 = (self.mat[0] < 0.into()) ^ (self.mat[4] < 0.into());
                let s2 = (self.mat[1] < 0.into()) ^ (self.mat[5] < 0.into());
                let s3 = (self.mat[2] < 0.into()) ^ (self.mat[6] < 0.into());
                let s4 = (self.mat[3] < 0.into()) ^ (self.mat[7] < 0.into());
                if self.singularity && (s1 != s2 || s2 != s3 || s3 != s4) {
                    let a1: BigInt = self.mat[4].clone() << 1;
                    let a2: BigInt = self.mat[5].clone() << 1;
                    let a3: BigInt = self.mat[6].clone() << 1;
                    let a4: BigInt = self.mat[7].clone() << 1;
                    if a1.into_parts().1 < self.mat[0].clone().into_parts().1
                        && a2.into_parts().1 < self.mat[1].clone().into_parts().1
                        && a3.into_parts().1 < self.mat[2].clone().into_parts().1
                        && a4.into_parts().1 < self.mat[3].clone().into_parts().1
                    {
                        if !self.mat[0].bit(0)
                            && !self.mat[1].bit(0)
                            && !self.mat[2].bit(0)
                            && !self.mat[3].bit(0)
                        {
                            self.mat[0] >>= 1;
                            self.mat[1] >>= 1;
                            self.mat[2] >>= 1;
                            self.mat[3] >>= 1;
                        } else {
                            self.mat[4] <<= 1;
                            self.mat[5] <<= 1;
                            self.mat[6] <<= 1;
                            self.mat[7] <<= 1;
                        }
                        return Some(Term::OrdSingularity);
                    } else {
                        continue;
                    }
                } else {
                    self.singularity = false;
                }

                // the normal stuff
                if (self.mat[0] < 0.into()) != (self.mat[4] < 0.into()) {
                    self.mat[0] = -self.mat[0].clone();
                    self.mat[1] = -self.mat[1].clone();
                    self.mat[2] = -self.mat[2].clone();
                    self.mat[3] = -self.mat[3].clone();
                    return Some(Term::Neg);
                } else if (self.mat[0].clone() >> 1) >= self.mat[4]
                    && (self.mat[1].clone() >> 1) >= self.mat[5]
                    && (self.mat[2].clone() >> 1) >= self.mat[6]
                    && (self.mat[3].clone() >> 1) >= self.mat[7]
                {
                    if !self.mat[0].bit(0)
                        && !self.mat[1].bit(0)
                        && !self.mat[2].bit(0)
                        && !self.mat[3].bit(0)
                    {
                        self.mat[0] >>= 1;
                        self.mat[1] >>= 1;
                        self.mat[2] >>= 1;
                        self.mat[3] >>= 1;
                    } else {
                        self.mat[4] <<= 1;
                        self.mat[5] <<= 1;
                        self.mat[6] <<= 1;
                        self.mat[7] <<= 1;
                    }
                    return Some(Term::Ord);
                } else if self.mat[0] >= self.mat[4]
                    && self.mat[1] >= self.mat[5]
                    && self.mat[2] >= self.mat[6]
                    && self.mat[3] >= self.mat[7]
                    && (self.mat[0].clone() >> 1) < self.mat[4]
                    && (self.mat[1].clone() >> 1) < self.mat[5]
                    && (self.mat[2].clone() >> 1) < self.mat[6]
                    && (self.mat[3].clone() >> 1) < self.mat[7]
                {
                    self.mat[0] -= self.mat[4].clone();
                    self.mat[1] -= self.mat[5].clone();
                    self.mat[2] -= self.mat[6].clone();
                    self.mat[3] -= self.mat[7].clone();
                    self.mat.swap(0, 4);
                    self.mat.swap(1, 5);
                    self.mat.swap(2, 6);
                    self.mat.swap(3, 7);
                    return Some(Term::DRec);
                } else if self.mat[0] < self.mat[4]
                    && self.mat[1] < self.mat[5]
                    && self.mat[2] < self.mat[6]
                    && self.mat[3] < self.mat[7]
                {
                    self.mat.swap(0, 4);
                    self.mat.swap(1, 5);
                    self.mat.swap(2, 6);
                    self.mat.swap(3, 7);
                    return Some(Term::Rec);
                }
                // the following are SPECULATIVE
                else if self.mat[4] < self.mat[0]
                    && self.mat[0] < (self.mat[4].clone() << 2)
                    && self.mat[5] < self.mat[1]
                    && self.mat[1] < (self.mat[5].clone() << 2)
                    && self.mat[6] < self.mat[2]
                    && self.mat[2] < (self.mat[6].clone() << 2)
                    && self.mat[7] < self.mat[3]
                    && self.mat[3] < (self.mat[7].clone() << 2)
                {
                    if !self.mat[0].bit(0)
                        && !self.mat[1].bit(0)
                        && !self.mat[2].bit(0)
                        && !self.mat[3].bit(0)
                    {
                        self.mat[0] >>= 1;
                        self.mat[1] >>= 1;
                        self.mat[2] >>= 1;
                        self.mat[3] >>= 1;
                    } else {
                        self.mat[4] <<= 1;
                        self.mat[5] <<= 1;
                        self.mat[6] <<= 1;
                        self.mat[7] <<= 1;
                    }
                    return Some(Term::OrdSpec);
                } else if self.mat[4] < (self.mat[0].clone() << 1)
                    && self.mat[0] < self.mat[4].clone() << 1
                    && self.mat[5] < (self.mat[1].clone() << 1)
                    && self.mat[1] < self.mat[5].clone() << 1
                    && self.mat[6] < (self.mat[2].clone() << 1)
                    && self.mat[2] < self.mat[6].clone() << 1
                    && self.mat[7] < (self.mat[3].clone() << 1)
                    && self.mat[3] < self.mat[7].clone() << 1
                {
                    self.mat[0] -= self.mat[4].clone();
                    self.mat[1] -= self.mat[5].clone();
                    self.mat[2] -= self.mat[6].clone();
                    self.mat[3] -= self.mat[7].clone();
                    self.mat.swap(0, 4);
                    self.mat.swap(1, 5);
                    self.mat.swap(2, 6);
                    self.mat.swap(3, 7);
                    self.singularity = true;
                    return Some(Term::DRecSpec);
                } else if self.mat[4].clone().into_parts().1 > self.mat[0].clone().into_parts().1
                    && self.mat[5].clone().into_parts().1 > self.mat[1].clone().into_parts().1
                    && self.mat[6].clone().into_parts().1 > self.mat[2].clone().into_parts().1
                    && self.mat[7].clone().into_parts().1 > self.mat[3].clone().into_parts().1
                {
                    self.mat.swap(0, 4);
                    self.mat.swap(1, 5);
                    self.mat.swap(2, 6);
                    self.mat.swap(3, 7);
                    self.singularity = true;
                    return Some(Term::RecSpec);
                }
            }
        }
    }
    impl<X: Stream, Y: Stream> Stream for Blft<X, Y> {}
    Blft {
        x,
        y,
        mat,
        singularity: false,
    }
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
