from prelude import *

# TODO roll this up into a single function
# returning the input/output/registers
# TODO class struct for output

# i could have used an rf memblock with 8 read and write ports
# but this is easier
# too much swapping stuff around to deal with that
m0 = pyrtl.Register(bitwidth=COEF_WIDTH)
m1 = pyrtl.Register(bitwidth=COEF_WIDTH)
m2 = pyrtl.Register(bitwidth=COEF_WIDTH)
m3 = pyrtl.Register(bitwidth=COEF_WIDTH)
m4 = pyrtl.Register(bitwidth=COEF_WIDTH)
m5 = pyrtl.Register(bitwidth=COEF_WIDTH)
m6 = pyrtl.Register(bitwidth=COEF_WIDTH)
m7 = pyrtl.Register(bitwidth=COEF_WIDTH)
singularity = pyrtl.Register(bitwidth=1)

ctrl = pyrtl.Input(bitwidth=CTRL_WIDTH, name='ctrl')
#in_inexact = pyrtl.Input(bitwidth=1, name='in_inexact')
# this would indicate an overflow (shift or add/sub) and that the results can't be trusted
# (likewise the out variant)
# TODO we should use saturating add/bitshift to make sure it's inexact instead of garbage
x = pyrtl.Input(bitwidth=TERM_WIDTH, name='in_x')
y = pyrtl.Input(bitwidth=TERM_WIDTH, name='in_y')
z = pyrtl.Output(bitwidth=TERM_WIDTH, name='out_z')
#out_inexact = pyrtl.Output(bitwidth=1, name='out_inexact')

# brabec sketched out and implemented a design with the components:
# controller, register file, transform logic (minimal but wide ALU w/register writeback), and compare logic
# i don't think this design will differ much from that vision
# we're sorta only half doing the controller since we take inputs for ctrl/x/y
# but a more advanced approach (brabec's) would be for the compare logic to suggest control actions
# rather than x/y/z on each cycle (or however many cycles this actually amounts to)
# which is what gosper does
# and what i think i'll do here since it's just so simple and easy to daisy chain (especially if we're mixing unit types)

# (intermediate flags and wires defined for egestion)
num_agreed   = pyrtl.WireVector(bitwidth=1, name='e_num')
den_agreed   = pyrtl.WireVector(bitwidth=1, name='e_den')
den_zeros    = pyrtl.WireVector(bitwidth=1, name='e_zeros')
well_defined = pyrtl.WireVector(bitwidth=1, name='e_welldf')
all_neven    = pyrtl.WireVector(bitwidth=1, name='e_nums_even')
# (intermediate mat coefficients with the signs flipped if they're all negative)
i0 = pyrtl.WireVector(bitwidth=COEF_WIDTH)
i1 = pyrtl.WireVector(bitwidth=COEF_WIDTH)
i2 = pyrtl.WireVector(bitwidth=COEF_WIDTH)
i3 = pyrtl.WireVector(bitwidth=COEF_WIDTH)
i4 = pyrtl.WireVector(bitwidth=COEF_WIDTH)
i5 = pyrtl.WireVector(bitwidth=COEF_WIDTH)
i6 = pyrtl.WireVector(bitwidth=COEF_WIDTH)
i7 = pyrtl.WireVector(bitwidth=COEF_WIDTH)

