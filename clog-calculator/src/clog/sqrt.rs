use super::*;

pub fn sqrt<X>(x: X, _speculative: bool) -> impl Stream
where
    X: Stream,
{
    #[derive(Clone)]
    struct Sqrt<X: Stream> {
        x: X,
        mat: [BigInt; 8],
    }
    impl<X: Stream> Iterator for Sqrt<X> {
        type Item = Term;
        fn next(&mut self) -> Option<Term> {
            let mut i = 0;
            loop {
                i += 1;
                if i > 100 {
                    panic!()
                }
                // ingest from x
                // same exact logic as in the arith algorithm
                let term = self.x.next();
                // println!("{:?} | {:?}", term, self.mat);
                match term {
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

                // if there's no y in the denominator,
                // then we've hit oo
                if self.mat[4] == 0.into() && self.mat[6] == 0.into() {
                    return None;
                }

                // whyyy does this seemingly very rational algorithm not work
                // and the nonsense one DOES (mostly)
                // i don't get it ;-;

                let n_y2xoo: BigInt = 2 * self.mat[0].clone() + self.mat[1].clone();
                let d_y2xoo: BigInt = 2 * self.mat[4].clone() + self.mat[5].clone();
                // (false for positive, true for negative)
                let s_y2xoo = (n_y2xoo < 0.into()) ^ (d_y2xoo < 0.into());
                let n_y2x1: BigInt = 2 * self.mat[0].clone()
                    + self.mat[1].clone()
                    + 2 * self.mat[2].clone()
                    + self.mat[3].clone();
                let d_y2x1: BigInt = 2 * self.mat[4].clone()
                    + self.mat[5].clone()
                    + 2 * self.mat[6].clone()
                    + self.mat[7].clone();
                let s_y2x1 = (n_y2x1 < 0.into()) ^ (d_y2x1 < 0.into());
                let n_y1xoo = self.mat[0].clone() + self.mat[1].clone();
                let d_y1xoo = self.mat[4].clone() + self.mat[5].clone();
                let s_y1xoo = (n_y1xoo < 0.into()) ^ (d_y1xoo < 0.into());
                let n_y1x1 = self.mat[0].clone()
                    + self.mat[1].clone()
                    + self.mat[2].clone()
                    + self.mat[3].clone();
                let d_y1x1 = self.mat[4].clone()
                    + self.mat[5].clone()
                    + self.mat[6].clone()
                    + self.mat[7].clone();
                let s_y1x1 = (n_y1x1 < 0.into()) ^ (d_y1x1 < 0.into());

                let n_y2xoo = n_y2xoo.into_parts().1;
                let d_y2xoo = d_y2xoo.into_parts().1;
                let n_y2x1 = n_y2x1.into_parts().1;
                let d_y2x1 = d_y2x1.into_parts().1;
                let n_y1xoo = n_y1xoo.into_parts().1;
                let d_y1xoo = d_y1xoo.into_parts().1;
                let n_y1x1 = n_y1x1.into_parts().1;
                let d_y1x1 = d_y1x1.into_parts().1;

                println!("{:?}", self.mat);
                println!(
                    "at y=2 | x=oo {}{:?}/{:?}, x=1 {}{:?}/{:?}",
                    if s_y2xoo { "-" } else { "" },
                    n_y2xoo,
                    d_y2xoo,
                    if s_y2x1 { "-" } else { "" },
                    n_y2x1,
                    d_y2x1
                );
                println!(
                    "at y=1 | x=oo {}{:?}/{:?}, x=1 {}{:?}/{:?}",
                    if s_y1xoo { "-" } else { "" },
                    n_y1xoo,
                    d_y1xoo,
                    if s_y1x1 { "-" } else { "" },
                    n_y1x1,
                    d_y1x1
                );

                // when y=2 and we're < 0
                if s_y2xoo && s_y2x1 && s_y1xoo && s_y1x1 {
                    // egest
                    // self.mat[0] = -self.mat[0].clone();
                    self.mat[1] = -self.mat[1].clone();
                    // self.mat[2] = -self.mat[2].clone();
                    self.mat[3] = -self.mat[3].clone();
                    // ingest
                    // self.mat[0] = -self.mat[0].clone();
                    // self.mat[2] = -self.mat[2].clone();
                    self.mat[4] = -self.mat[4].clone();
                    self.mat[6] = -self.mat[6].clone();
                    return Some(Term::Neg);
                }

                // when y=2 and we're >= 2
                if !s_y2xoo
                    && !s_y2x1
                    && n_y2xoo.clone() >= d_y2xoo.clone() * 2u32
                    && n_y2x1.clone() >= d_y2x1.clone() * 2u32
                {
                    // egest
                    if self.mat[0].clone() % 2 == 0.into()
                        && self.mat[1].clone() % 2 == 0.into()
                        && self.mat[2].clone() % 2 == 0.into()
                        && self.mat[3].clone() % 2 == 0.into()
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
                    // ingest
                    if self.mat[1].clone() % 2 == 0.into()
                        && self.mat[3].clone() % 2 == 0.into()
                        && self.mat[5].clone() % 2 == 0.into()
                        && self.mat[7].clone() % 2 == 0.into()
                    {
                        self.mat[1] >>= 1;
                        self.mat[3] >>= 1;
                        self.mat[5] >>= 1;
                        self.mat[7] >>= 1;
                    } else {
                        self.mat[0] <<= 1;
                        self.mat[2] <<= 1;
                        self.mat[4] <<= 1;
                        self.mat[6] <<= 1;
                    }
                    // println!("egest ord");
                    return Some(Term::Ord);
                }
                // when y=2 and we're < 2 and
                //      either y=1 puts us >= 1 (don't wanna jump the gun on a /)
                //      or y=1 puts us < 0 (an intervening asymptote! go with the positive root!)
                if !s_y2xoo
                    && !s_y2x1
                    && n_y2xoo.clone() < d_y2xoo.clone() * 2u32
                    && n_y2x1.clone() < d_y2x1.clone() * 2u32
                    && ((!s_y1xoo
                        && !s_y1x1
                        && n_y1xoo.clone() >= d_y1xoo
                        && n_y1x1.clone() >= d_y1x1.clone())
                        || (s_y1xoo && s_y1x1))
                {
                    // egest
                    self.mat[0] -= self.mat[4].clone();
                    self.mat[1] -= self.mat[5].clone();
                    self.mat[2] -= self.mat[6].clone();
                    self.mat[3] -= self.mat[7].clone();
                    self.mat.swap(0, 4);
                    self.mat.swap(1, 5);
                    self.mat.swap(2, 6);
                    self.mat.swap(3, 7);
                    // ingest
                    self.mat.swap(0, 1);
                    self.mat.swap(2, 3);
                    self.mat.swap(4, 5);
                    self.mat.swap(6, 7);
                    self.mat[0] += self.mat[1].clone();
                    self.mat[2] += self.mat[3].clone();
                    self.mat[4] += self.mat[5].clone();
                    self.mat[6] += self.mat[7].clone();
                    // println!("egest drec");
                    return Some(Term::DRec);
                }
                // when y=1 and we're between 0 and 1
                if !s_y1xoo
                    && !s_y1x1
                    && n_y1xoo.clone() < d_y1xoo.clone()
                    && n_y1x1.clone() < d_y1x1.clone()
                {
                    // egest
                    self.mat.swap(0, 4);
                    self.mat.swap(1, 5);
                    self.mat.swap(2, 6);
                    self.mat.swap(3, 7);
                    // ingest
                    self.mat.swap(0, 1);
                    self.mat.swap(2, 3);
                    self.mat.swap(4, 5);
                    self.mat.swap(6, 7);
                    // println!("egest rec");
                    return Some(Term::Rec);
                }

                // TODO: WHY DOES THIS EVEN WORK??????
                // this feels like it shouldn't work

                // if self.mat.iter().all(|a| *a <= 0.into()) {
                //     println!("FLIPPING EVERYTHING!!!!");
                //     self.mat[0] = -self.mat[0].clone();
                //     self.mat[1] = -self.mat[1].clone();
                //     self.mat[2] = -self.mat[2].clone();
                //     self.mat[3] = -self.mat[3].clone();
                //     self.mat[4] = -self.mat[4].clone();
                //     self.mat[5] = -self.mat[5].clone();
                //     self.mat[6] = -self.mat[6].clone();
                //     self.mat[7] = -self.mat[7].clone();
                // }
                // if self.mat[..4].iter().all(|a| *a <= 0.into()) {
                //     // egest -
                //     self.mat[0] = -self.mat[0].clone();
                //     self.mat[1] = -self.mat[1].clone();
                //     self.mat[2] = -self.mat[2].clone();
                //     self.mat[3] = -self.mat[3].clone();
                //     // ingest -
                //     self.mat[0] = -self.mat[0].clone();
                //     self.mat[2] = -self.mat[2].clone();
                //     self.mat[4] = -self.mat[4].clone();
                //     self.mat[6] = -self.mat[6].clone();
                //     println!("EGEST AND INGEST NEG");
                //     return Some(Term::Neg);
                // }
                // // plug in y=2 for x=oo and x=1; if they agree
                // // egest and ingest that term from/into y
                // // otherwise we try y=1 to discern between 0 and /
                // if 2 * self.mat[0].clone() + self.mat[1].clone()
                //     >= 2 * (2 * self.mat[4].clone() + self.mat[5].clone())
                //     && 2 * self.mat[0].clone()
                //         + self.mat[1].clone()
                //         + 2 * self.mat[2].clone()
                //         + self.mat[3].clone()
                //         >= 2 * (2 * self.mat[4].clone()
                //             + self.mat[5].clone()
                //             + 2 * self.mat[6].clone()
                //             + self.mat[7].clone())
                // {
                //     // egest from y
                //     if self.mat[0].clone() % 2 == 0.into()
                //         && self.mat[1].clone() % 2 == 0.into()
                //         && self.mat[2].clone() % 2 == 0.into()
                //         && self.mat[3].clone() % 2 == 0.into()
                //     {
                //         self.mat[0] >>= 1;
                //         self.mat[1] >>= 1;
                //         self.mat[2] >>= 1;
                //         self.mat[3] >>= 1;
                //     } else {
                //         self.mat[4] <<= 1;
                //         self.mat[5] <<= 1;
                //         self.mat[6] <<= 1;
                //         self.mat[7] <<= 1;
                //     }
                //     // ingest into y
                //     if self.mat[1].clone() % 2 == 0.into()
                //         && self.mat[3].clone() % 2 == 0.into()
                //         && self.mat[5].clone() % 2 == 0.into()
                //         && self.mat[7].clone() % 2 == 0.into()
                //     {
                //         self.mat[1] >>= 1;
                //         self.mat[3] >>= 1;
                //         self.mat[5] >>= 1;
                //         self.mat[7] >>= 1;
                //     } else {
                //         self.mat[0] <<= 1;
                //         self.mat[2] <<= 1;
                //         self.mat[4] <<= 1;
                //         self.mat[6] <<= 1;
                //     }
                //     // println!("egest ord");
                //     return Some(Term::Ord);
                // } else if 2 * self.mat[0].clone() + self.mat[1].clone()
                //     < 2 * (2 * self.mat[4].clone() + self.mat[5].clone())
                //     && 2 * self.mat[0].clone()
                //         + self.mat[1].clone()
                //         + 2 * self.mat[2].clone()
                //         + self.mat[3].clone()
                //         < 2 * (2 * self.mat[4].clone()
                //             + self.mat[5].clone()
                //             + 2 * self.mat[6].clone()
                //             + self.mat[7].clone())
                //     && self.mat[0].clone() + self.mat[1].clone()
                //         >= self.mat[4].clone() + self.mat[5].clone()
                //     && self.mat[0].clone()
                //         + self.mat[1].clone()
                //         + self.mat[2].clone()
                //         + self.mat[3].clone()
                //         >= self.mat[4].clone()
                //             + self.mat[5].clone()
                //             + self.mat[6].clone()
                //             + self.mat[7].clone()
                // {
                //     // otherwise, we egest and ingest 0 from/into y
                //     // TODO WHAT HAPPENS WHEN THIS ISN'T THE MOVE
                //     self.mat[0] -= self.mat[4].clone();
                //     self.mat[1] -= self.mat[5].clone();
                //     self.mat[2] -= self.mat[6].clone();
                //     self.mat[3] -= self.mat[7].clone();
                //     self.mat.swap(0, 4);
                //     self.mat.swap(1, 5);
                //     self.mat.swap(2, 6);
                //     self.mat.swap(3, 7);
                //     // ingest
                //     self.mat.swap(0, 1);
                //     self.mat.swap(2, 3);
                //     self.mat.swap(4, 5);
                //     self.mat.swap(6, 7);
                //     self.mat[0] += self.mat[1].clone();
                //     self.mat[2] += self.mat[3].clone();
                //     self.mat[4] += self.mat[5].clone();
                //     self.mat[6] += self.mat[7].clone();
                //     // println!("egest drec");
                //     return Some(Term::DRec);
                // } else if self.mat[0].clone() + self.mat[1].clone()
                //     < self.mat[4].clone() + self.mat[5].clone()
                //     && self.mat[0].clone()
                //         + self.mat[1].clone()
                //         + self.mat[2].clone()
                //         + self.mat[3].clone()
                //         < self.mat[4].clone()
                //             + self.mat[5].clone()
                //             + self.mat[6].clone()
                //             + self.mat[7].clone()
                // {
                //     // egest
                //     self.mat.swap(0, 4);
                //     self.mat.swap(1, 5);
                //     self.mat.swap(2, 6);
                //     self.mat.swap(3, 7);
                //     // ingest
                //     self.mat.swap(0, 1);
                //     self.mat.swap(2, 3);
                //     self.mat.swap(4, 5);
                //     self.mat.swap(6, 7);
                //     // println!("egest rec");
                //     return Some(Term::Rec);
                // }
            }
        }
    }
    impl<X: Stream> Stream for Sqrt<X> {}
    Sqrt {
        x,
        mat: [
            0.into(),
            1.into(),
            0.into(),
            0.into(),
            0.into(),
            0.into(),
            1.into(),
            0.into(),
        ],
    }
}
