Continued Logarithm-Based Calculator
=

Inspired by a [lobsters post](https://lobste.rs/s/xjrlj2/how_android_s_calculator_works_with_real), this is a CLI calculator implemented with a speculatively redundant continued logarithm scheme, as described in [Brabec 2010](https://ieeexplore.ieee.org/document/5467052).

See the global README or the writeup for more details. Very much incomplete (only basic arithmetic is supported at the moment... but it has the capacity to do true arbitrary precision real arithmetic!)

To run

```
cargo run
```

Since it's a stack calculator, expressions like `5 0.152 * 10 +` will be evaluated as (5 * 0.152) + 10.
