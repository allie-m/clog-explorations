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
                if i > 100 {
                    panic!()
                }
                // println!("hii {:?}", self.mat);
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

                let n0 = self.mat[0].clone();
                let n1 = self.mat[0].clone() + self.mat[1].clone();
                let n2 = self.mat[0].clone() + self.mat[2].clone();
                let n3 = self.mat[0].clone()
                    + self.mat[1].clone()
                    + self.mat[2].clone()
                    + self.mat[3].clone();
                let d0 = self.mat[4].clone();
                let d1 = self.mat[4].clone() + self.mat[5].clone();
                let d2 = self.mat[4].clone() + self.mat[6].clone();
                let d3 = self.mat[4].clone()
                    + self.mat[5].clone()
                    + self.mat[6].clone()
                    + self.mat[7].clone();

                let num_agreed = (n0 < 0.into()) == (n1 < 0.into())
                    && (n1 < 0.into()) == (n2 < 0.into())
                    && (n2 < 0.into()) == (n3 < 0.into());
                let den_agreed = (d0 < 0.into()) == (d1 < 0.into())
                    && (d1 < 0.into()) == (d2 < 0.into())
                    && (d2 < 0.into()) == (d3 < 0.into());
                let den_zeros =
                    d0 == 0.into() || d1 == 0.into() || d2 == 0.into() || d3 == 0.into();
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
                    && n0.clone().into_parts().1 < d0.clone().into_parts().1
                    && n1.clone().into_parts().1 < d1.clone().into_parts().1
                    && n2.clone().into_parts().1 < d2.clone().into_parts().1
                    && n3.clone().into_parts().1 < d3.clone().into_parts().1
                {
                    self.mat.swap(0, 4);
                    self.mat.swap(1, 5);
                    self.mat.swap(2, 6);
                    self.mat.swap(3, 7);
                    self.singularity = true;
                    return Some(Term::RecSpec);
                }
                if self.singularity {
                    let a1: BigInt = d0.clone() << 1;
                    let a2: BigInt = d1.clone() << 1;
                    let a3: BigInt = d2.clone() << 1;
                    let a4: BigInt = d3.clone() << 1;
                    if a1.into_parts().1 < n0.clone().into_parts().1
                        && a2.into_parts().1 < n1.clone().into_parts().1
                        && a3.into_parts().1 < n2.clone().into_parts().1
                        && a4.into_parts().1 < n3.clone().into_parts().1
                    {
                        if !n0.bit(0) && !n1.bit(0) && !n2.bit(0) && !n3.bit(0) {
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
                    } else if (n0.clone() >> 1) >= d0
                        && (n1.clone() >> 1) >= d1
                        && (n2.clone() >> 1) >= d2
                        && (n3.clone() >> 1) >= d3
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
                    } else if n0 >= d0
                        && n1 >= d1
                        && n2 >= d2
                        && n3 >= d3
                        && (n0.clone() >> 1) < d0
                        && (n1.clone() >> 1) < d1
                        && (n2.clone() >> 1) < d2
                        && (n3.clone() >> 1) < d3
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
                    } else if n0 < d0 && n1 < d1 && n2 < d2 && n3 < d3 {
                        self.mat.swap(0, 4);
                        self.mat.swap(1, 5);
                        self.mat.swap(2, 6);
                        self.mat.swap(3, 7);
                        return Some(Term::Rec);
                    }
                    // the following are SPECULATIVE
                    else if self.speculative
                        && d0 < n0
                        && n0 < (d0.clone() << 2)
                        && d1 < n1
                        && n1 < (d1.clone() << 2)
                        && d2 < n2
                        && n2 < (d2.clone() << 2)
                        && d3 < n3
                        && n3 < (d3.clone() << 2)
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
                        && d0 < (n0.clone() << 1)
                        && n0 < d0.clone() << 1
                        && d1 < (n1.clone() << 1)
                        && n1 < d1.clone() << 1
                        && d2 < (n2.clone() << 1)
                        && n2 < d2.clone() << 1
                        && d3 < (n3.clone() << 1)
                        && n3 < d3.clone() << 1
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
