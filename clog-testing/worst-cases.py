from utils import *

# tests integers of the form e.g. 0b1011111111 or 0b1111111110
def test_int_off_by(exp, p):
    _, _, cl, lm = rational_to_clog(2**exp - 2**p, 1)
    print(len(cl), lm, avg_magnitude(cl))

test_int_off_by(31, 1)
test_int_off_by(31, 2)
test_int_off_by(31, 3)
test_int_off_by(31, 4)
test_int_off_by(31, 5)
test_int_off_by(31, 6)
test_int_off_by(31, 7)
test_int_off_by(31, 8)
test_int_off_by(31, 9)
test_int_off_by(31, 10)
test_int_off_by(31, 11)
test_int_off_by(31, 12)
test_int_off_by(31, 13)
print("compare with")
_, _, cl, lm = rational_to_clog(2**31 - 1920, 1)
print(len(cl), lm, avg_magnitude(cl))
_, _, cl, lm = rational_to_clog(2**31 - 19201284, 1)
print(len(cl), lm, avg_magnitude(cl))
_, _, cl, lm = rational_to_clog(2**31 - 58, 1)
print(len(cl), lm, avg_magnitude(cl))
