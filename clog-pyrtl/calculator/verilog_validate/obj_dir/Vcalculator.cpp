// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcalculator__pch.h"

//============================================================
// Constructors

Vcalculator::Vcalculator(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcalculator__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rgb0{vlSymsp->TOP.rgb0}
    , rgb1{vlSymsp->TOP.rgb1}
    , rgb2{vlSymsp->TOP.rgb2}
    , user_1{vlSymsp->TOP.user_1}
    , user_2{vlSymsp->TOP.user_2}
    , user_3{vlSymsp->TOP.user_3}
    , user_4{vlSymsp->TOP.user_4}
    , usb_dp{vlSymsp->TOP.usb_dp}
    , usb_dn{vlSymsp->TOP.usb_dn}
    , usb_dp_pu{vlSymsp->TOP.usb_dp_pu}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vcalculator::Vcalculator(const char* _vcname__)
    : Vcalculator(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcalculator::~Vcalculator() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vcalculator___024root___eval_debug_assertions(Vcalculator___024root* vlSelf);
#endif  // VL_DEBUG
void Vcalculator___024root___eval_static(Vcalculator___024root* vlSelf);
void Vcalculator___024root___eval_initial(Vcalculator___024root* vlSelf);
void Vcalculator___024root___eval_settle(Vcalculator___024root* vlSelf);
void Vcalculator___024root___eval(Vcalculator___024root* vlSelf);

void Vcalculator::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcalculator::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcalculator___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vcalculator___024root___eval_static(&(vlSymsp->TOP));
        Vcalculator___024root___eval_initial(&(vlSymsp->TOP));
        Vcalculator___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vcalculator___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vcalculator::eventsPending() { return false; }

uint64_t Vcalculator::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vcalculator::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vcalculator___024root___eval_final(Vcalculator___024root* vlSelf);

VL_ATTR_COLD void Vcalculator::final() {
    Vcalculator___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcalculator::hierName() const { return vlSymsp->name(); }
const char* Vcalculator::modelName() const { return "Vcalculator"; }
unsigned Vcalculator::threads() const { return 1; }
void Vcalculator::prepareClone() const { contextp()->prepareClone(); }
void Vcalculator::atClone() const {
    contextp()->threadPoolpOnClone();
}
