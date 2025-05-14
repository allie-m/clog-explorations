import pyrtl
from pyrtl.corecircuits import *
from dataclasses import dataclass
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

# there are exactly 76 invocations of these saturate functions
# in the current implementation of blfts
# TODO find some way to have these have a big bit or output

# def s_neg(val): return 0 - val
# def s_add(a, b): return signed_add(a, b)
# def s_shift_left(val, shamt): return shift_left_arithmetic(val, shamt)

def s_neg(val):
    is_min = val == pyrtl.Const(MIN_VAL, bitwidth=COEF_WIDTH)
    return mux(is_min, 0 - val, MAX_VAL)

def s_add(a, b):
    the_sum = signed_add(a, b)
    # (+) + (+) = (- | 0)
    overflow_pos = signed_lt(0, a) & signed_lt(0, b) & signed_le(the_sum, 0)
    # (-) + (-) = (+ | 0)
    overflow_neg = signed_lt(a, 0) & signed_lt(b, 0) & signed_le(0, the_sum)
    i = mux(overflow_pos, the_sum, pyrtl.Const(MAX_VAL, bitwidth=COEF_WIDTH))
    return mux(overflow_neg, i, pyrtl.Const(MIN_VAL, bitwidth=COEF_WIDTH))

def s_shift_left(val, shamt):
    shifted = shift_left_arithmetic(val, shamt)
    # (+) << shamt = (-)
    overflow_pos = signed_lt(0, val) & signed_lt(shifted, 0)
    # (-) << shamt = (+ | 0)
    overflow_neg = signed_lt(val, 0) & signed_le(0, shifted)
    i = mux(overflow_pos, shifted, pyrtl.Const(MAX_VAL, bitwidth=COEF_WIDTH))
    return mux(overflow_neg, i, pyrtl.Const(MIN_VAL, bitwidth=COEF_WIDTH))
