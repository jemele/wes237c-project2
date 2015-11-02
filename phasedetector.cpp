/*
	Filename: phasedetector.cpp
		Phase detector

	INPUT:
		I: signal for I sample
		Q: signal for Q sample

	OUTPUT:
		R: Radius
		Theta: Angle

*/

#include "phasedetector.h"

void phasedetector(float *in, float *out)
{
#pragma AP interface ap_fifo port=in
#pragma AP interface ap_fifo port=out
#pragma AP interface ap_ctrl_none port=return

    // Read input from host.
    data_t i = *in++;
    data_t q = *in++;

	data_t x, y;
	fir(i, q, &x, &y);

    data_t r, theta;
	cordiccart2pol(x, y, &r, &theta);

    // Write output back to host.
    *out++ = r;
    *out++ = theta;
}
