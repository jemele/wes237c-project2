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
#include "fir.h"

int main () {
  const int    SAMPLES=1024;
  FILE         *fp, *finI, *finQ;

  fix_num signal_I, signal_Q, output_X, output_Y;
  int i;
  signal_I = 0;
  signal_Q = 0;

  finI=fopen("input_i.dat","r");
  finQ=fopen("input_q.dat","r");
  fp=fopen("out.dat","w");

  for (i=0;i<SAMPLES;i++) {
	  float input[2];
	  fscanf(finI,"%f",&input[0]);
	  fscanf(finQ,"%f",&input[1]);
	  signal_I = input[0];
	  signal_Q = input[1];
	  //Call the HLS block
	  fir(signal_I, signal_Q, &output_X, &output_Y);
	  // Save the results.
	  fprintf(fp,"%f %f\n",output_X.to_float(), output_Y.to_float());
	  //printf("%i, %f, %f, %f, %f,\n",i,signal_I, signal_Q,output_X, output_Y);
  }

  fclose(fp);
  fclose(finQ);
  fclose(finI);

  //Comparing results with the golden output.
  printf ("Comparing against output data \n");
    if (system("diff -w out.dat out.gold.dat")) {
  	fprintf(stdout, "*******************************************\n");
  	fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
  	fprintf(stdout, "*******************************************\n");
    } else {
  	fprintf(stdout, "*******************************************\n");
  	fprintf(stdout, "PASS: The output matches the golden output!\n");
  	fprintf(stdout, "*******************************************\n");
    }
    return 0;

}

