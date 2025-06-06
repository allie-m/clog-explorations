// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vcalculator__pch.h"
#include "Vcalculator.h"
#include "Vcalculator___024root.h"

// FUNCTIONS
Vcalculator__Syms::~Vcalculator__Syms()
{
}

Vcalculator__Syms::Vcalculator__Syms(VerilatedContext* contextp, const char* namep, Vcalculator* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(1010);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
