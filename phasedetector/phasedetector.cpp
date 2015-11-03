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
#pragma HLS PIPELINE II=3

    // Read input from host.
    fix_num i = *in++;
    fix_num q = *in++;

	fix_num x, y;
	fir(i, q, &x, &y);

    fix_num r, theta;
	cordiccart2pol(x, y, &r, &theta);

    // Write output back to host.
    *out++ = r;
    *out++ = theta;
}
