import pyrtl
from pyrtl.corecircuits import *
from enum import IntEnum

# dials we can fiddle with
COEF_WIDTH = 256
MAX_VAL = 2**(COEF_WIDTH - 1) - 1
MIN_VAL = -(2**(COEF_WIDTH - 1))
ENABLE_SPECULATIVE_EGEST = pyrtl.WireVector(bitwidth=1, name='cfg_speculative_egest')
ENABLE_SPECULATIVE_EGEST <<= 1 # 0 for no speculative egest (could be a pyrtl.Const... whatever)

CTRL_WIDTH = 2
class Control(IntEnum):
    NONE  = 0b00
    X_IN  = 0b01
    Y_IN  = 0b10
    Z_OUT = 0b11

TERM_WIDTH = 4
class Term(IntEnum):
    NONE      = 0
    ORD       = 1
    ORD_SPEC  = 2
    ORD_SING  = 3
    DREC      = 4
    DREC_SPEC = 5
    REC       = 6
    REC_SPEC  = 7
    NEG       = 8
    INF       = 15

# helper circuits

def abs_val(val):
    out = pyrtl.WireVector(bitwidth=val.bitwidth)
    out <<= mux(signed_lt(val, 0), 0 - val, val)
    return out

# saturating versions of neg, signed_add, and shift_left_arithmetic
# that also TODO sets the out_inexact flag

def s_neg(val):
    # TODO
    return 0 - val

def s_add(a, b):
    the_sum = signed_add(a, b)
    out = pyrtl.WireVector(bitwidth=COEF_WIDTH)
    with pyrtl.conditional_assignment:
        # (+) + (+) = (- | 0)
        with signed_lt(0, a) & signed_lt(0, b) & signed_le(the_sum, 0):
            out |= pyrtl.Const(MAX_VAL, bitwidth=COEF_WIDTH)
        # (-) + (-) = (+ | 0)
        with signed_lt(a, 0) & signed_lt(b, 0) & signed_le(0, the_sum):
            out |= pyrtl.Const(MIN_VAL, bitwidth=COEF_WIDTH)
        # no overflow
        with pyrtl.otherwise:
            out |= the_sum
    return out

def s_shift_left(val, shamt):
    shifted = shift_left_arithmetic(val, shamt)
    out = pyrtl.WireVector(bitwidth=COEF_WIDTH)
    with pyrtl.conditional_assignment:
        # (+) << shamt = (-)
        # (you can't shift into 0 from +)
        with signed_lt(0, val) & signed_lt(shifted, 0):
            out |= pyrtl.Const(MAX_VAL, bitwidth=COEF_WIDTH)
        # (-) << shamt = (+ | 0)
        with signed_lt(val, 0) & signed_le(0, shifted):
            out |= pyrtl.Const(MIN_VAL, bitwidth=COEF_WIDTH)
        # no overflow
        with pyrtl.otherwise:
            out |= shifted
    return out
