// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcalculator.h for the primary calling header

#ifndef VERILATED_VCALCULATOR___024ROOT_H_
#define VERILATED_VCALCULATOR___024ROOT_H_  // guard

#include "verilated.h"


class Vcalculator__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vcalculator___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_OUT8(rgb0,0,0);
    VL_OUT8(rgb1,0,0);
    VL_OUT8(rgb2,0,0);
    VL_IN8(user_1,0,0);
    VL_OUT8(user_2,0,0);
    VL_OUT8(user_3,0,0);
    VL_IN8(user_4,0,0);
    VL_OUT8(usb_dp,0,0);
    VL_OUT8(usb_dn,0,0);
    VL_OUT8(usb_dp_pu,0,0);
    CData/*3:0*/ top__DOT__pyrtl_toplevel__DOT__my_calculator_out_z;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp10;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp11;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp12;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp13;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp14;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp15;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp16;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp17;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp18;
    CData/*4:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7899;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__was_toggled;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7710;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7728;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7746;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7763;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7781;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7798;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7815;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7831;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7847;
    CData/*3:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7861;
    CData/*4:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7923;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*26:0*/ top__DOT__pyrtl_toplevel__DOT__tmp0;
    IData/*26:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*2:0*/, 32> top__DOT__pyrtl_toplevel__DOT__mem_0;
    VlUnpacked<CData/*3:0*/, 32> top__DOT__pyrtl_toplevel__DOT__mem_1;
    VlUnpacked<CData/*3:0*/, 32> top__DOT__pyrtl_toplevel__DOT__mem_2;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vcalculator__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcalculator___024root(Vcalculator__Syms* symsp, const char* v__name);
    ~Vcalculator___024root();
    VL_UNCOPYABLE(Vcalculator___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
