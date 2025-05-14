mod clog;
mod parse;

fn main() {
    // hmm this might be cool as a C program
    // to make a calculator for my operating system...
    // another time perhaps
    let stdin = std::io::stdin();
    let mut buf = String::new();
    // we're just not gonna deal with io errors
    // they'll get sent to stderr, whatever
    enum OutFormat {
        Rational,
        Decimal,
        Interval,
        ClogTerms,
    }
    struct Cfg {
        speculative: bool,
        max_terms: u32,
        out_format: OutFormat,
    }
    let mut cfg = Cfg {
        speculative: true,
        max_terms: 200,
        out_format: OutFormat::Rational,
    };
    while stdin.read_line(&mut buf).unwrap() > 0 {
        if buf.starts_with("cfg ") {
            let mut iter = buf.split(" ");
            let _ = iter.next().unwrap();
            match iter.next().map(|s| s.trim()) {
                Some(item) => match item {
                    "speculative" => cfg.speculative = true,
                    "exact" => cfg.speculative = false,
                    "max_terms" => {
                        if let Some(Ok(item)) = iter.next().map(|i| i.parse()) {
                            cfg.max_terms = item
                        }
                    }
                    // TODO more
                    _ => {}
                },
                None => {}
            }
            buf.clear();
            continue;
        }
        let dag = match parse::roll_stack_expression(&buf) {
            Ok(dag) => dag,
            Err(e) => {
                eprintln!("Invalid stack expression; {:?}", e);
                buf.clear();
                continue;
            }
        };
        println!("{:?}", dag);
        let clog_dag = match parse::node_to_clog_stream(dag, cfg.speculative) {
            Ok(clog_dag) => clog_dag,
            Err(e) => {
                eprintln!("Can't convert to a continued logarithm dag; {:?}", e);
                buf.clear();
                continue;
            }
        };
        match cfg.out_format {
            OutFormat::Decimal => todo!(),
            OutFormat::Rational => {
                // println!("{:?}", clog_dag.collect::<Vec<_>>());
                println!("{:?}", clog::terms_to_rational(clog_dag, cfg.max_terms));
            }
            OutFormat::Interval => todo!(),
            OutFormat::ClogTerms => todo!(),
        }
        buf.clear();
    }
}

// AD-HOC TEST CODE FOR THE CLOG ARITHMETIC STUFF:
// let rat = clog::rational(2147483632u32.into(), 1u32.into(), -1);
// println!("hi {:?}", rat.clone().collect::<Vec<_>>());
// let mut iter = clog::lft(rat.clone(), [1.into(), 0.into(), 0.into(), 1.into()]);
// for _ in 0..10 {
//     println!("{:?}", iter.next())
// }
// println!(
//     "ha {:?}",
//     clog::lft(rat.clone(), [1.into(), 0.into(), 0.into(), 1.into()],).collect::<Vec<_>>()
// );
// sqrt(2) * sqrt(2) = 2
// sqrt(2) is 01(011)
// #[derive(Clone)]
// struct Sqrt2 {
//     i: u32
// }
// impl Iterator for Sqrt2 {
//     type Item = clog::Term;
//     fn next(&mut self) -> Option<clog::Term> {
//         if self.i == 10 {
//             self.i = 9;
//             Some(clog::Term::DRec)
//         } else if self.i == 9 {
//             self.i = 0;
//             Some(clog::Term::Ord)
//         } else {
//             let t = match self.i {
//                 0 => clog::Term::DRec,
//                 1 | 2 => clog::Term::Ord,
//                 _ => panic!()
//             };
//             self.i += 1;
//             self.i %= 3;
//             Some(t)
//         }
//     }
// }
// impl clog::Stream for Sqrt2 {}
// let s1 = Sqrt2 { i: 10 };
// let s2 = Sqrt2 { i: 10 };

// let mut iter = clog::blft(s1, s2, [
//     1.into(),
//     0.into(),
//     0.into(),
//     0.into(),
//     0.into(),
//     0.into(),
//     0.into(),
//     1.into(),
// ]);
// for _ in 0..10 {
//     println!("{:?}", iter.next());
// }

// // 10/3 * 15/1 = 50
// let c1 = clog::rational(10u32.into(), 3u32.into(), 1);
// let c2 = clog::rational(15u32.into(), 1u32.into(), 1);
// let iter = clog::blft(
//     c1,
//     c2,
//     [
//         1.into(),
//         0.into(),
//         0.into(),
//         0.into(),
//         0.into(),
//         0.into(),
//         0.into(),
//         1.into(),
//     ],
// );
// println!("{:?}", iter.clone().collect::<Vec<_>>());
// // for _ in 0..20 {
// //     println!("{:?}", iter.next())
// // }
