use num_bigint::BigInt;

use crate::clog::{Stream, Term};

// shouldn't need to be speculative
// since cfracs decide explicitly which side of 2 they're on
// is a basic lft
pub fn cfrac_to_clog<X>(x: X, mat: [BigInt; 4]) -> impl Stream
where
    X: Iterator<Item = i64>,
{
    struct CFrac<X: Iterator<Item = i64>> {
        x: X,
        mat: [BigInt; 4],
    }
    impl<X: Iterator<Item = i64>> Iterator for CFrac<X> {
        type Item = Term;

        fn next(&mut self) -> Option<Self::Item> {
            loop {
                // ingest terms
                let t = self.x.next();
                // println!("{:?} | {:?}", t, self.mat);
                match t {
                    Some(t) => {
                        let i = self.mat[0].clone();
                        self.mat[0] *= t;
                        self.mat[0] += self.mat[1].clone();
                        self.mat[1] = i;
                        let i = self.mat[2].clone();
                        self.mat[2] *= t;
                        self.mat[2] += self.mat[3].clone();
                        self.mat[3] = i;
                    }
                    None => {
                        // ingesting oo
                        self.mat[1] = self.mat[0].clone();
                        self.mat[3] = self.mat[2].clone();
                    }
                }
                // egest terms
                let n0 = self.mat[0].clone();
                let n1 = self.mat[0].clone() + self.mat[1].clone();
                let d0 = self.mat[2].clone();
                let d1 = self.mat[2].clone() + self.mat[3].clone();
                if (self.mat[0] < 0.into()) != (self.mat[2] < 0.into()) {
                    self.mat[0] = -self.mat[0].clone();
                    self.mat[1] = -self.mat[1].clone();
                    return Some(Term::Neg);
                } else if (n0.clone() >> 1) >= d0 && (n1.clone() >> 1) >= d1 {
                    if !self.mat[0].bit(0) && !self.mat[1].bit(0) {
                        self.mat[0] >>= 1;
                        self.mat[1] >>= 1;
                    } else {
                        self.mat[2] <<= 1;
                        self.mat[3] <<= 1;
                    }
                    return Some(Term::Ord);
                } else if n0 >= d0 && n1 >= d1 && (n0.clone() >> 1) < d0 && (n1.clone() >> 1) < d1 {
                    self.mat[0] -= self.mat[2].clone();
                    self.mat[1] -= self.mat[3].clone();
                    self.mat.swap(0, 2);
                    self.mat.swap(1, 3);
                    return Some(Term::DRec);
                } else if n0 < d0 && n1 < d1 {
                    self.mat.swap(0, 2);
                    self.mat.swap(1, 3);
                    return Some(Term::Rec);
                }
            }
        }
    }
    impl<X: Iterator<Item = i64>> Stream for CFrac<X> {}
    CFrac { x, mat }
}
