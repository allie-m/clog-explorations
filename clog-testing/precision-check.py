from utils import *
# 2^31 - 16 --- degenerate case, requires >400 bits
#_, _, cl, lm = rational_to_clog(2**31 - 16, 1)
#print(cl, len(cl), lm, avg_magnitude(cl))

# generate avg plausible rationals, convert to clogs, analytics
# generate avg plausible floats, convert to clogs, analytics
# generate totally random clog sequences of fixed lengths, analytics
# 	note that random clog sequences can be expected to have avg magnitude of 1
#   what about sequences weighted to have magnitudes < 1?

#import random
from numpy import random
from math import gcd, log2
from matplotlib import pyplot as plt

random.seed(198412)

def try_rationals(iters, gen_ft):
	info = []
	for i in range(iters):
		num, den = gen_ft(i)
		_, _, cl, lm = rational_to_clog(num, den)
		#print(num/den, int(log2(num)), int(log2(den)), len(cl), lm, avg_magnitude(cl))
		info.append((num/den, int(log2(num/den)), len(cl), lm, avg_magnitude(cl)))
	info = sorted(info, key=lambda i: i[0])
	return info

# (to be clear the data suggests this isn't actually the worst case for integers)
# (somehow)
# (this was just my hypothesized worst case)
def worst_case(p):
	info = []
	for i in range(p+1, 32):
		_, _, cl, lm = rational_to_clog(2**i - 2**p, 1)
		info.append((2**i - 2**p,  i, len(cl), lm, avg_magnitude(cl)))
	return info

def best_case():
	info = []
	for i in range(2, 32):
		_, _, cl, lm = rational_to_clog(2**i, 1)
		info.append((2**i, i, len(cl), lm, avg_magnitude(cl)))
	return info

def decompose_and_plot_infos(info):
	values = list(map(lambda i: i[0], info))
	magnitudes = list(map(lambda i: i[1], info))
	clog_lengths = list(map(lambda i: i[2], info))
	ld_ones = list(map(lambda i: i[3], info))
	avg_mags = list(map(lambda i: i[4], info))
	# what scatterplots we're producing

	#plt.scatter(values, clog_lengths)
	plt.scatter(values, avg_mags)

def _magnitudes_random_int32(i):
	mag = random.randint(3, 32)
	return random.randint(2**(mag-1) - 1, 2**mag - 1), 1

plt.title("32-bit ints (equal sampling from each order of magnitude)")
plt.xscale("log", base=2)
plt.xlabel("Integer Size")
plt.ylabel("Continued Logarithm Terms")
decompose_and_plot_infos(try_rationals(100000, _magnitudes_random_int32))
decompose_and_plot_infos(worst_case(1))
decompose_and_plot_infos(best_case())
#decompose_and_plot_infos(worst_case(2))
#decompose_and_plot_infos(worst_case(3))
#decompose_and_plot_infos(worst_case(4))

plt.show()
