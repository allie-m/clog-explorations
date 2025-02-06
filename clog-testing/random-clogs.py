from utils import *

from math import log2

import random

def random_clog(size, leading_ones):
    clog = [1] * leading_ones
    while len(clog) < size:
        clog.append(random.randint(0, 1))
    return clog

def sample_random_clogs(num, size, leading):
    for _ in range(0, num):
        clog = random_clog(num,)

def prec_of_rat(rational):
    return log2(rational[0]) + log2(rational[1])

print(prec_of_rat(clog_to_rational(random_clog(30, 0))))
