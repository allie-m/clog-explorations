Continued Logarithm Arithmetic in Pyrtl
=

Tomas Brabec implemented nonspeculative non-redundant continued logarithms on an FPGA in 2006. He also devised speculatively redundant continued logarithms in 2010. But he never implemented them on hardware. Hence, this project :)

This project aims to implement the `blfts` and `nlfts` in pyrtl (FPGAs are hard and I've never worked with them).

As my W25 1L blogpost illustrated, I don't think there's a place for nonredundant continued logarithms. And the only use that seems viable for redundant scheme is in pure software as an "easy" way to do real arithmetic. But writing up the algorithms in a basic HDL seems like a fun idea.

Who knows, the results of this experiment might imply that a hardware solution for continued logarithms makes theoretical sense.
