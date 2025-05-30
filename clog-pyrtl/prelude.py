import pyrtl
from pyrtl.corecircuits import *
from dataclasses import dataclass
from enum import IntEnum

# dials we can fiddle with
COEF_WIDTH = 8
MAX_VAL = 2**(COEF_WIDTH - 1) - 1
MIN_VAL = -(2**(COEF_WIDTH - 1))
ENABLE_SPECULATIVE_EGEST = pyrtl.WireVector(bitwidth=1, name='cfg_speculative_egest')
ENABLE_SPECULATIVE_EGEST <<= 1 # 0 for no speculative egest (could be a pyrtl.Const... whatever)

CTRL_WIDTH = 3
class Control(IntEnum):
    NONE  = 0b000
    X_IN  = 0b001
    Y_IN  = 0b010
    Z_OUT = 0b011
    RESET = 0b100

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

# creates a romblock fit for consumption by a 3-cycle blft/nlft/etc
# given two input clogs specified as strings
def three_cycle_clogs(cl1: str, cl2: str, cycles, addrwidth):
    def c_to_term(c):
        if c == "0": return Term.DREC
        if c == "1": return Term.ORD
        if c == "/": return Term.REC
        if c == "-": return Term.NEG
        if c == "oo": return Term.INF
        raise Exception("ahhhhhhhhh invalid clog char")
    cl1 = list(map(c_to_term, cl1)) + [Term.INF]
    cl2 = list(map(c_to_term, cl2)) + [Term.INF]
    ctrl = [Control.RESET] + ([Control.X_IN, Control.Y_IN, Control.Z_OUT] * (cycles-2)) + [Control.NONE]
    ncl1 = [Term.NONE]
    ncl2 = [Term.NONE]
    for i in range(cycles-1):
        if i//3 < len(cl1): ncl1.append(cl1[i//3])
        else: ncl1.append(Term.NONE)
        if i//3 < len(cl2): ncl2.append(cl2[i//3])
        else: ncl2.append(Term.NONE)
    ctrl = pyrtl.RomBlock(bitwidth=CTRL_WIDTH, addrwidth=addrwidth, romdata=ctrl, pad_with_zeros=True)
    x = pyrtl.RomBlock(bitwidth=TERM_WIDTH, addrwidth=addrwidth, romdata=ncl1, pad_with_zeros=True)
    y = pyrtl.RomBlock(bitwidth=TERM_WIDTH, addrwidth=addrwidth, romdata=ncl2, pad_with_zeros=True)
    return (ctrl, x, y)

# helper circuits

# TODO find some way to have these have a big bit-or'd output

# def abs_val(val): return mux(signed_lt(val, 0), 0 - val, val)
# def s_neg(val): return 0 - val
# def s_add(a, b): return signed_add(a, b)
# def s_shift_left(val, shamt): return shift_left_arithmetic(val, shamt)

def abs_val(val):
    return mux(val[COEF_WIDTH-1] == 1, val, s_neg(val))

def s_neg(val):
    is_min = val == pyrtl.Const(MIN_VAL, bitwidth=COEF_WIDTH)
    return mux(is_min, 0 - val, MAX_VAL)

def s_add(a, b):
    the_sum = signed_add(a, b)[:COEF_WIDTH]
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
