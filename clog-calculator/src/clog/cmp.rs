// use std::cmp::Ordering;

// use num_bigint::Sign;

// use crate::clog::{blfts, terms_to_rational, Stream};

// // consumes x and y
// // is x greater than, less than, or equal to y?
// pub fn compare<X, Y>(x: X, y: Y, count: u32) -> Ordering
// where
//     X: Stream,
//     Y: Stream,
// {
//     match terms_to_rational(
//         blfts(
//             x,
//             y,
//             [
//                 0.into(),
//                 1.into(),
//                 (-1).into(),
//                 0.into(),
//                 0.into(),
//                 0.into(),
//                 0.into(),
//                 1.into(),
//             ],
//             true,
//         ),
//         count,
//     )
//     .0
//     .sign()
//     {
//         Sign::Plus => Ordering::Greater,
//         Sign::Minus => Ordering::Less,
//         Sign::NoSign => Ordering::Equal,
//     }
// }