with pyrtl.conditional_assignment:
    # ingest x
    with ctrl == Control.X_IN:
        # (z and singularity are irrelevant; preserve singularity, emit nothing)
        # (singularity is amended on egest check)
        z |= Term.NONE
        singularity.next |= singularity
        with x == Term.NONE:
            pass
        with x == Term.INF:
            m2.next |= m0
            m3.next |= m1
            m6.next |= m4
            m7.next |= m5
        with (x == Term.ORD) | (x == Term.ORD_SPEC) | (x == Term.ORD_SING):
            m0.next |= shift_left_logical(m0, 1)
            m1.next |= shift_left_logical(m1, 1)
            m4.next |= shift_left_logical(m4, 1)
            m5.next |= shift_left_logical(m5, 1)
        with (x == Term.REC) | (x == Term.REC_SPEC):
            m0.next |= m2
            m2.next |= m0
            m1.next |= m3
            m3.next |= m1
            m4.next |= m6
            m6.next |= m4
            m5.next |= m7
            m7.next |= m5
        with (x == Term.DREC) | (x == Term.DREC_SPEC):
            m0.next |= m0 + m2
            m2.next |= m0
            m1.next |= m1 + m3
            m3.next |= m1
            m4.next |= m4 + m6
            m6.next |= m4
            m5.next |= m5 + m7
            m7.next |= m5
        with x == Term.NEG:
            m0.next |= 0 - m0
            m1.next |= 0 - m1
            m4.next |= 0 - m4
            m5.next |= 0 - m5
    # ingest y
    with ctrl == Control.Y_IN:
        # (z and singularity are irrelevant; preserve singularity, emit nothing)
        # (singularity is amended on egest check)
        z |= Term.NONE
        singularity.next |= singularity
        with y == Term.NONE:
            pass
        with y == Term.INF:
            m1.next |= m0
            m3.next |= m2
            m5.next |= m4
            m7.next |= m6
        with (y == Term.ORD) | (y == Term.ORD_SPEC) | (y == Term.ORD_SING):
            m0.next |= shift_left_logical(m0, 1)
            m2.next |= shift_left_logical(m2, 1)
            m4.next |= shift_left_logical(m4, 1)
            m6.next |= shift_left_logical(m6, 1)
        with (y == Term.REC) | (y == Term.REC_SPEC):
            m0.next |= m1
            m1.next |= m0
            m2.next |= m3
            m3.next |= m2
            m4.next |= m5
            m5.next |= m4
            m6.next |= m7
            m7.next |= m6
        with (y == Term.DREC) | (y == Term.DREC_SPEC):
            m0.next |= m0 + m1
            m1.next |= m0
            m2.next |= m2 + m3
            m3.next |= m2
            m4.next |= m4 + m5
            m5.next |= m4
            m6.next |= m6 + m7
            m7.next |= m6
        with y == Term.NEG:
            m0.next |= 0 - m0
            m2.next |= 0 - m2
            m4.next |= 0 - m4
            m6.next |= 0 - m6
    # egest z
    with ctrl == Control.Z_OUT:
        num_agreed |= (signed_lt(m0, 0) == signed_lt(m1, 0)) &\
                      (signed_lt(m1, 0) == signed_lt(m2, 0)) &\
                      (signed_lt(m2, 0) == signed_lt(m3, 0))
        den_agreed |= (signed_lt(m4, 0) == signed_lt(m5, 0)) &\
                      (signed_lt(m5, 0) == signed_lt(m6, 0)) &\
                      (signed_lt(m6, 0) == signed_lt(m7, 0))
        den_zeros  |= (m4 == 0) | (m5 == 0) | (m6 == 0) | (m7 == 0)
        well_defined |= num_agreed & den_agreed & ~den_zeros
        all_neven  |= ~(m0[0] | m1[0] | m2[0] | m3[0])
        # flip all negatives to all positives
        # only relevant if we're well defined
        with well_defined & signed_lt(m0, 0) & signed_lt(m4, 0):
            i0 |= 0 - m0; i1 |= 0 - m1; i2 |= 0 - m2; i3 |= 0 - m3
            i4 |= 0 - m4; i5 |= 0 - m5; i6 |= 0 - m6; i7 |= 0 - m7
        with well_defined & ~(signed_lt(m0, 0) & signed_lt(m4, 0)):
            i0 |= m0; i1 |= m1; i2 |= m2; i3 |= m3
            i4 |= m4; i5 |= m5; i6 |= m6; i7 |= m7
        with pyrtl.otherwise: pass

        # all zero denominator; we're infinite!
        with (m4 == 0) & (m5 == 0) & (m6 == 0) & (m7 == 0):
            z |= Term.INF
            singularity.next |= 0
        # we're well defined, it's time to egest :D (probably)
        with well_defined:
            # it's no longer a singularity if we're well defined
            # UNLESS we're about to create a new one
            # so each of these conditions has to set the flag separately
            
            # first, the nonspeculative terms
            # neg
            with signed_lt(m0, 0) != signed_lt(m4, 0):
                z |= Term.NEG # (no need to use the i variants for negative)
                singularity.next |= 0
                m0.next |= 0 - m0
                m1.next |= 0 - m1
                m2.next |= 0 - m2
                m3.next |= 0 - m3
            # ord
            with signed_ge(shift_right_arithmetic(i0, 1), i4) &\
                 signed_ge(shift_right_arithmetic(i1, 1), i5) &\
                 signed_ge(shift_right_arithmetic(i2, 1), i6) &\
                 signed_ge(shift_right_arithmetic(i3, 1), i7):
                z |= Term.ORD
                singularity.next |= 0
                with all_neven:
                    m0.next |= shift_right_arithmetic(i0, 1)
                    m1.next |= shift_right_arithmetic(i1, 1)
                    m2.next |= shift_right_arithmetic(i2, 1)
                    m3.next |= shift_right_arithmetic(i3, 1)
                    m4.next |= i4; m5.next |= i5; m6.next |= i6; m7.next |= i7
                with pyrtl.otherwise:
                    m0.next |= i0; m1.next |= i1; m2.next |= i2; m3.next |= i3
                    m4.next |= shift_left_arithmetic(i4, 1)
                    m5.next |= shift_left_arithmetic(i5, 1)
                    m6.next |= shift_left_arithmetic(i6, 1)
                    m7.next |= shift_left_arithmetic(i7, 1)
            # drec
            with signed_ge(i0, i4) & signed_ge(i1, i5) &\
                 signed_ge(i2, i6) & signed_ge(i3, i7) &\
                 signed_lt(shift_right_arithmetic(i0, 1), i4) &\
                 signed_lt(shift_right_arithmetic(i1, 1), i5) &\
                 signed_lt(shift_right_arithmetic(i2, 1), i6) &\
                 signed_lt(shift_right_arithmetic(i3, 1), i7):
                z |= Term.DREC
                singularity.next |= 0
                m0.next |= i4
                m4.next |= i0 - i4
                m1.next |= i5
                m5.next |= i1 - i5
                m2.next |= i6
                m6.next |= i2 - i6
                m3.next |= i7
                m7.next |= i3 - i7
            # rec
            with signed_lt(i0, i4) & signed_lt(i1, i5) & signed_lt(i2, i6) & signed_lt(i3, i7):
                z |= Term.REC
                singularity.next |= 0
                m0.next |= i4
                m4.next |= i0
                m1.next |= i5
                m5.next |= i1
                m2.next |= i6
                m6.next |= i2
                m3.next |= i7
                m7.next |= i3
            # now it's time for SPECULATIVE TERMS oooo
            with ENABLE_SPECULATIVE_EGEST:
                # ord spec
                with signed_lt(i4, i0) & signed_lt(i0, shift_left_arithmetic(i4, 2)) &\
                     signed_lt(i5, i1) & signed_lt(i1, shift_left_arithmetic(i5, 2)) &\
                     signed_lt(i6, i2) & signed_lt(i2, shift_left_arithmetic(i6, 2)) &\
                     signed_lt(i7, i3) & signed_lt(i3, shift_left_arithmetic(i7, 2)):
                    z |= Term.ORD_SPEC
                    singularity.next |= 0
                    with all_neven:
                        m0.next |= shift_right_arithmetic(i0, 1)
                        m1.next |= shift_right_arithmetic(i1, 1)
                        m2.next |= shift_right_arithmetic(i2, 1)
                        m3.next |= shift_right_arithmetic(i3, 1)
                        m4.next |= i4; m5.next |= i5; m6.next |= i6; m7.next |= i7
                    with pyrtl.otherwise:
                        m0.next |= i0; m1.next |= i1; m2.next |= i2; m3.next |= i3
                        m4.next |= shift_left_arithmetic(i4, 1)
                        m5.next |= shift_left_arithmetic(i5, 1)
                        m6.next |= shift_left_arithmetic(i6, 1)
                        m7.next |= shift_left_arithmetic(i7, 1)
                # drec spec; creates a singularity!!
                with signed_lt(i4, shift_left_arithmetic(i0, 1)) &\
                     signed_lt(i0, shift_left_arithmetic(i4, 1)) &\
                     signed_lt(i5, shift_left_arithmetic(i1, 1)) &\
                     signed_lt(i1, shift_left_arithmetic(i5, 1)) &\
                     signed_lt(i6, shift_left_arithmetic(i2, 1)) &\
                     signed_lt(i2, shift_left_arithmetic(i6, 1)) &\
                     signed_lt(i7, shift_left_arithmetic(i3, 1)) &\
                     signed_lt(i3, shift_left_arithmetic(i7, 1)):
                    z |= Term.DREC_SPEC
                    singularity.next |= 1
                    m0.next |= i4
                    m4.next |= i0 - i4
                    m1.next |= i5
                    m5.next |= i1 - i5
                    m2.next |= i6
                    m6.next |= i2 - i6
                    m3.next |= i7
                    m7.next |= i3 - i7
                # nothing yet to egest; we need to take more terms!
                with pyrtl.otherwise:
                    z |= Term.NONE
                    singularity.next |= 0
            # nothing yet to egest; we need to take more terms!
            with pyrtl.otherwise:
                z |= Term.NONE
                singularity.next |= 0
        # we're not well defined!!
        # note that we don't use the intermediate variants
        # as they won't have been set if we're not well defined
        with ENABLE_SPECULATIVE_EGEST:
            # rec spec; initiates a singularity!!
            with signed_lt(abs_val(m0), abs_val(m4)) &\
                 signed_lt(abs_val(m1), abs_val(m5)) &\
                 signed_lt(abs_val(m2), abs_val(m6)) &\
                 signed_lt(abs_val(m3), abs_val(m7)):
                z |= Term.REC
                singularity.next |= 1
                m0.next |= m4
                m4.next |= m0
                m1.next |= m5
                m5.next |= m1
                m2.next |= m6
                m6.next |= m2
                m3.next |= m7
                m7.next |= m3
            # we previously speculated our way into a singularity (the flag was set)
            # and will continue to have a singularity until we ingest clarifying terms
            with singularity &\
                 signed_ge(shift_right_arithmetic(abs_val(m0), 1), abs_val(m4)) &\
                 signed_ge(shift_right_arithmetic(abs_val(m1), 1), abs_val(m5)) &\
                 signed_ge(shift_right_arithmetic(abs_val(m2), 1), abs_val(m6)) &\
                 signed_ge(shift_right_arithmetic(abs_val(m3), 1), abs_val(m7)):
                z |= Term.ORD_SING
                singularity.next |= 1
                with all_neven:
                    m0.next |= shift_right_arithmetic(m0, 1)
                    m1.next |= shift_right_arithmetic(m1, 1)
                    m2.next |= shift_right_arithmetic(m2, 1)
                    m3.next |= shift_right_arithmetic(m3, 1)
                    # (no need for this since we're not correcting the signs w/i coefficients)
                    # m4.next |= m4; m5.next |= m5; m6.next |= m6; m7.next |= m7
                with pyrtl.otherwise:
                    # m0.next |= m0; m1.next |= m1; m2.next |= m2; m3.next |= m3
                    m4.next |= shift_left_arithmetic(m4, 1)
                    m5.next |= shift_left_arithmetic(m5, 1)
                    m6.next |= shift_left_arithmetic(m6, 1)
                    m7.next |= shift_left_arithmetic(m7, 1)
            # nothing yet to egest; we need to take more terms!
            with pyrtl.otherwise:
                z |= Term.NONE
                singularity.next |= singularity
        # nothing yet to egest; we need to take more terms!
        with pyrtl.otherwise:
            z |= Term.NONE
            singularity.next |= singularity

