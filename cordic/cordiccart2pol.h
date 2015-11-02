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

void cordiccart2pol(fix_num x, fix_num y, fix_num *r, fix_num *theta);
#endif
