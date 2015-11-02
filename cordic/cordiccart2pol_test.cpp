#include "cordiccart2pol.h"
#include <math.h>
#include <stdio.h>

int main()
{
	fix_num x,y,r,theta;

	int is_successful;

	printf("---testing results----------------------------------\n");

	//test1
	x=0.8147;
	y=0.1269;
	cordiccart2pol(x, y, &r,  &theta);

	if ((fabs(theta-fix_num(0.154521173805634))>0.0001)||(fabs(r-fix_num(0.824523923242982))>0.0001))
		is_successful=0;
	else
		is_successful=1;

	if (is_successful)
		printf("Test1 passed!\n");
	else
		printf("Test1 failed!\n");


	//test2
	x=0.6323;
	y=-0.2785;
	cordiccart2pol(x, y, &r,  &theta);

	if ((fabs(theta+fix_num(0.414888412375609))>0.0001)||(fabs(r-fix_num(0.690916449362729))>0.0001))
		is_successful=0;
	else
		is_successful=1;

	if (is_successful)
		printf("Test2 passed!\n");
	else
		printf("Test2 failed!\n");

	//test3
	x=-0.5469;
	y=-0.9575;
	cordiccart2pol(x, y, &r,  &theta);

	if ((fabs(theta+fix_num(2.089751217098013))>0.0001)||(fabs(r-fix_num(1.102681214132172))>0.0001))
		is_successful=0;
	else
		is_successful=1;

	if (is_successful)
		printf("Test3 passed!\n");
	else
		printf("Test3 failed!\n");


	//test4
	x=-0.4854;
	y=0.7003;
	cordiccart2pol(x, y, &r,  &theta);

	if ((fabs(theta-fix_num(2.176897679895152))>0.0001)||(fabs(r-fix_num(0.852075847562880))>0.0001))
		is_successful=0;
	else
		is_successful=1;

	if (is_successful)
		printf("Test4 passed!\n");
	else
		printf("Test4 failed!\n");



    return 0;

}
