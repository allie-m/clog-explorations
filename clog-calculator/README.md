Continued Logarithm-Based Calculator
=

Inspired by a [lobsters post](https://lobste.rs/s/xjrlj2/how_android_s_calculator_works_with_real), this is a CLI calculator implemented with a speculatively redundant continued logarithm scheme, as described in [Brabec 2010](https://ieeexplore.ieee.org/document/5467052).

An easier way to do real arithmetic than RRA or computer algebra.

I would leverage [this](https://mathr.co.uk/web/continued-logarithm.html) beautiful, featureful, yet concise Haskell implementation of continued logarithms were it to support speculatively redundant continued logarithms; however, our calculator needs to be able to evaluate sqrt(2) * sqrt(2) correctly! So, we have to roll our own.
