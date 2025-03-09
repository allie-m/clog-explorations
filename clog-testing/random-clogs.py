from utils import *

from matplotlib import pyplot as plt

from math import log2

import random

# weight = % of 0s
def random_clog(length, leading_ones, weight):
    clog = [1] * leading_ones
    while len(clog) < length:
        clog.append(random.random() < weight)
    if clog[-1] != 0:
        clog[-1] = 0
    return clog

def sample_random_clogs(per_gen, generations, leading_ones, weight):
    clogs = []
    for length in range(1, generations):
        for _ in range(0, per_gen):
            clogs.append(random_clog(length, leading_ones, weight))
    rationals = list(map(clog_to_rational, clogs))
    precisions = list(map(prec_of_rat, rationals))
    plt.scatter(list(map(len, clogs)), list(map(prec_of_rat, map(clog_to_rational, clogs))))

# TODO: add worst + best cases to this scatterplot
# in different colors

def prec_of_rat(rational):
    return log2(rational[0]) + log2(rational[1])

#print(prec_of_rat(clog_to_rational(random_clog(30, 0, 0.5))))
plt.title("Random clog length vs bits required to express equivalent rational")
plt.xlabel("Continued Logarithm Terms")
plt.ylabel("Total Bits in Rational Representation (log2(num) + log2(den))")
#plt.xscale("log")
sample_random_clogs(10000, 100, 0, 0.5)
plt.show()
