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

void firI1 (
  data_t *y,
  data_t x
  ) {

	coef_t c[N] = {1,    -1,    1,    -1,    -1,    -1,    1,    1,    -1,    -1,    -1,    1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    1,    1,    1,    1,    -1,    -1,    1,    1,    1,    -1,    -1,    -1};

	// Write your code here
	static data_t shift_regI1[N];
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
  data_t *y,
  data_t x
  ) {

	coef_t c[N] = {1,    -1,    1,    -1,    -1,    -1,    1,    1,    -1,    -1,    -1,    1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    1,    1,    1,    1,    -1,    -1,    1,    1,    1,    -1,    -1,    -1};

	// Write your code here
	static data_t shift_regI2[N];
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
  data_t *y,
  data_t x
  ) {

	coef_t c[N] = {-1,    -1,    1,    -1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    -1,    1,    -1,    1,    1,    -1,    1,    -1,    -1,    1,    -1,    1,    1,    1,    1,    -1,    1,    -1,    1,    1};


	// Write your code here
	static data_t shift_regQ1[N];
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
  data_t *y,
  data_t x
  ) {

	coef_t c[N] = {-1,    -1,    1,    -1,    1,    -1,    1,    -1,    -1,    -1,    -1,    1,    -1,    1,    -1,    1,    1,    -1,    1,    -1,    -1,    1,    -1,    1,    1,    1,    1,    -1,    1,    -1,    1,    1};


	// Write your code here
	static data_t shift_regQ2[N];
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
  data_t I,
  data_t Q,

  data_t *X,
  data_t *Y
  ) {

	// Write your code here
	
	data_t II, QQ, QI, IQ = 0;

	firI1(&II, I);
	firI2(&IQ, Q);

	firQ1(&QQ, Q);
	firQ2(&QI, I);

	//Calculate X

	*X = II + QQ;

	//Calculate Y

	*Y = IQ - QI;

}
