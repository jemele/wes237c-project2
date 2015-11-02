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


void phasedetector (
    float *input_i_q,
    float *output_r_theta
  ){

	data_t x, y= 0;

	// Write your code here
	fir(input_i_q[0], input_i_q[1], &x, &y);

	//printf("x = %.4f, y = %.4f\n", x, y);
	cordiccart2pol(x, y, &output_r_theta[0], &output_r_theta[1]);
}