pyrtl.optimize()
# timing = pyrtl.TimingAnalysis()
# timing.print_max_length()
# critical_path_info = timing.critical_path()
# print(list(map(lambda l: len(l[1]), critical_path_info)))
logic_area, mem_area = pyrtl.area_estimation(tech_in_nm=65)
est_area = logic_area + mem_area
print("Estimated area of block", est_area, "sq mm")

# test it :D
if __name__ == "__main__":
    ctrls = [Control.X_IN, Control.Y_IN, Control.X_IN, Control.Y_IN, Control.Y_IN, Control.Z_OUT, Control.Z_OUT, Control.Z_OUT, Control.Z_OUT, Control.Z_OUT, Control.Z_OUT, Control.NONE]
    xs    = [Term.DREC, Term.NONE, Term.INF,  Term.NONE, Term.NONE, Term.NONE,  Term.NONE,  Term.NONE,  Term.NONE,  Term.NONE,  Term.NONE, Term.NONE]
    ys    = [Term.NONE, Term.ORD,  Term.NONE, Term.DREC, Term.INF,  Term.NONE,  Term.NONE,  Term.NONE,  Term.NONE,  Term.NONE,  Term.NONE, Term.NONE]
    tmat = {m0: 0, m1: 2, m2: 1, m3: 0,
            m4: 0, m5: 0, m6: 0, m7: 1,
            singularity: 0}
    sim_trace = pyrtl.SimulationTrace()
    sim = pyrtl.Simulation(tracer=sim_trace, register_value_map=tmat)
    sim.step_multiple({'ctrl': ctrls, 'in_x': xs, 'in_y': ys})
    sim_trace.render_trace(repr_per_name={'ctrl': pyrtl.enum_name(Control), 'in_x': pyrtl.enum_name(Term), 'in_y': pyrtl.enum_name(Term), 'out_z': pyrtl.enum_name(Term)})
    print(sim.inspect(m0), sim.inspect(m1), sim.inspect(m2), sim.inspect(m3))
    print(sim.inspect(m4), sim.inspect(m5), sim.inspect(m6), sim.inspect(m7))
