use super::*;

pub fn blfts<X, Y>(x: X, y: Y, mat: [BigInt; 8], speculative: bool) -> impl Stream
where
    X: Stream,
    Y: Stream,
{
    #[derive(Clone)]
    struct Blfts<X: Stream, Y: Stream> {
        x: X,
        y: Y,
        mat: [BigInt; 8],
        singularity: bool,
        speculative: bool,
    }
    impl<X: Stream, Y: Stream> Iterator for Blfts<X, Y> {
        type Item = Term;
        fn next(&mut self) -> Option<Term> {
            let mut i = 0;
            loop {
                i += 1;
                if i > 100 { panic!() }
                println!("hii {:?}", self.mat);
                // println!("{:?}", self.mat.iter().map(|i| i.bits()).max().unwrap());
                if self.mat[4] == 0.into()
                    && self.mat[5] == 0.into()
                    && self.mat[6] == 0.into()
                    && self.mat[7] == 0.into()
                {
                    return None;
                }
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

                let num_agreed = (self.mat[0] < 0.into()) == (self.mat[1] < 0.into())
                    && (self.mat[1] < 0.into()) == (self.mat[2] < 0.into())
                    && (self.mat[2] < 0.into()) == (self.mat[3] < 0.into());
                let den_agreed = (self.mat[4] < 0.into()) == (self.mat[5] < 0.into())
                    && (self.mat[5] < 0.into()) == (self.mat[6] < 0.into())
                    && (self.mat[6] < 0.into()) == (self.mat[7] < 0.into());
                let den_zeros = self.mat[4] == 0.into()
                    || self.mat[5] == 0.into()
                    || self.mat[6] == 0.into()
                    || self.mat[7] == 0.into();
                let well_defined = num_agreed && den_agreed && !den_zeros;
                // if well defined and num/den are negative, flip all negatives to positives
                if well_defined && self.mat[0] < 0.into() && self.mat[4] < 0.into() {
                    self.mat[0] = -self.mat[0].clone();
                    self.mat[1] = -self.mat[1].clone();
                    self.mat[2] = -self.mat[2].clone();
                    self.mat[3] = -self.mat[3].clone();
                    self.mat[4] = -self.mat[4].clone();
                    self.mat[5] = -self.mat[5].clone();
                    self.mat[6] = -self.mat[6].clone();
                    self.mat[7] = -self.mat[7].clone();
                }

                // speculative stuff for which we don't need well definedness
                if self.speculative && !self.singularity
                    // 0s ARE allowed in the denominator; we send to [-inf, -1) U (1, inf]
                    && self.mat[0].clone().into_parts().1 < self.mat[4].clone().into_parts().1
                    && self.mat[1].clone().into_parts().1 < self.mat[5].clone().into_parts().1
                    && self.mat[2].clone().into_parts().1 < self.mat[6].clone().into_parts().1
                    && self.mat[3].clone().into_parts().1 < self.mat[7].clone().into_parts().1
                {
                    self.mat.swap(0, 4);
                    self.mat.swap(1, 5);
                    self.mat.swap(2, 6);
                    self.mat.swap(3, 7);
                    self.singularity = true;
                    return Some(Term::RecSpec);
                }
                if self.singularity {
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
                    }
                } else {
                    self.singularity = false;
                }

                if well_defined {
                    self.singularity = false;
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
                    else if self.speculative
                        && self.mat[4] < self.mat[0]
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
                    } else if self.speculative
                        && self.mat[4] < (self.mat[0].clone() << 1)
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
                    }
                }
            }
        }
    }
    impl<X: Stream, Y: Stream> Stream for Blfts<X, Y> {}
    Blfts {
        x,
        y,
        mat,
        singularity: false,
        speculative,
    }
}
