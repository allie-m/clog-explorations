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
    while stdin.read_line(&mut buf).unwrap() > 0 {
        // write!(stdout, "{}", buf).unwrap();
        let dag = match parse::roll_stack_expression(&buf) {
            Ok(dag) => dag,
            Err(e) => {
                eprintln!("Invalid stack expression; {:?}", e);
                continue;
            }
        };
        println!("{:?}", dag);
        let mut clog_dag = match parse::node_to_clog_stream(dag) {
            Ok(clog_dag) => clog_dag,
            Err(e) => {
                eprintln!("Can't convert to a continued logarithm dag; {:?}", e);
                continue;
            }
        };
        for _ in 0..20 {
            println!("{:?}", clog_dag.next());
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
