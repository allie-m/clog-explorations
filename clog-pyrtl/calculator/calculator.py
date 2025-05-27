import pyrtl

import sys
sys.path.append('..')
import blfts
from prelude import *

# use counter logic to divide system clock
# the clock is 48 MHz
counter = pyrtl.Register(bitwidth=26)
counter.next <<= counter + 1

high_bit = pyrtl.Register(bitwidth=1)
high_bit.next <<= counter[24]
was_toggled = pyrtl.Register(bitwidth=1)
was_toggled.next <<= high_bit != counter[24]

in_1 = pyrtl.Input(bitwidth=1, name='in_1') # left
in_2 = pyrtl.Input(bitwidth=1, name='in_2') # right

red_o = pyrtl.Output(bitwidth=1, name='red_o')
green_o = pyrtl.Output(bitwidth=1, name='green_o')
blue_o = pyrtl.Output(bitwidth=1, name='blue_o')

blft = blfts.blft("my_calculator_", [0, 2, 1, 0, 0, 0, 0, 1])

current_out = pyrtl.Register(bitwidth=3)

red_o   |= (current_out == Term.ORD) | (current_out == Term.ORD_SPEC) | (current_out == Term.ORD_SING) | (current_out == Term.INF)
green_o |= (current_out == Term.DREC) | (current_out == Term.DREC_SPEC) | (current_out == Term.REC) | (current_out == Term.REC_SPEC) | (current_out == Term.INF)
blue_o  |= (current_out == Term.NEG) | (current_out == Term.REC) | (current_out == Term.REC_SPEC) | (current_out == Term.INF)
# TODO convert blft to registers (or figure out how to embed a block in another block i guess)
# with pyrtl.conditional_assignment:
#     with was_toggled:
#         with blft.ctrl == Control.NONE: blft.ctrl |= Control.X_IN
#         with blft.ctrl == Control.X_IN:
#             blft.x |= Term.ORD
#             blft.ctrl |= Control.Y_IN
#         with blft.ctrl == Control.Y_IN:
#             blft.y |= Term.ORD
#             blft.ctrl |= Control.Z_OUT
#         with blft.ctrl == Control.Z_OUT:
#             current_out.next |= blft.z
#             blft.ctrl |= Control.X_IN

# TODO: THE PLAN
# user provides little endian bitstrings specifying two rationals and an operation
# which we pack into a blft's coefficient matrix
# and then do the cyclic x/y/z; each output is a color (2^3=8 colors, 8 clog terms)
# outputs are metered by the counter
# (we can also mayyyybe use the counter to profile(ish) how long the blft took)
# IDEA: start with a hardcoded blft matrix outputting, then let users configure

##=========================================================================##
## Do not change the code below this header!
## Export this PyRTL code to Verilog, then combine it with the Verilog
## harness code in `fomu.v`, creating new file `out.v`.
##=========================================================================##
with open('calculator.v', 'w') as out:
    with open("fomu.v", 'r') as harness:
        out.write(harness.read())
    pyrtl.importexport.output_to_verilog(dest_file=out, add_reset=False)
