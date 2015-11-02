/*
	Filename: fir.h
		Header file
		FIR lab wirtten for WES237C class at UCSD.

*/
#ifndef PHASE_DETECTOR_H_
#define PHASE_DETECTOR_H_

#include <ap_fixed.h>
const int N=32;
#define NO_ITER 16
typedef ap_fixed<64,8> fix_num;
typedef float data_t;

void fir(float I, float Q, float *X, float *Y); 
void phasedetector(float *input, float *output);
void cordiccart2pol(float x, float y, float *r, float *theta);
void correct_quad(fix_num * x, fix_num * y, int * quad);
void restore_quad(fix_num *theta, int quad);

#endif
