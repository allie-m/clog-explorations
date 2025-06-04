// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcalculator.h for the primary calling header

#include "Vcalculator__pch.h"
#include "Vcalculator___024root.h"

void Vcalculator___024root___eval_act(Vcalculator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcalculator___024root___eval_act\n"); );
    Vcalculator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vcalculator___024root___nba_sequent__TOP__0(Vcalculator___024root* vlSelf);

void Vcalculator___024root___eval_nba(Vcalculator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcalculator___024root___eval_nba\n"); );
    Vcalculator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vcalculator___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vcalculator___024root___nba_sequent__TOP__0(Vcalculator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcalculator___024root___nba_sequent__TOP__0\n"); );
    Vcalculator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp36;
    top__DOT__pyrtl_toplevel__DOT__tmp36 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp44;
    top__DOT__pyrtl_toplevel__DOT__tmp44 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp79;
    top__DOT__pyrtl_toplevel__DOT__tmp79 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp89;
    top__DOT__pyrtl_toplevel__DOT__tmp89 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp107;
    top__DOT__pyrtl_toplevel__DOT__tmp107 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp136;
    top__DOT__pyrtl_toplevel__DOT__tmp136 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp150;
    top__DOT__pyrtl_toplevel__DOT__tmp150 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp192;
    top__DOT__pyrtl_toplevel__DOT__tmp192 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp217;
    top__DOT__pyrtl_toplevel__DOT__tmp217 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp242;
    top__DOT__pyrtl_toplevel__DOT__tmp242 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp284;
    top__DOT__pyrtl_toplevel__DOT__tmp284 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp399;
    top__DOT__pyrtl_toplevel__DOT__tmp399 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp404;
    top__DOT__pyrtl_toplevel__DOT__tmp404 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp411;
    top__DOT__pyrtl_toplevel__DOT__tmp411 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp424;
    top__DOT__pyrtl_toplevel__DOT__tmp424 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp471;
    top__DOT__pyrtl_toplevel__DOT__tmp471 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp522;
    top__DOT__pyrtl_toplevel__DOT__tmp522 = 0;
    SData/*9:0*/ top__DOT__pyrtl_toplevel__DOT__tmp529;
    top__DOT__pyrtl_toplevel__DOT__tmp529 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp555;
    top__DOT__pyrtl_toplevel__DOT__tmp555 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp583;
    top__DOT__pyrtl_toplevel__DOT__tmp583 = 0;
    SData/*9:0*/ top__DOT__pyrtl_toplevel__DOT__tmp650;
    top__DOT__pyrtl_toplevel__DOT__tmp650 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp676;
    top__DOT__pyrtl_toplevel__DOT__tmp676 = 0;
    SData/*9:0*/ top__DOT__pyrtl_toplevel__DOT__tmp771;
    top__DOT__pyrtl_toplevel__DOT__tmp771 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp797;
    top__DOT__pyrtl_toplevel__DOT__tmp797 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp837;
    top__DOT__pyrtl_toplevel__DOT__tmp837 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp870;
    top__DOT__pyrtl_toplevel__DOT__tmp870 = 0;
    SData/*9:0*/ top__DOT__pyrtl_toplevel__DOT__tmp892;
    top__DOT__pyrtl_toplevel__DOT__tmp892 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1025;
    top__DOT__pyrtl_toplevel__DOT__tmp1025 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1054;
    top__DOT__pyrtl_toplevel__DOT__tmp1054 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1089;
    top__DOT__pyrtl_toplevel__DOT__tmp1089 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1102;
    top__DOT__pyrtl_toplevel__DOT__tmp1102 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1107;
    top__DOT__pyrtl_toplevel__DOT__tmp1107 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1110;
    top__DOT__pyrtl_toplevel__DOT__tmp1110 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1122;
    top__DOT__pyrtl_toplevel__DOT__tmp1122 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1144;
    top__DOT__pyrtl_toplevel__DOT__tmp1144 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1177;
    top__DOT__pyrtl_toplevel__DOT__tmp1177 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1246;
    top__DOT__pyrtl_toplevel__DOT__tmp1246 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1312;
    top__DOT__pyrtl_toplevel__DOT__tmp1312 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1460;
    top__DOT__pyrtl_toplevel__DOT__tmp1460 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1475;
    top__DOT__pyrtl_toplevel__DOT__tmp1475 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1513;
    top__DOT__pyrtl_toplevel__DOT__tmp1513 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1587;
    top__DOT__pyrtl_toplevel__DOT__tmp1587 = 0;
    SData/*9:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1594;
    top__DOT__pyrtl_toplevel__DOT__tmp1594 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1690;
    top__DOT__pyrtl_toplevel__DOT__tmp1690 = 0;
    SData/*9:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1719;
    top__DOT__pyrtl_toplevel__DOT__tmp1719 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1785;
    top__DOT__pyrtl_toplevel__DOT__tmp1785 = 0;
    SData/*9:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1844;
    top__DOT__pyrtl_toplevel__DOT__tmp1844 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1942;
    top__DOT__pyrtl_toplevel__DOT__tmp1942 = 0;
    SData/*9:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1969;
    top__DOT__pyrtl_toplevel__DOT__tmp1969 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp1995;
    top__DOT__pyrtl_toplevel__DOT__tmp1995 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2058;
    top__DOT__pyrtl_toplevel__DOT__tmp2058 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2070;
    top__DOT__pyrtl_toplevel__DOT__tmp2070 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2115;
    top__DOT__pyrtl_toplevel__DOT__tmp2115 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2139;
    top__DOT__pyrtl_toplevel__DOT__tmp2139 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2248;
    top__DOT__pyrtl_toplevel__DOT__tmp2248 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2310;
    top__DOT__pyrtl_toplevel__DOT__tmp2310 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2455;
    top__DOT__pyrtl_toplevel__DOT__tmp2455 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2512;
    top__DOT__pyrtl_toplevel__DOT__tmp2512 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2519;
    top__DOT__pyrtl_toplevel__DOT__tmp2519 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2631;
    top__DOT__pyrtl_toplevel__DOT__tmp2631 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2725;
    top__DOT__pyrtl_toplevel__DOT__tmp2725 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2753;
    top__DOT__pyrtl_toplevel__DOT__tmp2753 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2775;
    top__DOT__pyrtl_toplevel__DOT__tmp2775 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2800;
    top__DOT__pyrtl_toplevel__DOT__tmp2800 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2858;
    top__DOT__pyrtl_toplevel__DOT__tmp2858 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2880;
    top__DOT__pyrtl_toplevel__DOT__tmp2880 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2895;
    top__DOT__pyrtl_toplevel__DOT__tmp2895 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp2984;
    top__DOT__pyrtl_toplevel__DOT__tmp2984 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3020;
    top__DOT__pyrtl_toplevel__DOT__tmp3020 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3062;
    top__DOT__pyrtl_toplevel__DOT__tmp3062 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3083;
    top__DOT__pyrtl_toplevel__DOT__tmp3083 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3134;
    top__DOT__pyrtl_toplevel__DOT__tmp3134 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3150;
    top__DOT__pyrtl_toplevel__DOT__tmp3150 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3267;
    top__DOT__pyrtl_toplevel__DOT__tmp3267 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3296;
    top__DOT__pyrtl_toplevel__DOT__tmp3296 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3314;
    top__DOT__pyrtl_toplevel__DOT__tmp3314 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3368;
    top__DOT__pyrtl_toplevel__DOT__tmp3368 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3370;
    top__DOT__pyrtl_toplevel__DOT__tmp3370 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3402;
    top__DOT__pyrtl_toplevel__DOT__tmp3402 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3442;
    top__DOT__pyrtl_toplevel__DOT__tmp3442 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3516;
    top__DOT__pyrtl_toplevel__DOT__tmp3516 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3565;
    top__DOT__pyrtl_toplevel__DOT__tmp3565 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3578;
    top__DOT__pyrtl_toplevel__DOT__tmp3578 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3606;
    top__DOT__pyrtl_toplevel__DOT__tmp3606 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3647;
    top__DOT__pyrtl_toplevel__DOT__tmp3647 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3665;
    top__DOT__pyrtl_toplevel__DOT__tmp3665 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3708;
    top__DOT__pyrtl_toplevel__DOT__tmp3708 = 0;
    SData/*10:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3715;
    top__DOT__pyrtl_toplevel__DOT__tmp3715 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3842;
    top__DOT__pyrtl_toplevel__DOT__tmp3842 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp3933;
    top__DOT__pyrtl_toplevel__DOT__tmp3933 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4067;
    top__DOT__pyrtl_toplevel__DOT__tmp4067 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4084;
    top__DOT__pyrtl_toplevel__DOT__tmp4084 = 0;
    SData/*10:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4117;
    top__DOT__pyrtl_toplevel__DOT__tmp4117 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4131;
    top__DOT__pyrtl_toplevel__DOT__tmp4131 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4201;
    top__DOT__pyrtl_toplevel__DOT__tmp4201 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4262;
    top__DOT__pyrtl_toplevel__DOT__tmp4262 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4285;
    top__DOT__pyrtl_toplevel__DOT__tmp4285 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4409;
    top__DOT__pyrtl_toplevel__DOT__tmp4409 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4422;
    top__DOT__pyrtl_toplevel__DOT__tmp4422 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4466;
    top__DOT__pyrtl_toplevel__DOT__tmp4466 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4499;
    top__DOT__pyrtl_toplevel__DOT__tmp4499 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4526;
    top__DOT__pyrtl_toplevel__DOT__tmp4526 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4543;
    top__DOT__pyrtl_toplevel__DOT__tmp4543 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4577;
    top__DOT__pyrtl_toplevel__DOT__tmp4577 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4604;
    top__DOT__pyrtl_toplevel__DOT__tmp4604 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4655;
    top__DOT__pyrtl_toplevel__DOT__tmp4655 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4682;
    top__DOT__pyrtl_toplevel__DOT__tmp4682 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4733;
    top__DOT__pyrtl_toplevel__DOT__tmp4733 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4760;
    top__DOT__pyrtl_toplevel__DOT__tmp4760 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4773;
    top__DOT__pyrtl_toplevel__DOT__tmp4773 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4872;
    top__DOT__pyrtl_toplevel__DOT__tmp4872 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4875;
    top__DOT__pyrtl_toplevel__DOT__tmp4875 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp4898;
    top__DOT__pyrtl_toplevel__DOT__tmp4898 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5002;
    top__DOT__pyrtl_toplevel__DOT__tmp5002 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5077;
    top__DOT__pyrtl_toplevel__DOT__tmp5077 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5141;
    top__DOT__pyrtl_toplevel__DOT__tmp5141 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5181;
    top__DOT__pyrtl_toplevel__DOT__tmp5181 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5235;
    top__DOT__pyrtl_toplevel__DOT__tmp5235 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5426;
    top__DOT__pyrtl_toplevel__DOT__tmp5426 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5441;
    top__DOT__pyrtl_toplevel__DOT__tmp5441 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5465;
    top__DOT__pyrtl_toplevel__DOT__tmp5465 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5478;
    top__DOT__pyrtl_toplevel__DOT__tmp5478 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5490;
    top__DOT__pyrtl_toplevel__DOT__tmp5490 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5505;
    top__DOT__pyrtl_toplevel__DOT__tmp5505 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5556;
    top__DOT__pyrtl_toplevel__DOT__tmp5556 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5611;
    top__DOT__pyrtl_toplevel__DOT__tmp5611 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5623;
    top__DOT__pyrtl_toplevel__DOT__tmp5623 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5638;
    top__DOT__pyrtl_toplevel__DOT__tmp5638 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5665;
    top__DOT__pyrtl_toplevel__DOT__tmp5665 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5690;
    top__DOT__pyrtl_toplevel__DOT__tmp5690 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5745;
    top__DOT__pyrtl_toplevel__DOT__tmp5745 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5772;
    top__DOT__pyrtl_toplevel__DOT__tmp5772 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5812;
    top__DOT__pyrtl_toplevel__DOT__tmp5812 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5824;
    top__DOT__pyrtl_toplevel__DOT__tmp5824 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5841;
    top__DOT__pyrtl_toplevel__DOT__tmp5841 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5879;
    top__DOT__pyrtl_toplevel__DOT__tmp5879 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5891;
    top__DOT__pyrtl_toplevel__DOT__tmp5891 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5906;
    top__DOT__pyrtl_toplevel__DOT__tmp5906 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5933;
    top__DOT__pyrtl_toplevel__DOT__tmp5933 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5946;
    top__DOT__pyrtl_toplevel__DOT__tmp5946 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5958;
    top__DOT__pyrtl_toplevel__DOT__tmp5958 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp5986;
    top__DOT__pyrtl_toplevel__DOT__tmp5986 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6061;
    top__DOT__pyrtl_toplevel__DOT__tmp6061 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6159;
    top__DOT__pyrtl_toplevel__DOT__tmp6159 = 0;
    SData/*10:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6223;
    top__DOT__pyrtl_toplevel__DOT__tmp6223 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6237;
    top__DOT__pyrtl_toplevel__DOT__tmp6237 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6344;
    top__DOT__pyrtl_toplevel__DOT__tmp6344 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6364;
    top__DOT__pyrtl_toplevel__DOT__tmp6364 = 0;
    SData/*10:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6371;
    top__DOT__pyrtl_toplevel__DOT__tmp6371 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6385;
    top__DOT__pyrtl_toplevel__DOT__tmp6385 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6425;
    top__DOT__pyrtl_toplevel__DOT__tmp6425 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6504;
    top__DOT__pyrtl_toplevel__DOT__tmp6504 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6512;
    top__DOT__pyrtl_toplevel__DOT__tmp6512 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6641;
    top__DOT__pyrtl_toplevel__DOT__tmp6641 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6654;
    top__DOT__pyrtl_toplevel__DOT__tmp6654 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6738;
    top__DOT__pyrtl_toplevel__DOT__tmp6738 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6750;
    top__DOT__pyrtl_toplevel__DOT__tmp6750 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6807;
    top__DOT__pyrtl_toplevel__DOT__tmp6807 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6816;
    top__DOT__pyrtl_toplevel__DOT__tmp6816 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6851;
    top__DOT__pyrtl_toplevel__DOT__tmp6851 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6865;
    top__DOT__pyrtl_toplevel__DOT__tmp6865 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6929;
    top__DOT__pyrtl_toplevel__DOT__tmp6929 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6971;
    top__DOT__pyrtl_toplevel__DOT__tmp6971 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp6991;
    top__DOT__pyrtl_toplevel__DOT__tmp6991 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7034;
    top__DOT__pyrtl_toplevel__DOT__tmp7034 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7041;
    top__DOT__pyrtl_toplevel__DOT__tmp7041 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7050;
    top__DOT__pyrtl_toplevel__DOT__tmp7050 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7078;
    top__DOT__pyrtl_toplevel__DOT__tmp7078 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7082;
    top__DOT__pyrtl_toplevel__DOT__tmp7082 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7094;
    top__DOT__pyrtl_toplevel__DOT__tmp7094 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7123;
    top__DOT__pyrtl_toplevel__DOT__tmp7123 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7135;
    top__DOT__pyrtl_toplevel__DOT__tmp7135 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7160;
    top__DOT__pyrtl_toplevel__DOT__tmp7160 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7164;
    top__DOT__pyrtl_toplevel__DOT__tmp7164 = 0;
    SData/*8:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7176;
    top__DOT__pyrtl_toplevel__DOT__tmp7176 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7189;
    top__DOT__pyrtl_toplevel__DOT__tmp7189 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7248;
    top__DOT__pyrtl_toplevel__DOT__tmp7248 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7292;
    top__DOT__pyrtl_toplevel__DOT__tmp7292 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7373;
    top__DOT__pyrtl_toplevel__DOT__tmp7373 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7393;
    top__DOT__pyrtl_toplevel__DOT__tmp7393 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7407;
    top__DOT__pyrtl_toplevel__DOT__tmp7407 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7449;
    top__DOT__pyrtl_toplevel__DOT__tmp7449 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7525;
    top__DOT__pyrtl_toplevel__DOT__tmp7525 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7619;
    top__DOT__pyrtl_toplevel__DOT__tmp7619 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7640;
    top__DOT__pyrtl_toplevel__DOT__tmp7640 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7865;
    top__DOT__pyrtl_toplevel__DOT__tmp7865 = 0;
    CData/*0:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7866;
    top__DOT__pyrtl_toplevel__DOT__tmp7866 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7870;
    top__DOT__pyrtl_toplevel__DOT__tmp7870 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7874;
    top__DOT__pyrtl_toplevel__DOT__tmp7874 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7878;
    top__DOT__pyrtl_toplevel__DOT__tmp7878 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7882;
    top__DOT__pyrtl_toplevel__DOT__tmp7882 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7886;
    top__DOT__pyrtl_toplevel__DOT__tmp7886 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7890;
    top__DOT__pyrtl_toplevel__DOT__tmp7890 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7894;
    top__DOT__pyrtl_toplevel__DOT__tmp7894 = 0;
    CData/*7:0*/ top__DOT__pyrtl_toplevel__DOT__tmp7898;
    top__DOT__pyrtl_toplevel__DOT__tmp7898 = 0;
    SData/*9:0*/ top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_39;
    top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_39 = 0;
    SData/*9:0*/ top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_40;
    top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_40 = 0;
    SData/*9:0*/ top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_42;
    top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_42 = 0;
    SData/*9:0*/ top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_43;
    top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_43 = 0;
    SData/*9:0*/ top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_45;
    top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_45 = 0;
    SData/*9:0*/ top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_46;
    top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_46 = 0;
    SData/*9:0*/ top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_48;
    top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_48 = 0;
    SData/*9:0*/ top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_49;
    top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_49 = 0;
    CData/*0:0*/ __VdfgRegularize_hd87f99a1_0_0;
    __VdfgRegularize_hd87f99a1_0_0 = 0;
    // Body
    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__my_calculator_out_z 
        = vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7861;
    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp18 
        = vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7847;
    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13 
        = vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7763;
    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12 
        = vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7746;
    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11 
        = vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7728;
    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17 
        = vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7831;
    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__was_toggled 
        = ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp5) 
           != (1U & (vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp0 
                     >> 1U)));
    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10 
        = vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7710;
    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16 
        = vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7815;
    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15 
        = vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7798;
    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14 
        = vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7781;
    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899 
        = vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7923;
    vlSelfRef.rgb0 = (0U == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__my_calculator_out_z));
    vlSelfRef.rgb1 = ((1U == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__my_calculator_out_z)) 
                      | (0xfU == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__my_calculator_out_z)));
    vlSelfRef.rgb2 = ((4U == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__my_calculator_out_z)) 
                      | (0xfU == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__my_calculator_out_z)));
    top__DOT__pyrtl_toplevel__DOT__tmp676 = (1U & (
                                                   (~ 
                                                    ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13) 
                                                     >> 7U)) 
                                                   ^ 
                                                   (~ 
                                                    (1U 
                                                     & ((- (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13)) 
                                                        >> 8U)))));
    top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_45 
        = ((0x100U & ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13) 
                      << 1U)) | (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13));
    top__DOT__pyrtl_toplevel__DOT__tmp2519 = ((0x80U 
                                               == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13))
                                               ? 0x7fU
                                               : (0x1ffU 
                                                  & (- (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13))));
    top__DOT__pyrtl_toplevel__DOT__tmp1785 = (1U & 
                                              (~ (1U 
                                                  ^ 
                                                  ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13) 
                                                   >> 7U))));
    top__DOT__pyrtl_toplevel__DOT__tmp555 = (1U & (
                                                   (~ 
                                                    ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12) 
                                                     >> 7U)) 
                                                   ^ 
                                                   (~ 
                                                    (1U 
                                                     & ((- (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12)) 
                                                        >> 8U)))));
    top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_48 
        = ((0x100U & ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12) 
                      << 1U)) | (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12));
    top__DOT__pyrtl_toplevel__DOT__tmp2880 = ((0x80U 
                                               == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12))
                                               ? 0x7fU
                                               : (0x1ffU 
                                                  & (- (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12))));
    top__DOT__pyrtl_toplevel__DOT__tmp2248 = (1U & 
                                              (~ (1U 
                                                  ^ 
                                                  ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12) 
                                                   >> 7U))));
    top__DOT__pyrtl_toplevel__DOT__tmp217 = (1U & (
                                                   (~ 
                                                    ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11) 
                                                     >> 7U)) 
                                                   ^ 
                                                   (~ 
                                                    (1U 
                                                     & ((- (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11)) 
                                                        >> 8U)))));
    top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_46 
        = ((0x100U & ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11) 
                      << 1U)) | (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11));
    top__DOT__pyrtl_toplevel__DOT__tmp2858 = ((0x80U 
                                               == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11))
                                               ? 0x7fU
                                               : (0x1ffU 
                                                  & (- (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11))));
    top__DOT__pyrtl_toplevel__DOT__tmp242 = (1U & (~ 
                                                   (1U 
                                                    ^ 
                                                    ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11) 
                                                     >> 7U))));
    top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_39 
        = ((0x100U & ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17) 
                      << 1U)) | (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17));
    top__DOT__pyrtl_toplevel__DOT__tmp1995 = (1U & 
                                              ((~ ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17) 
                                                   >> 7U)) 
                                               ^ (~ 
                                                  (1U 
                                                   & ((- (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17)) 
                                                      >> 8U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp6851 = ((0x80U 
                                               == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17))
                                               ? 0x7fU
                                               : (0x1ffU 
                                                  & (- (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17))));
    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp5 = 
        (1U & (vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp0 
               >> 1U));
    top__DOT__pyrtl_toplevel__DOT__tmp150 = (1U & (
                                                   (~ 
                                                    ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10) 
                                                     >> 7U)) 
                                                   ^ 
                                                   (~ 
                                                    (1U 
                                                     & ((- (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10)) 
                                                        >> 8U)))));
    top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_49 
        = ((0x100U & ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10) 
                      << 1U)) | (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10));
    top__DOT__pyrtl_toplevel__DOT__tmp7034 = ((0x80U 
                                               == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10))
                                               ? 0x7fU
                                               : (0x1ffU 
                                                  & (- (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10))));
    top__DOT__pyrtl_toplevel__DOT__tmp583 = (1U & (~ 
                                                   (1U 
                                                    ^ 
                                                    ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10) 
                                                     >> 7U))));
    top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_42 
        = ((0x100U & ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16) 
                      << 1U)) | (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16));
    top__DOT__pyrtl_toplevel__DOT__tmp797 = (1U & (
                                                   (~ 
                                                    ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16) 
                                                     >> 7U)) 
                                                   ^ 
                                                   (~ 
                                                    (1U 
                                                     & ((- (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16)) 
                                                        >> 8U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp6816 = ((0x80U 
                                               == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16))
                                               ? 0x7fU
                                               : (0x1ffU 
                                                  & (- (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16))));
    top__DOT__pyrtl_toplevel__DOT__tmp837 = (1U & (~ 
                                                   (1U 
                                                    ^ 
                                                    ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16) 
                                                     >> 7U))));
    top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_40 
        = ((0x100U & ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15) 
                      << 1U)) | (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15));
    top__DOT__pyrtl_toplevel__DOT__tmp7407 = (1U & 
                                              ((~ ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15) 
                                                   >> 7U)) 
                                               ^ (~ 
                                                  (1U 
                                                   & ((- (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15)) 
                                                      >> 8U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp1089 = ((0x80U 
                                               == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15))
                                               ? 0x7fU
                                               : (0x1ffU 
                                                  & (- (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15))));
    top__DOT__pyrtl_toplevel__DOT__tmp2310 = (1U & 
                                              (~ (1U 
                                                  ^ 
                                                  ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15) 
                                                   >> 7U))));
    top__DOT__pyrtl_toplevel__DOT__tmp284 = (1U & (
                                                   (~ 
                                                    ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14) 
                                                     >> 7U)) 
                                                   ^ 
                                                   (~ 
                                                    (1U 
                                                     & ((- (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14)) 
                                                        >> 8U)))));
    top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_43 
        = ((0x100U & ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14) 
                      << 1U)) | (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14));
    top__DOT__pyrtl_toplevel__DOT__tmp2753 = (((0U 
                                                == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14)) 
                                               & (0U 
                                                  == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15))) 
                                              & ((0U 
                                                  == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16)) 
                                                 & (0U 
                                                    == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17))));
    top__DOT__pyrtl_toplevel__DOT__tmp7050 = ((0x80U 
                                               == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14))
                                               ? 0x7fU
                                               : (0x1ffU 
                                                  & (- (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14))));
    top__DOT__pyrtl_toplevel__DOT__tmp2631 = (1U & 
                                              (~ (1U 
                                                  ^ 
                                                  ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14) 
                                                   >> 7U))));
    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7923 
        = (0x1fU & ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__was_toggled)
                     ? ((IData)(1U) + (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899))
                     : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899)));
    top__DOT__pyrtl_toplevel__DOT__tmp522 = ((4U == 
                                              vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_1
                                              [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]) 
                                             | (5U 
                                                == 
                                                vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_1
                                                [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]));
    top__DOT__pyrtl_toplevel__DOT__tmp1587 = ((4U == 
                                               vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_2
                                               [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]) 
                                              | (5U 
                                                 == 
                                                 vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_2
                                                 [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]));
    top__DOT__pyrtl_toplevel__DOT__tmp411 = ((6U == 
                                              vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_1
                                              [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]) 
                                             | (7U 
                                                == 
                                                vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_1
                                                [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]));
    top__DOT__pyrtl_toplevel__DOT__tmp1460 = ((6U == 
                                               vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_2
                                               [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]) 
                                              | (7U 
                                                 == 
                                                 vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_2
                                                 [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]));
    top__DOT__pyrtl_toplevel__DOT__tmp136 = ((1U == 
                                              vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_1
                                              [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]) 
                                             | ((2U 
                                                 == 
                                                 vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_1
                                                 [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]) 
                                                | (3U 
                                                   == 
                                                   vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_1
                                                   [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899])));
    top__DOT__pyrtl_toplevel__DOT__tmp1177 = ((1U == 
                                               vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_2
                                               [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]) 
                                              | ((2U 
                                                  == 
                                                  vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_2
                                                  [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]) 
                                                 | (3U 
                                                    == 
                                                    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_2
                                                    [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899])));
    top__DOT__pyrtl_toplevel__DOT__tmp89 = (0xfU == 
                                            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_1
                                            [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]);
    top__DOT__pyrtl_toplevel__DOT__tmp1122 = (0xfU 
                                              == vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_2
                                              [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]);
    top__DOT__pyrtl_toplevel__DOT__tmp1110 = (2U == 
                                              vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_0
                                              [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]);
    top__DOT__pyrtl_toplevel__DOT__tmp79 = (1U == vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_0
                                            [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]);
    top__DOT__pyrtl_toplevel__DOT__tmp36 = (4U == vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_0
                                            [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]);
    top__DOT__pyrtl_toplevel__DOT__tmp4285 = ((0U != 
                                               vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_0
                                               [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]) 
                                              & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__was_toggled));
    top__DOT__pyrtl_toplevel__DOT__tmp7160 = ((0x80U 
                                               & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13))
                                               ? (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2519)
                                               : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13));
    top__DOT__pyrtl_toplevel__DOT__tmp1719 = (0x3ffU 
                                              & ((IData)(top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_48) 
                                                 + (IData)(top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_45)));
    top__DOT__pyrtl_toplevel__DOT__tmp6807 = ((0x80U 
                                               & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12))
                                               ? (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2880)
                                               : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12));
    top__DOT__pyrtl_toplevel__DOT__tmp650 = (0x3ffU 
                                             & ((IData)(top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_46) 
                                                + (IData)(top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_45)));
    top__DOT__pyrtl_toplevel__DOT__tmp7078 = ((0x80U 
                                               & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11))
                                               ? (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2858)
                                               : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11));
    top__DOT__pyrtl_toplevel__DOT__tmp7176 = ((0x80U 
                                               & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17))
                                               ? (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6851)
                                               : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17));
    top__DOT__pyrtl_toplevel__DOT__tmp529 = (0x3ffU 
                                             & ((IData)(top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_49) 
                                                + (IData)(top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_48)));
    top__DOT__pyrtl_toplevel__DOT__tmp1594 = (0x3ffU 
                                              & ((IData)(top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_49) 
                                                 + (IData)(top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_46)));
    top__DOT__pyrtl_toplevel__DOT__tmp6738 = ((0x80U 
                                               & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10))
                                               ? (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7034)
                                               : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10));
    top__DOT__pyrtl_toplevel__DOT__tmp192 = (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp583) 
                                              & (((~ 
                                                   (1U 
                                                    & (VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10), 1U) 
                                                       >> 7U))) 
                                                  ^ 
                                                  (~ 
                                                   (1U 
                                                    & ((- 
                                                        (0xffU 
                                                         & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10), 1U))) 
                                                       >> 8U)))) 
                                                 | (0U 
                                                    == 
                                                    (0xffU 
                                                     & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10), 1U)))))
                                              ? 0x80U
                                              : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp150) 
                                                  & (VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10), 1U) 
                                                     >> 7U))
                                                  ? 0x7fU
                                                  : 
                                                 (0xffU 
                                                  & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10), 1U))));
    top__DOT__pyrtl_toplevel__DOT__tmp1969 = (0x3ffU 
                                              & ((IData)(top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_42) 
                                                 + (IData)(top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_39)));
    top__DOT__pyrtl_toplevel__DOT__tmp7135 = ((0x80U 
                                               & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16))
                                               ? (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6816)
                                               : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16));
    top__DOT__pyrtl_toplevel__DOT__tmp7525 = (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp837) 
                                               & (((~ 
                                                    (1U 
                                                     & (VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16), 1U) 
                                                        >> 7U))) 
                                                   ^ 
                                                   (~ 
                                                    (1U 
                                                     & ((- 
                                                         (0xffU 
                                                          & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16), 1U))) 
                                                        >> 8U)))) 
                                                  | (0U 
                                                     == 
                                                     (0xffU 
                                                      & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16), 1U)))))
                                               ? 0x80U
                                               : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp797) 
                                                   & (VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16), 1U) 
                                                      >> 7U))
                                                   ? 0x7fU
                                                   : 
                                                  (0xffU 
                                                   & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16), 1U))));
    top__DOT__pyrtl_toplevel__DOT__tmp892 = (0x3ffU 
                                             & ((IData)(top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_40) 
                                                + (IData)(top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_39)));
    top__DOT__pyrtl_toplevel__DOT__tmp7094 = ((0x80U 
                                               & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15))
                                               ? (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1089)
                                               : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15));
    top__DOT__pyrtl_toplevel__DOT__tmp7449 = (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp2310) 
                                               & (((~ 
                                                    (1U 
                                                     & (VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15), 1U) 
                                                        >> 7U))) 
                                                   ^ 
                                                   (~ 
                                                    (1U 
                                                     & ((- 
                                                         (0xffU 
                                                          & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15), 1U))) 
                                                        >> 8U)))) 
                                                  | (0U 
                                                     == 
                                                     (0xffU 
                                                      & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15), 1U)))))
                                               ? 0x80U
                                               : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7407) 
                                                   & (VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15), 1U) 
                                                      >> 7U))
                                                   ? 0x7fU
                                                   : 
                                                  (0xffU 
                                                   & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15), 1U))));
    top__DOT__pyrtl_toplevel__DOT__tmp771 = (0x3ffU 
                                             & ((IData)(top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_43) 
                                                + (IData)(top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_42)));
    top__DOT__pyrtl_toplevel__DOT__tmp1844 = (0x3ffU 
                                              & ((IData)(top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_43) 
                                                 + (IData)(top__DOT__pyrtl_toplevel__DOT____VdfgRegularize_hca590bbe_0_40)));
    top__DOT__pyrtl_toplevel__DOT__tmp6750 = ((0x80U 
                                               & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14))
                                               ? (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7050)
                                               : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14));
    top__DOT__pyrtl_toplevel__DOT__tmp7373 = (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp2631) 
                                               & (((~ 
                                                    (1U 
                                                     & (VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14), 1U) 
                                                        >> 7U))) 
                                                   ^ 
                                                   (~ 
                                                    (1U 
                                                     & ((- 
                                                         (0xffU 
                                                          & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14), 1U))) 
                                                        >> 8U)))) 
                                                  | (0U 
                                                     == 
                                                     (0xffU 
                                                      & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14), 1U)))))
                                               ? 0x80U
                                               : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp284) 
                                                   & (VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14), 1U) 
                                                      >> 7U))
                                                   ? 0x7fU
                                                   : 
                                                  (0xffU 
                                                   & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14), 1U))));
    top__DOT__pyrtl_toplevel__DOT__tmp2800 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp583) 
                                              == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2631));
    __VdfgRegularize_hd87f99a1_0_0 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp583) 
                                      & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2631));
    top__DOT__pyrtl_toplevel__DOT__tmp44 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4285) 
                                            & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp36));
    top__DOT__pyrtl_toplevel__DOT__tmp2058 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp36)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4285));
    top__DOT__pyrtl_toplevel__DOT__tmp7164 = ((0x100U 
                                               & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7160)) 
                                              | (0xffU 
                                                 & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7160) 
                                                    >> 1U)));
    top__DOT__pyrtl_toplevel__DOT__tmp7123 = ((0x100U 
                                               & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6807)) 
                                              | (0xffU 
                                                 & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6807) 
                                                    >> 1U)));
    top__DOT__pyrtl_toplevel__DOT__tmp7082 = ((0x100U 
                                               & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7078)) 
                                              | (0xffU 
                                                 & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7078) 
                                                    >> 1U)));
    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp0 = vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp4;
    top__DOT__pyrtl_toplevel__DOT__tmp7041 = ((0x100U 
                                               & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6738)) 
                                              | (0xffU 
                                                 & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6738) 
                                                    >> 1U)));
    top__DOT__pyrtl_toplevel__DOT__tmp6865 = (1U & 
                                              ((((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6750) 
                                                   ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6738)) 
                                                  >> 8U) 
                                                 ^ 
                                                 (1U 
                                                  & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6738) 
                                                      - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6750)) 
                                                     >> 9U))) 
                                                & ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7094) 
                                                     ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7078)) 
                                                    >> 8U) 
                                                   ^ 
                                                   (1U 
                                                    & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7078) 
                                                        - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7094)) 
                                                       >> 9U)))) 
                                               & (1U 
                                                  & (((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7135) 
                                                        ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6807)) 
                                                       >> 8U) 
                                                      ^ 
                                                      (1U 
                                                       & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6807) 
                                                           - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7135)) 
                                                          >> 9U))) 
                                                     & ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7176) 
                                                          ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7160)) 
                                                         >> 8U) 
                                                        ^ 
                                                        (1U 
                                                         & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7160) 
                                                             - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7176)) 
                                                            >> 9U)))))));
    top__DOT__pyrtl_toplevel__DOT__tmp399 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp2058) 
                                             & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp79));
    top__DOT__pyrtl_toplevel__DOT__tmp4409 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp79)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2058));
    top__DOT__pyrtl_toplevel__DOT__tmp7189 = ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp18) 
                                              & ((((1U 
                                                    & ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6750) 
                                                         ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6738)) 
                                                        >> 8U) 
                                                       ^ 
                                                       (1U 
                                                        & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6750) 
                                                            - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7041)) 
                                                           >> 9U)))) 
                                                   | ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7041) 
                                                      == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6750))) 
                                                  & ((1U 
                                                      & ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7094) 
                                                           ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7078)) 
                                                          >> 8U) 
                                                         ^ 
                                                         (1U 
                                                          & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7094) 
                                                              - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7082)) 
                                                             >> 9U)))) 
                                                     | ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7082) 
                                                        == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7094)))) 
                                                 & (((1U 
                                                      & ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7135) 
                                                           ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6807)) 
                                                          >> 8U) 
                                                         ^ 
                                                         (1U 
                                                          & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7135) 
                                                              - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7123)) 
                                                             >> 9U)))) 
                                                     | ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7123) 
                                                        == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7135))) 
                                                    & ((1U 
                                                        & ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7176) 
                                                             ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7160)) 
                                                            >> 8U) 
                                                           ^ 
                                                           (1U 
                                                            & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7176) 
                                                                - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7164)) 
                                                               >> 9U)))) 
                                                       | ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7164) 
                                                          == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7176))))));
    top__DOT__pyrtl_toplevel__DOT__tmp471 = ((0U != 
                                              vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_1
                                              [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]) 
                                             & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp399));
    top__DOT__pyrtl_toplevel__DOT__tmp1513 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4409) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1110));
    top__DOT__pyrtl_toplevel__DOT__tmp6971 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1110)) 
                                              & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4409) 
                                                 & (3U 
                                                    == 
                                                    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_0
                                                    [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899])));
    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp4 = 
        (0x7ffffffU & ((IData)(1U) + vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp0));
    top__DOT__pyrtl_toplevel__DOT__tmp107 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp471) 
                                             & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp89));
    top__DOT__pyrtl_toplevel__DOT__tmp1025 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp89)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp471));
    top__DOT__pyrtl_toplevel__DOT__tmp1312 = ((0U != 
                                               vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_2
                                               [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899]) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1513));
    top__DOT__pyrtl_toplevel__DOT__tmp2775 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6971) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2753));
    top__DOT__pyrtl_toplevel__DOT__tmp7866 = ((~ (((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10) 
                                                   | (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11)) 
                                                  | ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12) 
                                                     | (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13)))) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6971));
    top__DOT__pyrtl_toplevel__DOT__tmp6344 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2753)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6971));
    top__DOT__pyrtl_toplevel__DOT__tmp7865 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6971) 
                                              & (((((((~ 
                                                       ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6971) 
                                                        & (((0U 
                                                             == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14)) 
                                                            | (0U 
                                                               == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15))) 
                                                           | ((0U 
                                                               == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16)) 
                                                              | (0U 
                                                                 == (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17)))))) 
                                                      & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp583) 
                                                         == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp242))) 
                                                     & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp242) 
                                                        == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2248))) 
                                                    & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp2248) 
                                                       == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1785))) 
                                                   & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp2631) 
                                                      == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2310))) 
                                                  & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp2310) 
                                                     == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp837))) 
                                                 & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp837) 
                                                    == 
                                                    (1U 
                                                     & ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17) 
                                                        >> 7U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp404 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1025) 
                                             & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp136));
    top__DOT__pyrtl_toplevel__DOT__tmp1102 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp136)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1025));
    top__DOT__pyrtl_toplevel__DOT__tmp1144 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1312) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1122));
    top__DOT__pyrtl_toplevel__DOT__tmp1690 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1122)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1312));
    top__DOT__pyrtl_toplevel__DOT__tmp6991 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7865)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6344));
    top__DOT__pyrtl_toplevel__DOT__tmp6641 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6344) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7865));
    top__DOT__pyrtl_toplevel__DOT__tmp2455 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7865) 
                                              & (IData)(__VdfgRegularize_hd87f99a1_0_0));
    top__DOT__pyrtl_toplevel__DOT__tmp424 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1102) 
                                             & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp411));
    top__DOT__pyrtl_toplevel__DOT__tmp1054 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp411)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1102));
    top__DOT__pyrtl_toplevel__DOT__tmp1246 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1690) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1177));
    top__DOT__pyrtl_toplevel__DOT__tmp1942 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1177)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1690));
    top__DOT__pyrtl_toplevel__DOT__tmp6929 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6991) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6865));
    top__DOT__pyrtl_toplevel__DOT__tmp7292 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6865)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6991));
    top__DOT__pyrtl_toplevel__DOT__tmp2895 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2800)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6641));
    top__DOT__pyrtl_toplevel__DOT__tmp5441 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6641) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2800));
    top__DOT__pyrtl_toplevel__DOT__tmp2512 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6971) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2455));
    top__DOT__pyrtl_toplevel__DOT__tmp2725 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2455)) 
                                              & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6971) 
                                                 & ((~ (IData)(__VdfgRegularize_hd87f99a1_0_0)) 
                                                    & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7865))));
    top__DOT__pyrtl_toplevel__DOT__tmp1107 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp522)) 
                                              & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1054) 
                                                 & (8U 
                                                    == 
                                                    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_1
                                                    [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899])));
    top__DOT__pyrtl_toplevel__DOT__tmp870 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1054) 
                                             & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp522));
    top__DOT__pyrtl_toplevel__DOT__tmp1475 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1942) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1460));
    top__DOT__pyrtl_toplevel__DOT__tmp2139 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1460)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1942));
    top__DOT__pyrtl_toplevel__DOT__tmp7640 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7189)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7292));
    top__DOT__pyrtl_toplevel__DOT__tmp7619 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7292) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7189));
    if (top__DOT__pyrtl_toplevel__DOT__tmp2725) {
        top__DOT__pyrtl_toplevel__DOT__tmp7882 = (0xffU 
                                                  & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13));
        top__DOT__pyrtl_toplevel__DOT__tmp7874 = (0xffU 
                                                  & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11));
        top__DOT__pyrtl_toplevel__DOT__tmp7878 = (0xffU 
                                                  & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12));
        top__DOT__pyrtl_toplevel__DOT__tmp7870 = (0xffU 
                                                  & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10));
        top__DOT__pyrtl_toplevel__DOT__tmp7898 = (0xffU 
                                                  & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17));
        top__DOT__pyrtl_toplevel__DOT__tmp7890 = (0xffU 
                                                  & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15));
        top__DOT__pyrtl_toplevel__DOT__tmp7894 = (0xffU 
                                                  & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16));
        top__DOT__pyrtl_toplevel__DOT__tmp7886 = (0xffU 
                                                  & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp2512) {
        top__DOT__pyrtl_toplevel__DOT__tmp7882 = (0xffU 
                                                  & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2519));
        top__DOT__pyrtl_toplevel__DOT__tmp7874 = (0xffU 
                                                  & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2858));
        top__DOT__pyrtl_toplevel__DOT__tmp7878 = (0xffU 
                                                  & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2880));
        top__DOT__pyrtl_toplevel__DOT__tmp7870 = (0xffU 
                                                  & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7034));
        top__DOT__pyrtl_toplevel__DOT__tmp7898 = (0xffU 
                                                  & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6851));
        top__DOT__pyrtl_toplevel__DOT__tmp7890 = (0xffU 
                                                  & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1089));
        top__DOT__pyrtl_toplevel__DOT__tmp7894 = (0xffU 
                                                  & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6816));
        top__DOT__pyrtl_toplevel__DOT__tmp7886 = (0xffU 
                                                  & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7050));
    } else {
        top__DOT__pyrtl_toplevel__DOT__tmp7882 = (0xffU 
                                                  & 0U);
        top__DOT__pyrtl_toplevel__DOT__tmp7874 = (0xffU 
                                                  & 0U);
        top__DOT__pyrtl_toplevel__DOT__tmp7878 = (0xffU 
                                                  & 0U);
        top__DOT__pyrtl_toplevel__DOT__tmp7870 = (0xffU 
                                                  & 0U);
        top__DOT__pyrtl_toplevel__DOT__tmp7898 = (0xffU 
                                                  & 0U);
        top__DOT__pyrtl_toplevel__DOT__tmp7890 = (0xffU 
                                                  & 0U);
        top__DOT__pyrtl_toplevel__DOT__tmp7894 = (0xffU 
                                                  & 0U);
        top__DOT__pyrtl_toplevel__DOT__tmp7886 = (0xffU 
                                                  & 0U);
    }
    top__DOT__pyrtl_toplevel__DOT__tmp2115 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1587)) 
                                              & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp2139) 
                                                 & (8U 
                                                    == 
                                                    vlSelfRef.top__DOT__pyrtl_toplevel__DOT__mem_2
                                                    [vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7899])));
    top__DOT__pyrtl_toplevel__DOT__tmp2070 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp2139) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1587));
    top__DOT__pyrtl_toplevel__DOT__tmp7248 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7619) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7866));
    top__DOT__pyrtl_toplevel__DOT__tmp7393 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7866)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7619));
    top__DOT__pyrtl_toplevel__DOT__tmp4131 = (1U & 
                                              ((~ ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882) 
                                                   >> 7U)) 
                                               ^ (~ 
                                                  (1U 
                                                   & ((- (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882)) 
                                                      >> 8U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp5891 = (1U & 
                                              (~ (1U 
                                                  ^ 
                                                  ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882) 
                                                   >> 7U))));
    top__DOT__pyrtl_toplevel__DOT__tmp3083 = ((0x80U 
                                               & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882)) 
                                              | (0x7fU 
                                                 & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882) 
                                                    >> 1U)));
    top__DOT__pyrtl_toplevel__DOT__tmp6237 = (1U & 
                                              ((~ ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874) 
                                                   >> 7U)) 
                                               ^ (~ 
                                                  (1U 
                                                   & ((- (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874)) 
                                                      >> 8U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp5623 = (1U & 
                                              (~ (1U 
                                                  ^ 
                                                  ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874) 
                                                   >> 7U))));
    top__DOT__pyrtl_toplevel__DOT__tmp3606 = ((0x80U 
                                               & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874)) 
                                              | (0x7fU 
                                                 & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874) 
                                                    >> 1U)));
    top__DOT__pyrtl_toplevel__DOT__tmp6385 = (1U & 
                                              ((~ ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878) 
                                                   >> 7U)) 
                                               ^ (~ 
                                                  (1U 
                                                   & ((- (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878)) 
                                                      >> 8U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp6425 = (1U & 
                                              (~ (1U 
                                                  ^ 
                                                  ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878) 
                                                   >> 7U))));
    top__DOT__pyrtl_toplevel__DOT__tmp3062 = ((0x80U 
                                               & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878)) 
                                              | (0x7fU 
                                                 & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878) 
                                                    >> 1U)));
    top__DOT__pyrtl_toplevel__DOT__tmp5490 = (1U & 
                                              (~ (1U 
                                                  ^ 
                                                  ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870) 
                                                   >> 7U))));
    top__DOT__pyrtl_toplevel__DOT__tmp5465 = (1U & 
                                              ((~ ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870) 
                                                   >> 7U)) 
                                               ^ (~ 
                                                  (1U 
                                                   & ((- (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870)) 
                                                      >> 8U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp3020 = ((0x80U 
                                               & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870)) 
                                              | (0x7fU 
                                                 & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870) 
                                                    >> 1U)));
    top__DOT__pyrtl_toplevel__DOT__tmp6512 = ((0x80U 
                                               == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898))
                                               ? 0x7fU
                                               : (0x1ffU 
                                                  & (- (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898))));
    top__DOT__pyrtl_toplevel__DOT__tmp5958 = (1U & 
                                              (~ (1U 
                                                  ^ 
                                                  ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898) 
                                                   >> 7U))));
    top__DOT__pyrtl_toplevel__DOT__tmp5933 = (1U & 
                                              ((~ ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898) 
                                                   >> 7U)) 
                                               ^ (~ 
                                                  (1U 
                                                   & ((- (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898)) 
                                                      >> 8U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp3578 = (1U & 
                                              (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898) 
                                                - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882)) 
                                               >> 8U));
    top__DOT__pyrtl_toplevel__DOT__tmp3842 = ((0x80U 
                                               == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890))
                                               ? 0x7fU
                                               : (0x1ffU 
                                                  & (- (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890))));
    top__DOT__pyrtl_toplevel__DOT__tmp5690 = (1U & 
                                              (~ (1U 
                                                  ^ 
                                                  ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890) 
                                                   >> 7U))));
    top__DOT__pyrtl_toplevel__DOT__tmp5665 = (1U & 
                                              ((~ ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890) 
                                                   >> 7U)) 
                                               ^ (~ 
                                                  (1U 
                                                   & ((- (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890)) 
                                                      >> 8U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp4543 = (1U & 
                                              (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890) 
                                                - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874)) 
                                               >> 8U));
    top__DOT__pyrtl_toplevel__DOT__tmp6364 = ((0x80U 
                                               == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894))
                                               ? 0x7fU
                                               : (0x1ffU 
                                                  & (- (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894))));
    top__DOT__pyrtl_toplevel__DOT__tmp3402 = (1U & 
                                              ((~ ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894) 
                                                   >> 7U)) 
                                               ^ (~ 
                                                  (1U 
                                                   & ((- (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894)) 
                                                      >> 8U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp5824 = (1U & 
                                              (~ (1U 
                                                  ^ 
                                                  ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894) 
                                                   >> 7U))));
    top__DOT__pyrtl_toplevel__DOT__tmp3565 = (1U & 
                                              (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894) 
                                                - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878)) 
                                               >> 8U));
    top__DOT__pyrtl_toplevel__DOT__tmp3708 = ((0x80U 
                                               == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886))
                                               ? 0x7fU
                                               : (0x1ffU 
                                                  & (- (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886))));
    top__DOT__pyrtl_toplevel__DOT__tmp4262 = (1U & 
                                              ((((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886) 
                                                   ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870)) 
                                                  >> 7U) 
                                                 ^ 
                                                 (1U 
                                                  & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870) 
                                                      - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886)) 
                                                     >> 8U))) 
                                                & ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890) 
                                                     ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874)) 
                                                    >> 7U) 
                                                   ^ 
                                                   (1U 
                                                    & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874) 
                                                        - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890)) 
                                                       >> 8U)))) 
                                               & (1U 
                                                  & (((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894) 
                                                        ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878)) 
                                                       >> 7U) 
                                                      ^ 
                                                      (1U 
                                                       & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878) 
                                                           - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894)) 
                                                          >> 8U))) 
                                                     & ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898) 
                                                          ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882)) 
                                                         >> 7U) 
                                                        ^ 
                                                        (1U 
                                                         & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882) 
                                                             - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898)) 
                                                            >> 8U)))))));
    top__DOT__pyrtl_toplevel__DOT__tmp5141 = (1U & 
                                              ((~ ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886) 
                                                   >> 7U)) 
                                               ^ (~ 
                                                  (1U 
                                                   & ((- (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886)) 
                                                      >> 8U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp5556 = (1U & 
                                              (~ (1U 
                                                  ^ 
                                                  ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886) 
                                                   >> 7U))));
    top__DOT__pyrtl_toplevel__DOT__tmp4466 = (1U & 
                                              (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886) 
                                                - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870)) 
                                               >> 8U));
    top__DOT__pyrtl_toplevel__DOT__tmp5879 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4131) 
                                              & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882), 1U) 
                                                 >> 7U));
    top__DOT__pyrtl_toplevel__DOT__tmp5906 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5891) 
                                              & (((~ 
                                                   (1U 
                                                    & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882), 1U) 
                                                       >> 7U))) 
                                                  ^ 
                                                  (~ 
                                                   (1U 
                                                    & ((- 
                                                        (0xffU 
                                                         & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882), 1U))) 
                                                       >> 8U)))) 
                                                 | (0U 
                                                    == 
                                                    (0xffU 
                                                     & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882), 1U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp5611 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6237) 
                                              & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874), 1U) 
                                                 >> 7U));
    top__DOT__pyrtl_toplevel__DOT__tmp5638 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5623) 
                                              & (((~ 
                                                   (1U 
                                                    & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874), 1U) 
                                                       >> 7U))) 
                                                  ^ 
                                                  (~ 
                                                   (1U 
                                                    & ((- 
                                                        (0xffU 
                                                         & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874), 1U))) 
                                                       >> 8U)))) 
                                                 | (0U 
                                                    == 
                                                    (0xffU 
                                                     & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874), 1U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp5745 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6385) 
                                              & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878), 1U) 
                                                 >> 7U));
    top__DOT__pyrtl_toplevel__DOT__tmp5772 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6425) 
                                              & (((~ 
                                                   (1U 
                                                    & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878), 1U) 
                                                       >> 7U))) 
                                                  ^ 
                                                  (~ 
                                                   (1U 
                                                    & ((- 
                                                        (0xffU 
                                                         & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878), 1U))) 
                                                       >> 8U)))) 
                                                 | (0U 
                                                    == 
                                                    (0xffU 
                                                     & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878), 1U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp5505 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5490) 
                                              & (((~ 
                                                   (1U 
                                                    & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870), 1U) 
                                                       >> 7U))) 
                                                  ^ 
                                                  (~ 
                                                   (1U 
                                                    & ((- 
                                                        (0xffU 
                                                         & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870), 1U))) 
                                                       >> 8U)))) 
                                                 | (0U 
                                                    == 
                                                    (0xffU 
                                                     & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870), 1U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp5478 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5465) 
                                              & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870), 1U) 
                                                 >> 7U));
    top__DOT__pyrtl_toplevel__DOT__tmp2984 = (1U & 
                                              ((((1U 
                                                  & ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886) 
                                                       ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870)) 
                                                      >> 7U) 
                                                     ^ 
                                                     (1U 
                                                      & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886) 
                                                          - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3020)) 
                                                         >> 8U)))) 
                                                 | ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3020) 
                                                    == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886))) 
                                                & ((1U 
                                                    & ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890) 
                                                         ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874)) 
                                                        >> 7U) 
                                                       ^ 
                                                       (1U 
                                                        & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890) 
                                                            - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3606)) 
                                                           >> 8U)))) 
                                                   | ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3606) 
                                                      == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890)))) 
                                               & (((1U 
                                                    & ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894) 
                                                         ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878)) 
                                                        >> 7U) 
                                                       ^ 
                                                       (1U 
                                                        & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894) 
                                                            - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3062)) 
                                                           >> 8U)))) 
                                                   | ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3062) 
                                                      == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894))) 
                                                  & ((1U 
                                                      & ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898) 
                                                           ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882)) 
                                                          >> 7U) 
                                                         ^ 
                                                         (1U 
                                                          & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898) 
                                                              - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3083)) 
                                                             >> 8U)))) 
                                                     | ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3083) 
                                                        == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898))))));
    top__DOT__pyrtl_toplevel__DOT__tmp4117 = (0x7ffU 
                                              & (((0x300U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882) 
                                                                     >> 7U)))) 
                                                      << 8U)) 
                                                  | (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882)) 
                                                 + 
                                                 ((0x200U 
                                                   & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6512) 
                                                      << 1U)) 
                                                  | (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6512))));
    top__DOT__pyrtl_toplevel__DOT__tmp3516 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5958) 
                                              & (((~ 
                                                   (1U 
                                                    & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898), 1U) 
                                                       >> 7U))) 
                                                  ^ 
                                                  (~ 
                                                   (1U 
                                                    & ((- 
                                                        (0xffU 
                                                         & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898), 1U))) 
                                                       >> 8U)))) 
                                                 | (0U 
                                                    == 
                                                    (0xffU 
                                                     & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898), 1U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp4760 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5958) 
                                              & (((~ 
                                                   (1U 
                                                    & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898), 2U) 
                                                       >> 7U))) 
                                                  ^ 
                                                  (~ 
                                                   (1U 
                                                    & ((- 
                                                        (0xffU 
                                                         & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898), 2U))) 
                                                       >> 8U)))) 
                                                 | (0U 
                                                    == 
                                                    (0xffU 
                                                     & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898), 2U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp5946 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5933) 
                                              & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898), 1U) 
                                                 >> 7U));
    top__DOT__pyrtl_toplevel__DOT__tmp4733 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5933) 
                                              & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898), 2U) 
                                                 >> 7U));
    top__DOT__pyrtl_toplevel__DOT__tmp6223 = (0x7ffU 
                                              & (((0x300U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874) 
                                                                     >> 7U)))) 
                                                      << 8U)) 
                                                  | (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874)) 
                                                 + 
                                                 ((0x200U 
                                                   & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3842) 
                                                      << 1U)) 
                                                  | (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3842))));
    top__DOT__pyrtl_toplevel__DOT__tmp3368 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5690) 
                                              & (((~ 
                                                   (1U 
                                                    & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890), 1U) 
                                                       >> 7U))) 
                                                  ^ 
                                                  (~ 
                                                   (1U 
                                                    & ((- 
                                                        (0xffU 
                                                         & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890), 1U))) 
                                                       >> 8U)))) 
                                                 | (0U 
                                                    == 
                                                    (0xffU 
                                                     & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890), 1U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp4604 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5690) 
                                              & (((~ 
                                                   (1U 
                                                    & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890), 2U) 
                                                       >> 7U))) 
                                                  ^ 
                                                  (~ 
                                                   (1U 
                                                    & ((- 
                                                        (0xffU 
                                                         & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890), 2U))) 
                                                       >> 8U)))) 
                                                 | (0U 
                                                    == 
                                                    (0xffU 
                                                     & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890), 2U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp5235 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5665) 
                                              & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890), 1U) 
                                                 >> 7U));
    top__DOT__pyrtl_toplevel__DOT__tmp4577 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5665) 
                                              & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890), 2U) 
                                                 >> 7U));
    top__DOT__pyrtl_toplevel__DOT__tmp6371 = (0x7ffU 
                                              & (((0x300U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878) 
                                                                     >> 7U)))) 
                                                      << 8U)) 
                                                  | (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878)) 
                                                 + 
                                                 ((0x200U 
                                                   & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6364) 
                                                      << 1U)) 
                                                  | (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6364))));
    top__DOT__pyrtl_toplevel__DOT__tmp5812 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3402) 
                                              & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894), 1U) 
                                                 >> 7U));
    top__DOT__pyrtl_toplevel__DOT__tmp4655 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3402) 
                                              & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894), 2U) 
                                                 >> 7U));
    top__DOT__pyrtl_toplevel__DOT__tmp3442 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5824) 
                                              & (((~ 
                                                   (1U 
                                                    & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894), 1U) 
                                                       >> 7U))) 
                                                  ^ 
                                                  (~ 
                                                   (1U 
                                                    & ((- 
                                                        (0xffU 
                                                         & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894), 1U))) 
                                                       >> 8U)))) 
                                                 | (0U 
                                                    == 
                                                    (0xffU 
                                                     & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894), 1U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp4682 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5824) 
                                              & (((~ 
                                                   (1U 
                                                    & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894), 2U) 
                                                       >> 7U))) 
                                                  ^ 
                                                  (~ 
                                                   (1U 
                                                    & ((- 
                                                        (0xffU 
                                                         & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894), 2U))) 
                                                       >> 8U)))) 
                                                 | (0U 
                                                    == 
                                                    (0xffU 
                                                     & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894), 2U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp3715 = (0x7ffU 
                                              & (((0x300U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870) 
                                                                     >> 7U)))) 
                                                      << 8U)) 
                                                  | (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870)) 
                                                 + 
                                                 ((0x200U 
                                                   & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3708) 
                                                      << 1U)) 
                                                  | (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3708))));
    top__DOT__pyrtl_toplevel__DOT__tmp3267 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5141) 
                                              & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886), 1U) 
                                                 >> 7U));
    top__DOT__pyrtl_toplevel__DOT__tmp4499 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5141) 
                                              & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886), 2U) 
                                                 >> 7U));
    top__DOT__pyrtl_toplevel__DOT__tmp5181 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5556) 
                                              & (((~ 
                                                   (1U 
                                                    & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886), 1U) 
                                                       >> 7U))) 
                                                  ^ 
                                                  (~ 
                                                   (1U 
                                                    & ((- 
                                                        (0xffU 
                                                         & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886), 1U))) 
                                                       >> 8U)))) 
                                                 | (0U 
                                                    == 
                                                    (0xffU 
                                                     & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886), 1U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp4526 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5556) 
                                              & (((~ 
                                                   (1U 
                                                    & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886), 2U) 
                                                       >> 7U))) 
                                                  ^ 
                                                  (~ 
                                                   (1U 
                                                    & ((- 
                                                        (0xffU 
                                                         & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886), 2U))) 
                                                       >> 8U)))) 
                                                 | (0U 
                                                    == 
                                                    (0xffU 
                                                     & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886), 2U)))));
    top__DOT__pyrtl_toplevel__DOT__tmp3647 = (1U & 
                                              ((((IData)(
                                                         ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886) 
                                                            ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870)) 
                                                           >> 7U) 
                                                          ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4466))) 
                                                 | ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870) 
                                                    == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886))) 
                                                & ((IData)(
                                                           ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890) 
                                                              ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874)) 
                                                             >> 7U) 
                                                            ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4543))) 
                                                   | ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874) 
                                                      == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890)))) 
                                               & ((((IData)(
                                                            ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894) 
                                                               ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878)) 
                                                              >> 7U) 
                                                             ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3565))) 
                                                    | ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878) 
                                                       == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894))) 
                                                   & ((IData)(
                                                              ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898) 
                                                                 ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882)) 
                                                                >> 7U) 
                                                               ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3578))) 
                                                      | ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882) 
                                                         == (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898)))) 
                                                  & (((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886) 
                                                        ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870)) 
                                                       >> 7U) 
                                                      ^ 
                                                      (1U 
                                                       & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3020) 
                                                           - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886)) 
                                                          >> 8U))) 
                                                     & (((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890) 
                                                           ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874)) 
                                                          >> 7U) 
                                                         ^ 
                                                         (1U 
                                                          & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3606) 
                                                              - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890)) 
                                                             >> 8U))) 
                                                        & (((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894) 
                                                              ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878)) 
                                                             >> 7U) 
                                                            ^ 
                                                            (1U 
                                                             & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3062) 
                                                                 - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894)) 
                                                                >> 8U))) 
                                                           & ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898) 
                                                                ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882)) 
                                                               >> 7U) 
                                                              ^ 
                                                              (1U 
                                                               & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3083) 
                                                                   - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898)) 
                                                                  >> 8U)))))))));
    top__DOT__pyrtl_toplevel__DOT__tmp3150 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5441) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2984));
    top__DOT__pyrtl_toplevel__DOT__tmp4084 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2984)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5441));
    top__DOT__pyrtl_toplevel__DOT__tmp4201 = (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5891) 
                                               & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6512) 
                                                   >> 8U) 
                                                  & (((~ 
                                                       ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4117) 
                                                        >> 7U)) 
                                                      ^ 
                                                      (~ 
                                                       (1U 
                                                        & ((- 
                                                            (0xffU 
                                                             & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4117))) 
                                                           >> 8U)))) 
                                                     | (0U 
                                                        == 
                                                        (0xffU 
                                                         & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4117))))))
                                               ? 0x80U
                                               : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4131) 
                                                   & (((~ 
                                                        ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6512) 
                                                         >> 8U)) 
                                                       ^ 
                                                       (~ 
                                                        (1U 
                                                         & ((- (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6512)) 
                                                            >> 9U)))) 
                                                      & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4117) 
                                                          >> 7U) 
                                                         | (0U 
                                                            == 
                                                            (0xffU 
                                                             & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4117))))))
                                                   ? 0x7fU
                                                   : 
                                                  (0xffU 
                                                   & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4117))));
    top__DOT__pyrtl_toplevel__DOT__tmp5426 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3516)
                                               ? 0x80U
                                               : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5946)
                                                   ? 0x7fU
                                                   : 
                                                  (0xffU 
                                                   & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898), 1U))));
    top__DOT__pyrtl_toplevel__DOT__tmp3933 = (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5623) 
                                               & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3842) 
                                                   >> 8U) 
                                                  & (((~ 
                                                       ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6223) 
                                                        >> 7U)) 
                                                      ^ 
                                                      (~ 
                                                       (1U 
                                                        & ((- 
                                                            (0xffU 
                                                             & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6223))) 
                                                           >> 8U)))) 
                                                     | (0U 
                                                        == 
                                                        (0xffU 
                                                         & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6223))))))
                                               ? 0x80U
                                               : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6237) 
                                                   & (((~ 
                                                        ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3842) 
                                                         >> 8U)) 
                                                       ^ 
                                                       (~ 
                                                        (1U 
                                                         & ((- (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3842)) 
                                                            >> 9U)))) 
                                                      & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6223) 
                                                          >> 7U) 
                                                         | (0U 
                                                            == 
                                                            (0xffU 
                                                             & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6223))))))
                                                   ? 0x7fU
                                                   : 
                                                  (0xffU 
                                                   & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6223))));
    top__DOT__pyrtl_toplevel__DOT__tmp3370 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3368)
                                               ? 0x80U
                                               : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5235)
                                                   ? 0x7fU
                                                   : 
                                                  (0xffU 
                                                   & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890), 1U))));
    top__DOT__pyrtl_toplevel__DOT__tmp4067 = (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6425) 
                                               & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6364) 
                                                   >> 8U) 
                                                  & (((~ 
                                                       ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6371) 
                                                        >> 7U)) 
                                                      ^ 
                                                      (~ 
                                                       (1U 
                                                        & ((- 
                                                            (0xffU 
                                                             & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6371))) 
                                                           >> 8U)))) 
                                                     | (0U 
                                                        == 
                                                        (0xffU 
                                                         & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6371))))))
                                               ? 0x80U
                                               : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6385) 
                                                   & (((~ 
                                                        ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6364) 
                                                         >> 8U)) 
                                                       ^ 
                                                       (~ 
                                                        (1U 
                                                         & ((- (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6364)) 
                                                            >> 9U)))) 
                                                      & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6371) 
                                                          >> 7U) 
                                                         | (0U 
                                                            == 
                                                            (0xffU 
                                                             & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6371))))))
                                                   ? 0x7fU
                                                   : 
                                                  (0xffU 
                                                   & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6371))));
    top__DOT__pyrtl_toplevel__DOT__tmp5841 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3442)
                                               ? 0x80U
                                               : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5812)
                                                   ? 0x7fU
                                                   : 
                                                  (0xffU 
                                                   & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894), 1U))));
    top__DOT__pyrtl_toplevel__DOT__tmp6159 = (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5490) 
                                               & ((~ 
                                                   (1U 
                                                    ^ 
                                                    ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3708) 
                                                     >> 8U))) 
                                                  & (((~ 
                                                       ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3715) 
                                                        >> 7U)) 
                                                      ^ 
                                                      (~ 
                                                       (1U 
                                                        & ((- 
                                                            (0xffU 
                                                             & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3715))) 
                                                           >> 8U)))) 
                                                     | (0U 
                                                        == 
                                                        (0xffU 
                                                         & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3715))))))
                                               ? 0x80U
                                               : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5465) 
                                                   & (((~ 
                                                        ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3708) 
                                                         >> 8U)) 
                                                       ^ 
                                                       (~ 
                                                        (1U 
                                                         & ((- (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3708)) 
                                                            >> 9U)))) 
                                                      & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3715) 
                                                          >> 7U) 
                                                         | (0U 
                                                            == 
                                                            (0xffU 
                                                             & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3715))))))
                                                   ? 0x7fU
                                                   : 
                                                  (0xffU 
                                                   & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3715))));
    top__DOT__pyrtl_toplevel__DOT__tmp3296 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5181)
                                               ? 0x80U
                                               : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3267)
                                                   ? 0x7fU
                                                   : 
                                                  (0xffU 
                                                   & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886), 1U))));
    top__DOT__pyrtl_toplevel__DOT__tmp4773 = (1U & 
                                              (((IData)(
                                                        ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870) 
                                                           ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886)) 
                                                          >> 7U) 
                                                         ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4466))) 
                                                & ((~ 
                                                    ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4526) 
                                                     | (1U 
                                                        & ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4499)) 
                                                           & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886), 2U) 
                                                              >> 7U))))) 
                                                   ^ 
                                                   ((~ 
                                                     ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870) 
                                                      >> 7U)) 
                                                    ^ 
                                                    (1U 
                                                     & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870) 
                                                         - 
                                                         ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4526)
                                                           ? 0x80U
                                                           : 
                                                          ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4499)
                                                            ? 0x7fU
                                                            : 
                                                           (0xffU 
                                                            & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886), 2U))))) 
                                                        >> 8U))))) 
                                               & (((IData)(
                                                           ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874) 
                                                              ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890)) 
                                                             >> 7U) 
                                                            ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4543))) 
                                                   & ((~ 
                                                       ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4604) 
                                                        | (1U 
                                                           & ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4577)) 
                                                              & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890), 2U) 
                                                                 >> 7U))))) 
                                                      ^ 
                                                      ((~ 
                                                        ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874) 
                                                         >> 7U)) 
                                                       ^ 
                                                       (1U 
                                                        & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874) 
                                                            - 
                                                            ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4604)
                                                              ? 0x80U
                                                              : 
                                                             ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4577)
                                                               ? 0x7fU
                                                               : 
                                                              (0xffU 
                                                               & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890), 2U))))) 
                                                           >> 8U))))) 
                                                  & ((IData)(
                                                             ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878) 
                                                                ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894)) 
                                                               >> 7U) 
                                                              ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3565))) 
                                                     & (((~ 
                                                          ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4682) 
                                                           | (1U 
                                                              & ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4655)) 
                                                                 & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894), 2U) 
                                                                    >> 7U))))) 
                                                         ^ 
                                                         ((~ 
                                                           ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878) 
                                                            >> 7U)) 
                                                          ^ 
                                                          (1U 
                                                           & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878) 
                                                               - 
                                                               ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4682)
                                                                 ? 0x80U
                                                                 : 
                                                                ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4655)
                                                                  ? 0x7fU
                                                                  : 
                                                                 (0xffU 
                                                                  & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894), 2U))))) 
                                                              >> 8U)))) 
                                                        & ((IData)(
                                                                   ((((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882) 
                                                                      ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898)) 
                                                                     >> 7U) 
                                                                    ^ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3578))) 
                                                           & ((~ 
                                                               ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4760) 
                                                                | (1U 
                                                                   & ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4733)) 
                                                                      & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898), 2U) 
                                                                         >> 7U))))) 
                                                              ^ 
                                                              ((~ 
                                                                ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882) 
                                                                 >> 7U)) 
                                                               ^ 
                                                               (1U 
                                                                & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882) 
                                                                    - 
                                                                    ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4760)
                                                                      ? 0x80U
                                                                      : 
                                                                     ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4733)
                                                                       ? 0x7fU
                                                                       : 
                                                                      (0xffU 
                                                                       & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898), 2U))))) 
                                                                   >> 8U))))))))));
    top__DOT__pyrtl_toplevel__DOT__tmp3134 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3150) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7866));
    top__DOT__pyrtl_toplevel__DOT__tmp3314 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7866)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3150));
    top__DOT__pyrtl_toplevel__DOT__tmp3665 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4084) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3647));
    top__DOT__pyrtl_toplevel__DOT__tmp4898 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3647)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4084));
    top__DOT__pyrtl_toplevel__DOT__tmp5986 = (1U & 
                                              ((((~ 
                                                  ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5505) 
                                                   | (1U 
                                                      & ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5478)) 
                                                         & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870), 1U) 
                                                            >> 7U))))) 
                                                 ^ 
                                                 ((~ 
                                                   ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886) 
                                                    >> 7U)) 
                                                  ^ 
                                                  (1U 
                                                   & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886) 
                                                       - 
                                                       ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5505)
                                                         ? 0x80U
                                                         : 
                                                        ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5478)
                                                          ? 0x7fU
                                                          : 
                                                         (0xffU 
                                                          & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870), 1U))))) 
                                                      >> 8U)))) 
                                                & ((~ 
                                                    ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5181) 
                                                     | (1U 
                                                        & ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3267)) 
                                                           & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886), 1U) 
                                                              >> 7U))))) 
                                                   ^ 
                                                   ((~ 
                                                     ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870) 
                                                      >> 7U)) 
                                                    ^ 
                                                    (1U 
                                                     & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870) 
                                                         - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3296)) 
                                                        >> 8U))))) 
                                               & ((((~ 
                                                     ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5638) 
                                                      | (1U 
                                                         & ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5611)) 
                                                            & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874), 1U) 
                                                               >> 7U))))) 
                                                    ^ 
                                                    ((~ 
                                                      ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890) 
                                                       >> 7U)) 
                                                     ^ 
                                                     (1U 
                                                      & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890) 
                                                          - 
                                                          ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5638)
                                                            ? 0x80U
                                                            : 
                                                           ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5611)
                                                             ? 0x7fU
                                                             : 
                                                            (0xffU 
                                                             & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874), 1U))))) 
                                                         >> 8U)))) 
                                                   & ((~ 
                                                       ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3368) 
                                                        | (1U 
                                                           & ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5235)) 
                                                              & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890), 1U) 
                                                                 >> 7U))))) 
                                                      ^ 
                                                      ((~ 
                                                        ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874) 
                                                         >> 7U)) 
                                                       ^ 
                                                       (1U 
                                                        & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874) 
                                                            - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3370)) 
                                                           >> 8U))))) 
                                                  & (((~ 
                                                       ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5772) 
                                                        | (1U 
                                                           & ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5745)) 
                                                              & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878), 1U) 
                                                                 >> 7U))))) 
                                                      ^ 
                                                      ((~ 
                                                        ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894) 
                                                         >> 7U)) 
                                                       ^ 
                                                       (1U 
                                                        & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894) 
                                                            - 
                                                            ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5772)
                                                              ? 0x80U
                                                              : 
                                                             ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5745)
                                                               ? 0x7fU
                                                               : 
                                                              (0xffU 
                                                               & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878), 1U))))) 
                                                           >> 8U)))) 
                                                     & (((~ 
                                                          ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3442) 
                                                           | (1U 
                                                              & ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5812)) 
                                                                 & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894), 1U) 
                                                                    >> 7U))))) 
                                                         ^ 
                                                         ((~ 
                                                           ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878) 
                                                            >> 7U)) 
                                                          ^ 
                                                          (1U 
                                                           & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878) 
                                                               - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5841)) 
                                                              >> 8U)))) 
                                                        & (((~ 
                                                             ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5906) 
                                                              | (1U 
                                                                 & ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5879)) 
                                                                    & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882), 1U) 
                                                                       >> 7U))))) 
                                                            ^ 
                                                            ((~ 
                                                              ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898) 
                                                               >> 7U)) 
                                                             ^ 
                                                             (1U 
                                                              & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898) 
                                                                  - 
                                                                  ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5906)
                                                                    ? 0x80U
                                                                    : 
                                                                   ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5879)
                                                                     ? 0x7fU
                                                                     : 
                                                                    (0xffU 
                                                                     & VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882), 1U))))) 
                                                                 >> 8U)))) 
                                                           & ((~ 
                                                               ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3516) 
                                                                | (1U 
                                                                   & ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5946)) 
                                                                      & (VL_SHIFTL_III(8,8,32, (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898), 1U) 
                                                                         >> 7U))))) 
                                                              ^ 
                                                              ((~ 
                                                                ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882) 
                                                                 >> 7U)) 
                                                               ^ 
                                                               (1U 
                                                                & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882) 
                                                                    - (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5426)) 
                                                                   >> 8U))))))))));
    top__DOT__pyrtl_toplevel__DOT__tmp4422 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4898) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4262));
    top__DOT__pyrtl_toplevel__DOT__tmp4872 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4262)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4898));
    top__DOT__pyrtl_toplevel__DOT__tmp6504 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4773)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4872));
    top__DOT__pyrtl_toplevel__DOT__tmp5002 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4872) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4773));
    top__DOT__pyrtl_toplevel__DOT__tmp6654 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5986)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6504));
    top__DOT__pyrtl_toplevel__DOT__tmp6061 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6504) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5986));
    top__DOT__pyrtl_toplevel__DOT__tmp4875 = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5002) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7866));
    top__DOT__pyrtl_toplevel__DOT__tmp5077 = ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7866)) 
                                              & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5002));
    if (top__DOT__pyrtl_toplevel__DOT__tmp7640) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7861 = 0U;
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7847 
            = vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp18;
    } else {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7861 
            = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7619)
                ? 3U : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6929)
                         ? 7U : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6654)
                                  ? 0U : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6061)
                                           ? 5U : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp5002)
                                                    ? 2U
                                                    : 
                                                   ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp4422)
                                                     ? 6U
                                                     : 
                                                    ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3665)
                                                      ? 4U
                                                      : 
                                                     ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp3150)
                                                       ? 1U
                                                       : 
                                                      ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp2895)
                                                        ? 8U
                                                        : 
                                                       ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp2775)
                                                         ? 0xfU
                                                         : 
                                                        ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp44)
                                                          ? 0U
                                                          : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__my_calculator_out_z))))))))))));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7847 
            = ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7619) 
               | ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6929) 
                  | ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6654)) 
                     & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp6061) 
                        | ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5002)) 
                           & ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4422)) 
                              & ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3665)) 
                                 & ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3150)) 
                                    & ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2895)) 
                                       & ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2775)) 
                                          & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1513)
                                              ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp18)
                                              : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp399)
                                                  ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp18)
                                                  : 
                                                 ((~ (IData)(top__DOT__pyrtl_toplevel__DOT__tmp44)) 
                                                  & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp18))))))))))))));
    }
    if (top__DOT__pyrtl_toplevel__DOT__tmp7248) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7763 
            = (0xffU & ((0x80U & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13)) 
                        | (0x7fU & ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13) 
                                    >> 1U))));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7728 
            = (0xffU & ((0x80U & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11)) 
                        | (0x7fU & ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11) 
                                    >> 1U))));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7746 
            = (0xffU & ((0x80U & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12)) 
                        | (0x7fU & ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12) 
                                    >> 1U))));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7710 
            = (0xffU & ((0x80U & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10)) 
                        | (0x7fU & ((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10) 
                                    >> 1U))));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp6929) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7763 
            = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7728 
            = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7746 
            = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7710 
            = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp6061) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7763 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7728 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7746 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7710 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp5077) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7763 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7728 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7746 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7710 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp4875) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7763 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3083));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7728 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3606));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7746 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3062));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7710 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3020));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp4422) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7763 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7728 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7746 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7710 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp3665) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7763 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7728 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7746 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7710 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp3314) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7763 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7728 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7746 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7710 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp3134) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7763 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3083));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7728 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3606));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7746 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3062));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7710 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3020));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp2895) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7763 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2519));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7728 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2858));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7746 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2880));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7710 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7034));
    } else {
        if (top__DOT__pyrtl_toplevel__DOT__tmp2070) {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7763 
                = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7728 
                = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10));
        } else if (top__DOT__pyrtl_toplevel__DOT__tmp1475) {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7763 
                = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7728 
                = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10));
        } else if (top__DOT__pyrtl_toplevel__DOT__tmp1144) {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7763 
                = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7728 
                = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10));
        } else {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7763 
                = (0xffU & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp870)
                             ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11)
                             : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp424)
                                 ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11)
                                 : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp107)
                                     ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11)
                                     : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp44)
                                         ? 0U : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13))))));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7728 
                = (0xffU & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1107)
                             ? (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2858)
                             : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp870)
                                 ? (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp242) 
                                     & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1785) 
                                        & (((~ ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp650) 
                                                >> 7U)) 
                                            ^ (~ (1U 
                                                  & ((- 
                                                      (0xffU 
                                                       & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp650))) 
                                                     >> 8U)))) 
                                           | (0U == 
                                              (0xffU 
                                               & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp650))))))
                                     ? 0x80U : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp217) 
                                                 & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp676) 
                                                    & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp650) 
                                                        >> 7U) 
                                                       | (0U 
                                                          == 
                                                          (0xffU 
                                                           & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp650))))))
                                                 ? 0x7fU
                                                 : (IData)(top__DOT__pyrtl_toplevel__DOT__tmp650)))
                                 : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp424)
                                     ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13)
                                     : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp404)
                                         ? (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp242) 
                                             & (((~ 
                                                  (1U 
                                                   & (VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11), 1U) 
                                                      >> 7U))) 
                                                 ^ 
                                                 (~ 
                                                  (1U 
                                                   & ((- 
                                                       (0xffU 
                                                        & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11), 1U))) 
                                                      >> 8U)))) 
                                                | (0U 
                                                   == 
                                                   (0xffU 
                                                    & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11), 1U)))))
                                             ? 0x80U
                                             : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp217) 
                                                 & (VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11), 1U) 
                                                    >> 7U))
                                                 ? 0x7fU
                                                 : 
                                                VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11), 1U)))
                                         : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp44)
                                             ? 2U : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11)))))));
        }
        if (top__DOT__pyrtl_toplevel__DOT__tmp2115) {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7746 
                = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp2880));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7710 
                = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7034));
        } else if (top__DOT__pyrtl_toplevel__DOT__tmp2070) {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7746 
                = (0xffU & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp2248) 
                             & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1785) 
                                & (((~ ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1719) 
                                        >> 7U)) ^ (~ 
                                                   (1U 
                                                    & ((- 
                                                        (0xffU 
                                                         & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1719))) 
                                                       >> 8U)))) 
                                   | (0U == (0xffU 
                                             & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1719))))))
                             ? 0x80U : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp555) 
                                         & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp676) 
                                            & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1719) 
                                                >> 7U) 
                                               | (0U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1719))))))
                                         ? 0x7fU : (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1719))));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7710 
                = (0xffU & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp583) 
                             & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp242) 
                                & (((~ ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1594) 
                                        >> 7U)) ^ (~ 
                                                   (1U 
                                                    & ((- 
                                                        (0xffU 
                                                         & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1594))) 
                                                       >> 8U)))) 
                                   | (0U == (0xffU 
                                             & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1594))))))
                             ? 0x80U : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp150) 
                                         & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp217) 
                                            & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1594) 
                                                >> 7U) 
                                               | (0U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1594))))))
                                         ? 0x7fU : (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1594))));
        } else if (top__DOT__pyrtl_toplevel__DOT__tmp1475) {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7746 
                = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7710 
                = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11));
        } else if (top__DOT__pyrtl_toplevel__DOT__tmp1246) {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7746 
                = (0xffU & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp2248) 
                             & (((~ (1U & (VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12), 1U) 
                                           >> 7U))) 
                                 ^ (~ (1U & ((- (0xffU 
                                                 & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12), 1U))) 
                                             >> 8U)))) 
                                | (0U == (0xffU & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12), 1U)))))
                             ? 0x80U : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp555) 
                                         & (VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12), 1U) 
                                            >> 7U))
                                         ? 0x7fU : 
                                        VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12), 1U))));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7710 
                = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp192));
        } else {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7746 
                = (0xffU & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp870)
                             ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10)
                             : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp424)
                                 ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10)
                                 : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp107)
                                     ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10)
                                     : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp44)
                                         ? 1U : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12))))));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7710 
                = (0xffU & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1107)
                             ? (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7034)
                             : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp870)
                                 ? (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp583) 
                                     & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp2248) 
                                        & (((~ ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp529) 
                                                >> 7U)) 
                                            ^ (~ (1U 
                                                  & ((- 
                                                      (0xffU 
                                                       & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp529))) 
                                                     >> 8U)))) 
                                           | (0U == 
                                              (0xffU 
                                               & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp529))))))
                                     ? 0x80U : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp150) 
                                                 & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp555) 
                                                    & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp529) 
                                                        >> 7U) 
                                                       | (0U 
                                                          == 
                                                          (0xffU 
                                                           & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp529))))))
                                                 ? 0x7fU
                                                 : (IData)(top__DOT__pyrtl_toplevel__DOT__tmp529)))
                                 : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp424)
                                     ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12)
                                     : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp404)
                                         ? (IData)(top__DOT__pyrtl_toplevel__DOT__tmp192)
                                         : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp44)
                                             ? 0U : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10)))))));
        }
    }
    if (top__DOT__pyrtl_toplevel__DOT__tmp7393) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7831 
            = (0xffU & ((IData)((((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17) 
                                  >> 7U) & (((~ (1U 
                                                 & (VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17), 1U) 
                                                    >> 7U))) 
                                             ^ (~ (1U 
                                                   & ((- 
                                                       (0xffU 
                                                        & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17), 1U))) 
                                                      >> 8U)))) 
                                            | (0U == 
                                               (0xffU 
                                                & VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17), 1U))))))
                         ? 0x80U : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1995) 
                                     & (VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17), 1U) 
                                        >> 7U)) ? 0x7fU
                                     : VL_SHIFTL_III(8,8,32, (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17), 1U))));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7798 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7449));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7815 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7525));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7781 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7373));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp6929) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7831 
            = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp13));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7798 
            = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp11));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7815 
            = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp12));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7781 
            = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp10));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp6061) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7831 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4201));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7798 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3933));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7815 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4067));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7781 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6159));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp5077) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7831 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5426));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7798 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3370));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7815 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5841));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7781 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3296));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp4875) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7831 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7798 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7815 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7781 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp4422) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7831 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7882));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7798 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7874));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7815 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7878));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7781 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7870));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp3665) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7831 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4201));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7798 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3933));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7815 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp4067));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7781 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6159));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp3314) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7831 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5426));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7798 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3370));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7815 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp5841));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7781 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp3296));
    } else if (top__DOT__pyrtl_toplevel__DOT__tmp3134) {
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7831 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7898));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7798 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7890));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7815 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7894));
        vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7781 
            = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7886));
    } else {
        if (top__DOT__pyrtl_toplevel__DOT__tmp2070) {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7831 
                = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7798 
                = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14));
        } else if (top__DOT__pyrtl_toplevel__DOT__tmp1475) {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7831 
                = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7798 
                = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14));
        } else if (top__DOT__pyrtl_toplevel__DOT__tmp1144) {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7831 
                = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7798 
                = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14));
        } else {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7831 
                = (0xffU & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp870)
                             ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15)
                             : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp424)
                                 ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15)
                                 : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp107)
                                     ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15)
                                     : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp44)
                                         ? 1U : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17))))));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7798 
                = (0xffU & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1107)
                             ? (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1089)
                             : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp870)
                                 ? (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp2310) 
                                     & (((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17) 
                                         >> 7U) & (
                                                   ((~ 
                                                     ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp892) 
                                                      >> 7U)) 
                                                    ^ 
                                                    (~ 
                                                     (1U 
                                                      & ((- 
                                                          (0xffU 
                                                           & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp892))) 
                                                         >> 8U)))) 
                                                   | (0U 
                                                      == 
                                                      (0xffU 
                                                       & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp892))))))
                                     ? 0x80U : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7407) 
                                                 & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1995) 
                                                    & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp892) 
                                                        >> 7U) 
                                                       | (0U 
                                                          == 
                                                          (0xffU 
                                                           & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp892))))))
                                                 ? 0x7fU
                                                 : (IData)(top__DOT__pyrtl_toplevel__DOT__tmp892)))
                                 : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp424)
                                     ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17)
                                     : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp404)
                                         ? (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7449)
                                         : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp44)
                                             ? 0U : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15)))))));
        }
        if (top__DOT__pyrtl_toplevel__DOT__tmp2115) {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7815 
                = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp6816));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7781 
                = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7050));
        } else if (top__DOT__pyrtl_toplevel__DOT__tmp2070) {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7815 
                = (0xffU & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp837) 
                             & (((IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17) 
                                 >> 7U) & (((~ ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1969) 
                                                >> 7U)) 
                                            ^ (~ (1U 
                                                  & ((- 
                                                      (0xffU 
                                                       & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1969))) 
                                                     >> 8U)))) 
                                           | (0U == 
                                              (0xffU 
                                               & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1969))))))
                             ? 0x80U : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp797) 
                                         & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1995) 
                                            & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1969) 
                                                >> 7U) 
                                               | (0U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1969))))))
                                         ? 0x7fU : (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1969))));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7781 
                = (0xffU & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp2631) 
                             & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp2310) 
                                & (((~ ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1844) 
                                        >> 7U)) ^ (~ 
                                                   (1U 
                                                    & ((- 
                                                        (0xffU 
                                                         & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1844))) 
                                                       >> 8U)))) 
                                   | (0U == (0xffU 
                                             & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1844))))))
                             ? 0x80U : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp284) 
                                         & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp7407) 
                                            & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1844) 
                                                >> 7U) 
                                               | (0U 
                                                  == 
                                                  (0xffU 
                                                   & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1844))))))
                                         ? 0x7fU : (IData)(top__DOT__pyrtl_toplevel__DOT__tmp1844))));
        } else if (top__DOT__pyrtl_toplevel__DOT__tmp1475) {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7815 
                = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp17));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7781 
                = (0xffU & (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp15));
        } else if (top__DOT__pyrtl_toplevel__DOT__tmp1246) {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7815 
                = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7525));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7781 
                = (0xffU & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7373));
        } else {
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7815 
                = (0xffU & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp870)
                             ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14)
                             : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp424)
                                 ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14)
                                 : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp107)
                                     ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14)
                                     : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp44)
                                         ? 0U : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16))))));
            vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp7781 
                = (0xffU & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp1107)
                             ? (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7050)
                             : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp870)
                                 ? (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp2631) 
                                     & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp837) 
                                        & (((~ ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp771) 
                                                >> 7U)) 
                                            ^ (~ (1U 
                                                  & ((- 
                                                      (0xffU 
                                                       & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp771))) 
                                                     >> 8U)))) 
                                           | (0U == 
                                              (0xffU 
                                               & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp771))))))
                                     ? 0x80U : (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp284) 
                                                 & ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp797) 
                                                    & (((IData)(top__DOT__pyrtl_toplevel__DOT__tmp771) 
                                                        >> 7U) 
                                                       | (0U 
                                                          == 
                                                          (0xffU 
                                                           & (IData)(top__DOT__pyrtl_toplevel__DOT__tmp771))))))
                                                 ? 0x7fU
                                                 : (IData)(top__DOT__pyrtl_toplevel__DOT__tmp771)))
                                 : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp424)
                                     ? (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp16)
                                     : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp404)
                                         ? (IData)(top__DOT__pyrtl_toplevel__DOT__tmp7373)
                                         : ((IData)(top__DOT__pyrtl_toplevel__DOT__tmp44)
                                             ? 0U : (IData)(vlSelfRef.top__DOT__pyrtl_toplevel__DOT__tmp14)))))));
        }
    }
}

void Vcalculator___024root___eval_triggers__act(Vcalculator___024root* vlSelf);

bool Vcalculator___024root___eval_phase__act(Vcalculator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcalculator___024root___eval_phase__act\n"); );
    Vcalculator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vcalculator___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vcalculator___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vcalculator___024root___eval_phase__nba(Vcalculator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcalculator___024root___eval_phase__nba\n"); );
    Vcalculator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vcalculator___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vcalculator___024root___dump_triggers__nba(Vcalculator___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vcalculator___024root___dump_triggers__act(Vcalculator___024root* vlSelf);
#endif  // VL_DEBUG

void Vcalculator___024root___eval(Vcalculator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcalculator___024root___eval\n"); );
    Vcalculator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vcalculator___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("calculator.v", 12, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vcalculator___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("calculator.v", 12, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vcalculator___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vcalculator___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vcalculator___024root___eval_debug_assertions(Vcalculator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcalculator___024root___eval_debug_assertions\n"); );
    Vcalculator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.user_1 & 0xfeU)))) {
        Verilated::overWidthError("user_1");}
    if (VL_UNLIKELY(((vlSelfRef.user_4 & 0xfeU)))) {
        Verilated::overWidthError("user_4");}
}
#endif  // VL_DEBUG
