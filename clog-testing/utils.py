from math import gcd

def leading_ones(cl):
    i = 0
    while i < len(cl) and cl[i] != 0:
        i += 1
    return i

# does NOT count the first block
def avg_magnitude(cl):
    blocks = 0
    cl = cl[cl.index(0):]
    for term in cl:
        if term == 0:
            blocks += 1
    return len(cl) / blocks

def clog_to_rational(cl):
    mat = [1, 0, 0, 1]
    for term in cl:
        if term == 1:
            mat[0] *= 2
            mat[2] *= 2
        elif term == 0:
            mat[1] += mat[0]
            mat[3] += mat[2]
            mat[0], mat[1] = mat[1], mat[0]
            mat[2], mat[3] = mat[3], mat[2]
        elif term == '/':
           mat[0], mat[1] = mat[1], mat[0]
           mat[2], mat[3] = mat[3], mat[2]
    g = gcd(mat[0], mat[2])
    return mat[0]//g, mat[2]//g

def rational_to_clog(num, den):
    cl = []
    neg = (num < 0) ^ (den < 0)
    num, den = abs(num), abs(den)
    recip = num < den
    if recip: num, den = den, num
    while den != 0:
        if num >= 2 * den:
            cl.append(1)
            if num % 2 == 0: num //= 2
            else: den *= 2
        elif num >= den:
            cl.append(0)
            num -= den
            num, den = den, num
    return neg, recip, cl, leading_ones(cl)

def f64_to_clog(val):
    cl = []
    neg = val < 0
    if neg: val = -val
    recip = val < 1
    if recip: val = 1/val
    while val != float("inf"):
        if val >= 2:
            val /= 2
            cl.append(1)
        elif val >= 1:
            val -= 1
            val = 1/val
            cl.append(0)
    return neg, recip, cl, leading_ones(cl)

print(clog_to_rational([1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0]))
print(clog_to_rational([1, 1, 1, 1, 1, 0, 1, '/', 0, 1, 1, 1, 0]))
