#include "phasedetector.h"
//#include <math.h>

fix_num Kvalues[NO_ITER] = {1,	0.500000000000000,	0.250000000000000,	0.125000000000000,	0.0625000000000000,	0.0312500000000000,	0.0156250000000000,	0.00781250000000000,	0.00390625000000000,	0.00195312500000000,	0.000976562500000000,	0.000488281250000000,	0.000244140625000000,	0.000122070312500000,	6.10351562500000e-05,	3.05175781250000e-05};

fix_num angles[NO_ITER] = {0.785398163397448,	0.463647609000806,	0.244978663126864,	0.124354994546761,	0.0624188099959574,	0.0312398334302683,	0.0156237286204768,	0.00781234106010111,	0.00390623013196697,	0.00195312251647882,	0.000976562189559320,	0.000488281211194898,	0.000244140620149362,	0.000122070311893670,	6.10351561742088e-05,	3.05175781155261e-05};

#define pi2  data_t(1.5707963)
#define SHIFTER

void correct_quad(fix_num * x, fix_num * y, int * quad)
{

	fix_num temp = 0;

	if (*x < 0) {
		if (*y<0) {
			temp = -*y; // temp = -1*y
			* y = *x;
			* x = temp;
			*quad = 3;
		} else {
			temp = -*x;  // temp  = -1*x
			* x = *y;
			* y = temp;
			*quad = 2;
		}
	}
}

void restore_quad(fix_num *theta, int quad){

//	printf("theta = %.4f\n", *theta);
	if (quad == 2) {
		*theta += fix_num(pi2);
	}
	if (quad == 3){
		*theta -= fix_num(pi2);
	}
//	printf("theta = %.4f\n", *theta);
}

void cordiccart2pol(float x_float, float y_float, float * r_float,  float * theta_float)
{
	// Write your code here
	fix_num x = x_float;
	fix_num y = y_float;
	fix_num r = 0;
	fix_num theta = 0;

	theta = 0;
	r = 0;

	int i = 0;
	int quad = 0;
	correct_quad(&x, &y, &quad);
	fix_num temp = 0;

	for (i = 0; i < NO_ITER; i++){

		if (y < 0) {
#ifdef SHIFTER
			temp=x;
			x -= y>>i;
			y += temp>>i;
			theta = theta - angles[i];
#else
			temp=x;
			x = x - (y*Kvalues[i]);
			y = y + (temp*Kvalues[i]);
			theta = theta - angles[i];
#endif
		} else {
#ifdef SHIFTER
			temp=x;
			x += y>>i;
			y -= temp>>i;
			theta = theta + angles[i];
#else
			temp=x;
			x = x + (y*Kvalues[i]);
			y = y - (temp*Kvalues[i]);
			theta = theta + angles[i];
#endif
		}
//		printf("x = %.4f, y = %.4f\n", float(x), float(y));
	}

	r = fix_num(0.60725441)*x; // 0.607252935008881

	restore_quad(&theta, quad);

	*r_float = float(r);
	*theta_float = float(theta);
}
