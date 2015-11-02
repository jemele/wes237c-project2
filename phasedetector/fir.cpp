/*
	Filename: fir.cpp
		Complex FIR or Match filter
		firI1 and firI2 share coef_t c[N]
		firQ1 and firQ2 share coef_t c[N]
		
	INPUT:
		I: signal for I sample
		I: signal for Q sample

	OUTPUT:
		X: filtered output
		Y: filtered output

*/

#include "phasedetector.h"

typedef int	coef_t;
typedef fix_num acc_t;

void firI1 (
  fix_num *y,
  fix_num x
  ) {
#pragma HLS PIPELINE II=3

	coef_t c[N] = {1,    -1,    1,    -1,    -1,    -1,    1,    1,    -1,    -1,    -1,    1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    1,    1,    1,    1,    -1,    -1,    1,    1,    1,    -1,    -1,    -1};
#pragma HLS ARRAY_PARTITION variable=c complete dim=1

	// Write your code here
	static fix_num shift_regI1[N];
#pragma HLS ARRAY_PARTITION variable=shift_regI1 complete dim=1
	acc_t acc = 0;
	int i;
	for (i=N-1;i>=1;i--) {
		shift_regI1[i]=shift_regI1[i-1];
		acc+=shift_regI1[i]*c[i];
	}

	shift_regI1[0]=x;
	acc+=x*c[0];

	*y=acc;

}


void firI2 (
  fix_num *y,
  fix_num x
  ) {
#pragma HLS PIPELINE II=3

	coef_t c[N] = {1,    -1,    1,    -1,    -1,    -1,    1,    1,    -1,    -1,    -1,    1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    1,    1,    1,    1,    -1,    -1,    1,    1,    1,    -1,    -1,    -1};
#pragma HLS ARRAY_PARTITION variable=c complete dim=1

	// Write your code here
	static fix_num shift_regI2[N];
#pragma HLS ARRAY_PARTITION variable=shift_regI2 complete dim=1
	acc_t acc = 0;
	int i;
	for (i=N-1;i>=1;i--) {
		shift_regI2[i]=shift_regI2[i-1];
		acc+=shift_regI2[i]*c[i];
	}

	shift_regI2[0]=x;
	acc+=x*c[0];

	*y=acc;
	
}




void firQ1 (
  fix_num *y,
  fix_num x
  ) {
#pragma HLS PIPELINE II=3

	coef_t c[N] = {-1,    -1,    1,    -1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    -1,    1,    -1,    1,    1,    -1,    1,    -1,    -1,    1,    -1,    1,    1,    1,    1,    -1,    1,    -1,    1,    1};
#pragma HLS ARRAY_PARTITION variable=c complete dim=1


	// Write your code here
	static fix_num shift_regQ1[N];
#pragma HLS ARRAY_PARTITION variable=shift_regQ1 complete dim=1
	acc_t acc = 0;
	int i;
	for (i=N-1;i>=1;i--) {
		shift_regQ1[i]=shift_regQ1[i-1];
		acc+=shift_regQ1[i]*c[i];
	}

	shift_regQ1[0]=x;
	acc+=x*c[0];

	*y=acc;
	
}

void firQ2 (
  fix_num *y,
  fix_num x
  ) {
#pragma HLS PIPELINE II=3

	coef_t c[N] = {-1,    -1,    1,    -1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    -1,    1,    -1,    1,    1,    -1,    1,    -1,    -1,    1,    -1,    1,    1,    1,    1,    -1,    1,    -1,    1,    1};
#pragma HLS ARRAY_PARTITION variable=c complete dim=1


	// Write your code here
	static fix_num shift_regQ2[N];
#pragma HLS ARRAY_PARTITION variable=shift_regQ2 complete dim=1
	acc_t acc = 0;
	int i;
	for (i=N-1;i>=1;i--) {
		shift_regQ2[i]=shift_regQ2[i-1];
		acc+=shift_regQ2[i]*c[i];
	}

	shift_regQ2[0]=x;
	acc+=x*c[0];

	*y=acc;
	
}


void fir (
  fix_num I,
  fix_num Q,

  fix_num *X,
  fix_num *Y
  ) {

	// Write your code here
	
	fix_num II, QQ, QI, IQ = 0;

	firI1(&II, I);
	firI2(&IQ, Q);

	firQ1(&QQ, Q);
	firQ2(&QI, I);

	//Calculate X

	*X = II + QQ;

	//Calculate Y

	*Y = IQ - QI;

}
