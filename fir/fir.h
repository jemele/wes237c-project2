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

// Support functions.
void fir(data_t I, data_t Q, data_t *X, data_t *Y); 
#endif
