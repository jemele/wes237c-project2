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
typedef ap_fixed<35,8> fix_num;
typedef float data_t;

// Top-level function.
void phasedetector(float *in, float *out);

// Support functions.
void fir(fix_num I, fix_num Q, fix_num *X, fix_num *Y); 
void cordiccart2pol(fix_num x, fix_num y, fix_num *r, fix_num *theta);
void correct_quad(fix_num * x, fix_num * y, int * quad);
void restore_quad(fix_num *theta, int quad);

#endif
