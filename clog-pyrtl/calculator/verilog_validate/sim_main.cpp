// FROM
// https://github.com/verilator/verilator/blob/master/examples/make_tracing_c/sim_main.cpp

#include <verilated.h>

#include "Vcalculator.h"

int main(int argc, char** argv) {
	// Verilated::mkdir("logs");

	VerilatedContext* ctx = new VerilatedContext;
	ctx->debug(0);
	ctx->randReset(2);
	ctx->traceEverOn(true);
	ctx->commandArgs(argc, argv);

	Vcalculator* calc = new Vcalculator {ctx, "CALC"};
	calc->clk = 0;
	// (other inputs are irrelevant)
	int iters = 0;
	// while (!Verilated::gotFinish()) {
	while (iters++ < 64*2) {
		calc->clk = !calc->clk;
		calc->eval();
		if (calc->clk) // posedge
			VL_PRINTF("%d | %d | %d\n", calc->rgb0, calc->rgb1, calc->rgb2);
	}

	calc->final();

	ctx->statsPrintSummary();

	delete calc;
	calc = NULL;
	delete ctx;
	ctx = NULL;

	return 0;
}
