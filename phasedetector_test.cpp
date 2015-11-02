/*
	Filename: fir_test.h
		FIR lab wirtten for WES237C class at UCSD.
		Testbench file
		Calls fir() function from fir.cpp
		Compares the output from fir() with out.gold.dat
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "phasedetector.h"

int main () {
  const int    SAMPLES=1024;
  FILE         *fp, *finI, *finQ, *finGold;

  data_t signal_I, signal_Q, output_R, output_Theta;
  int i;
  signal_I = 0;
  signal_Q = 0;

  data_t gold_R[SAMPLES];
  data_t gold_Theta[SAMPLES];

  data_t error_R=0;
  data_t error_Theta=0;

  finGold=fopen("out.gold.dat","r");
  for (i=0;i<SAMPLES;i++) {
	  fscanf(finGold,"%f %f",&gold_R[i], &gold_Theta[i]);
	  //printf("%f, %f\n",gold_R[i], gold_Theta[i]);

  }
  fclose(finGold);

  finI=fopen("input_i.dat","r");
  finQ=fopen("input_q.dat","r");
  fp=fopen("out.dat","w");

  for (i=0;i<SAMPLES;i++) {
	  fscanf(finI,"%f",&signal_I);
	  fscanf(finQ,"%f",&signal_Q);
	  //Call the HLS block
	  phasedetector(signal_I, signal_Q, &output_R, &output_Theta);
	  // Save the results.

	  //Accumluating error
	  error_R = error_R+ (fabs(output_R) - fabs(gold_R[i]));
	  error_Theta = error_Theta+ (fabs(output_Theta) - fabs(gold_Theta[i]));

	  fprintf(fp,"%f %f\n",output_R, output_Theta);
	  //printf("%i, %f, %f, %f, %f,\n",i,signal_I, signal_Q,output_R, output_Theta);
  }

  fclose(fp);
  fclose(finQ);
  fclose(finI);


  //Checking error
  if(fabs(error_R)<0.0001 and fabs(error_Theta<0.0001)) {
	  printf("error_R=%f, error_Theta=%f\n", error_R, error_Theta);
	  printf("PASS\n");
  }
  else{
	  printf("error_R=%f, error_Theta=%f\n", error_R, error_Theta);
	  printf("FAIL\n");
  }


    return 0;
}

