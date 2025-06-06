import pyrtl

import sys
sys.path.append('..')
import blfts
from prelude import *

# NOTE: THIS ONLY FITS ON THE FOMU
# IF COEF_WIDTH IS SET TO LIKE 16

# use counter logic to divide system clock
# the clock is 48 MHz
# (somewhat slower w/blft i think)
FREQ = 1#25
counter = pyrtl.Register(bitwidth=27)
counter.next <<= counter + 1
high_bit = pyrtl.Register(bitwidth=1)
high_bit.next <<= counter[FREQ]
was_toggled = pyrtl.Register(bitwidth=1, name='was_toggled')
was_toggled.next <<= (high_bit != counter[FREQ])

in_1 = pyrtl.Input(bitwidth=1, name='in_1') # left
in_2 = pyrtl.Input(bitwidth=1, name='in_2') # right

red_o = pyrtl.Output(bitwidth=1, name='red_o')
green_o = pyrtl.Output(bitwidth=1, name='green_o')
blue_o = pyrtl.Output(bitwidth=1, name='blue_o')

blft = blfts.blft("my_calculator_", [0, 2, 1, 0, 0, 0, 0, 1], was_toggled)

index = pyrtl.Register(bitwidth=5)
ctrls, xs, ys = three_cycle_clogs("0", "10", 32, 5)

# current_out = pyrtl.WireVector(bitwidth=TERM_WIDTH)
# red_o   <<= blft.z == Term.NONE#(current_out == Term.ORD) | (current_out == Term.ORD_SPEC) | (current_out == Term.ORD_SING) | (current_out == Term.INF)
# green_o <<= (blft.z == Term.ORD) | (blft.z == Term.INF)#(current_out == Term.DREC) | (current_out == Term.DREC_SPEC) | (current_out == Term.REC) | (current_out == Term.REC_SPEC) | (current_out == Term.INF)
# blue_o  <<= (blft.z == Term.DREC) | (blft.z == Term.INF)#(current_out == Term.NEG) | (current_out == Term.REC) | (current_out == Term.REC_SPEC) | (current_out == Term.INF)

blft.ctrl <<= ctrls[index]
blft.x <<= xs[index]
blft.y <<= ys[index]

# red_o <<= blft.z == Term.NONE
# green_o <<= (blft.x | blft.y) != 0
# blue_o <<= (blft.z == Term.ORD) | (blft.z == Term.DREC) | (blft.z == Term.INF)
red_o <<= blft.z == Term.NONE
green_o <<= (blft.z == Term.ORD) | (blft.z == Term.INF)
blue_o <<= (blft.z == Term.DREC) | (blft.z == Term.INF)

with pyrtl.conditional_assignment:
    with was_toggled: # doing blft computation this cycle
        index.next |= index + 1
        # nc = ctrls[index] # TEMPORARY
        # with nc == Control.RESET: current_out.next |= Term.NEG
        # with nc == Control.X_IN: current_out.next |= Term.REC
        # with nc == Control.Y_IN: current_out.next |= Term.REC
        # with nc == Control.Z_OUT: current_out.next |= Term.REC
    #     with blft.ctrl == Control.X_IN:
    #         blft.ctrl.next |= Control.Y_IN
    #         blft.y.next |= Term.INF
    #         # current_out.next |= Term.ORD # TODO TEMPORARY PLACEHOLDER
    #     with blft.ctrl == Control.Y_IN:
    #         blft.ctrl.next |= Control.Z_OUT
    #         # current_out.next |= Term.DREC # TODO TEMPORARY PLACEHOLDER
    #     with blft.ctrl == Control.Z_OUT:
    #         blft.ctrl.next |= Control.X_IN
    #         blft.x.next |= Term.INF
    #         current_out.next |= blft.z
    #     with pyrtl.otherwise:
    #         blft.ctrl.next |= Control.X_IN
    #         blft.x.next |= Term.INF
    #         # current_out.next |= Term.REC # TODO TEMPORARY PLACEHOLDER

# TEMPORARY SIM
sim_trace = pyrtl.SimulationTrace()
sim = pyrtl.Simulation(tracer=sim_trace, register_value_map={}, memory_value_map={})
sim.step_multiple({in_1: [0]*64, in_2: [0]*64})
sim_trace.render_trace(repr_per_name={'ctrl': pyrtl.enum_name(Control), 'in_x': pyrtl.enum_name(Term), 'in_y': pyrtl.enum_name(Term), 'out_z': pyrtl.enum_name(Term)})
print(sim.inspect(blft.mat[0]), sim.inspect(blft.mat[1]), sim.inspect(blft.mat[2]), sim.inspect(blft.mat[3]))
print(sim.inspect(blft.mat[4]), sim.inspect(blft.mat[5]), sim.inspect(blft.mat[6]), sim.inspect(blft.mat[7]))
pyrtl.optimize()

# https://mdko.github.io/2021/05/15/pyrtl-matmul.html
# (where i got this timing code from; thanks zach's friend)
# (and it seems to vaguely be corroborated by the fpga's performance/numbers)
# ta = pyrtl.TimingAnalysis()
# print(f"Max frequency: {ta.max_freq()} MhZ")
# print(f"Max timing delay: {ta.max_length()} ps")
# print(f"Logic count: {len({l for l in pyrtl.working_block().logic if l.op not in 'wcs'})}")
# logic, _ = pyrtl.area_estimation()
# print(f"Logic area est: {logic}mm^2")

##=========================================================================##
## Do not change the code below this header!
## Export this PyRTL code to Verilog, then combine it with the Verilog
## harness code in `fomu.v`, creating new file `out.v`.
##=========================================================================##
with open('calculator.v', 'w') as out:
    with open("fomu.v", 'r') as harness:
        out.write(harness.read())
    pyrtl.importexport.output_to_verilog(dest_file=out, add_reset=False, initialize_registers=True)
