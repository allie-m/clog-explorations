// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcalculator.h for the primary calling header

#include "Vcalculator__pch.h"
#include "Vcalculator__Syms.h"
#include "Vcalculator___024root.h"

void Vcalculator___024root___ctor_var_reset(Vcalculator___024root* vlSelf);

Vcalculator___024root::Vcalculator___024root(Vcalculator__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vcalculator___024root___ctor_var_reset(this);
}

void Vcalculator___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vcalculator___024root::~Vcalculator___024root() {
}
