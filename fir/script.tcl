############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2012 Xilinx Inc. All rights reserved.
############################################################
open_project fir
set_top fir
add_files fir.cpp
add_files -tb out.gold.dat
add_files -tb input_i.dat
add_files -tb input_q.dat
add_files fir.cpp
add_files fir.h
add_files -tb fir_test.cpp
open_solution "solution1"
set_part  {xc7z020clg484-1}
create_clock -period 10
# Because ap_fixed causes the simulation test bench to fail, but otherwise
# passes simulation when integrated into phasedetector, we omit the simulation
# step here to get accurate sizing/metrics.
#csim_design
csynth_design
