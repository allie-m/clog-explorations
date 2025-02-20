Continued Logarithms Are a Flawed (But Very Interesting) Representation
=

For the uninitiated, continued logarithms are a variant of continued fraction first conceived in a 1978 manuscript written by Bill Gosper.

They enable a far more computationally efficient arithmetic algorithm than is otherwise possible for continued fractions, while preserving many of their nice properties, making them suitable (at least in theory) for high precision exact arithmetic.

The original paper, dense as it is, can probably motivate and explain them better than I can here. It's a delightful read, would recommend :D

To briefly recap, here's what a basic continued logarithm is: a binary string, where a 1 conveys "I was > 2, so halve me", and a 0 conveys "I was between 1 and 2, so subtract 1 and reciprocate me" (and maybe we have a 2 bit preamble for the case that you're less than 1).

Here's the process for finding the continued logarithm of 30/7.

```
30/7      | 1
30/14     | 1
30/28     | 0
28/2 = 14 | 1
7         | 1
7/2       | 1
7/4       | 0
4/3       | 0
3/1       | 1
3/2       | 0
2/1       | 1
1/1       | 0
1/0       | oo

30/7 = 110111001010
```

Continued logarithms never did catch on; there's very little literature about them, and they are very obscure compared to other methods for high precision arithmetic (arbitrary precision floats, bignum rationals, interval arithmetic).

I got to wondering why, and I've come to the conclusion that it's at least partially due to the fact they use too many bits to represent the numbers people actually want to represent.

But first, their advantages, of which they on their face have many.

Algorithms written for continued logarithms ingest and egest the representation left to right, always dealing with the most significant bits first. You can interrupt a process and get an accurate but truncated output. Operations like arithmetic or sqrt or log can be treated like composable lazy iterators, feeding terms into each other on-demand.

Arithmetic uses only bitshifts, swaps, compares, and two's complement addition/subtraction, on the order of one add/sub per output bit, where the order of magnitude of the integers involved scales linearly with the number of terms already inputted. Not especially efficient, but (especially with dedicated hardware) it might compare favorably with rational arithmetic, or other methods that require big integer division.

Also, since this algorithm evaluates expressions of the form `(axy + bx + cy + d)/(exy + fx + gy + h)`, division is no more expensive than addition, and what might otherwise be multiple distinct arithmetic operations can be bundled together.

There exist algorithms for sqrt, log/exp [TODO inline/footnote citations for these], and all the trig stuff you could possibly want that are approximately as taxing as arithmetic.

Continued logarithms, like continued fractions, are capable of representing all exact rationals with a number of bits scaling with the complexity of the number. No `0.1 + 0.2 = 0.30000000000000004`. That's all well and good, but what does "scaling with the complexity of the number" mean, exactly?

In the case of continued fractions, it's very clear: the Stern-Brocot tree enumerates all rationals nonredundantly, and simple continued fractions can be thought of as a run-length encoding of a path down the tree. This is very mathematically pleasing, and the more complex a rational is (the larger its denominator is) the further down the tree it is (and hence the more bits it requires).

However, as Gosper points out in his original paper [TODO inline citation], this correspondence renders continued fractions a very inefficient representation. Each term is an integer, but it's not obvious how big an integer to allocate for each term; they do not span orders of magnitude well, as representing 2^128 would require leading with a 128 bit integer. Decomposing continued fractions into binary strings makes this problem worse; 2^128 would require 2^128 leading 1s. This issue also applies to negative orders of magnitude; 2^-128 is 0 2^-128 leading 0s, or [0; 2^128]. The representation is heavily biased to numbers near 1/1. [TODO]

Continued logarithms, Gosper posits [TODO inline citation], might have a better spread: each 1 term represents a binary order of magnitude, so that 2^128 requires only 128 bits; by the same token, 2^-128 requires just 129.
