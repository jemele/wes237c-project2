/*
	Filename: fir.h
		Header file
		FIR lab wirtten for WES237C class at UCSD.

*/
#ifndef PHASE_DETECTOR_H_
#define PHASE_DETECTOR_H_
//#define pi2  data_t(1.57079633)

#include "ap_int.h"
const int N=32;
#define NO_ITER 16
typedef ap_fixed<64,8> fix_num;

#undef BIT_ACCURATE
#ifdef BIT_ACCURATE
typedef ap_int<32>	coef_t;
typedef ap_int<32>	data_t;
typedef ap_int<32>	acc_t;
#else
typedef int	coef_t;
typedef float	data_t;
typedef float	acc_t;
#endif


void phasedetector (
  data_t I,
  data_t Q,

  data_t *R,
  data_t *theta
  );

void cordiccart2pol(data_t x, data_t y, data_t * r,  data_t * theta);

void fir (
  data_t I,
  data_t Q,

  data_t *X,
  data_t *Y
  );

void correct_quad(fix_num * x, fix_num * y, int * quad);

void restore_quad(fix_num *theta, int quad);

#endif
