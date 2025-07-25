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
                // same exact logic as in
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

                if self.mat.iter().all(|a| *a <= 0.into()) {
                    self.mat[0] = -self.mat[0].clone();
                    self.mat[1] = -self.mat[1].clone();
                    self.mat[2] = -self.mat[2].clone();
                    self.mat[3] = -self.mat[3].clone();
                    self.mat[4] = -self.mat[4].clone();
                    self.mat[5] = -self.mat[5].clone();
                    self.mat[6] = -self.mat[6].clone();
                    self.mat[7] = -self.mat[7].clone();
                }

                // TODO RAISE ERROR INSTEAD OF FLIPPING SIGN
                if self.mat[..4].iter().all(|a| *a <= 0.into()) {
                    self.mat[0] = -self.mat[0].clone();
                    self.mat[1] = -self.mat[1].clone();
                    self.mat[2] = -self.mat[2].clone();
                    self.mat[3] = -self.mat[3].clone();
                }
                if self.mat[4..].iter().all(|a| *a <= 0.into()) {
                    self.mat[4] = -self.mat[4].clone();
                    self.mat[5] = -self.mat[5].clone();
                    self.mat[6] = -self.mat[6].clone();
                    self.mat[7] = -self.mat[7].clone();
                }

                println!("{:?}", self.mat);
                println!(
                    "at y=2 | x=oo {:?}/{:?}, x=0 {:?}/{:?}",
                    2 * self.mat[0].clone() + self.mat[1].clone(),
                    2 * self.mat[4].clone() + self.mat[5].clone(),
                    2 * self.mat[0].clone()
                        + self.mat[1].clone()
                        + 2 * self.mat[2].clone()
                        + self.mat[3].clone(),
                    2 * self.mat[4].clone()
                        + self.mat[5].clone()
                        + 2 * self.mat[6].clone()
                        + self.mat[7].clone()
                );
                println!(
                    "at y=1 | x=oo {:?}/{:?}, x=0 {:?}/{:?}",
                    self.mat[0].clone() + self.mat[1].clone(),
                    self.mat[4].clone() + self.mat[5].clone(),
                    self.mat[0].clone()
                        + self.mat[1].clone()
                        + self.mat[2].clone()
                        + self.mat[3].clone(),
                    self.mat[4].clone()
                        + self.mat[5].clone()
                        + self.mat[6].clone()
                        + self.mat[7].clone()
                );

                // TODO IMPLEMENT SPECULATION FOR Y

                // plug in y=2 for x=oo and x=1; if they agree
                // egest and ingest that term from/into y
                // otherwise we try y=1 to discern between 0 and /
                if 2 * self.mat[0].clone() + self.mat[1].clone()
                    >= 2 * (2 * self.mat[4].clone() + self.mat[5].clone())
                    && 2 * self.mat[0].clone()
                        + self.mat[1].clone()
                        + 2 * self.mat[2].clone()
                        + self.mat[3].clone()
                        >= 2 * (2 * self.mat[4].clone()
                            + self.mat[5].clone()
                            + 2 * self.mat[6].clone()
                            + self.mat[7].clone())
                {
                    // egest from y
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
                    // ingest into y
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
                    // println!("egest ord");
                    return Some(Term::Ord);
                } else if 2 * self.mat[0].clone() + self.mat[1].clone()
                    < 2 * (2 * self.mat[4].clone() + self.mat[5].clone())
                    && 2 * self.mat[0].clone()
                        + self.mat[1].clone()
                        + 2 * self.mat[2].clone()
                        + self.mat[3].clone()
                        < 2 * (2 * self.mat[4].clone()
                            + self.mat[5].clone()
                            + 2 * self.mat[6].clone()
                            + self.mat[7].clone())
                    && self.mat[0].clone() + self.mat[1].clone()
                        >= self.mat[4].clone() + self.mat[5].clone()
                    && self.mat[0].clone()
                        + self.mat[1].clone()
                        + self.mat[2].clone()
                        + self.mat[3].clone()
                        >= self.mat[4].clone()
                            + self.mat[5].clone()
                            + self.mat[6].clone()
                            + self.mat[7].clone()
                {
                    // otherwise, we egest and ingest 0 from/into y
                    // TODO WHAT HAPPENS WHEN THIS ISN'T THE MOVE
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
                } else if self.mat[0].clone() + self.mat[1].clone()
                    < self.mat[4].clone() + self.mat[5].clone()
                    && self.mat[0].clone()
                        + self.mat[1].clone()
                        + self.mat[2].clone()
                        + self.mat[3].clone()
                        < self.mat[4].clone()
                            + self.mat[5].clone()
                            + self.mat[6].clone()
                            + self.mat[7].clone()
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
