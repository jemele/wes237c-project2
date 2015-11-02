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
  data_t I,
  data_t Q,

  data_t *R,
  data_t *theta
  ){

	data_t x, y= 0;

	// Write your code here
	fir(I, Q, &x, &y);


	//printf("x = %.4f, y = %.4f\n", x, y);
	cordiccart2pol(x, y, R, theta);

}
