############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2012 Xilinx Inc. All rights reserved.
############################################################
open_project ternarysynth
set_top ternarysynth
add_files ternarysynth.cpp
add_files -tb ternarysynth_test.cpp
open_solution "solution1"
set_part  {xc7z020clg484-1}
create_clock -period 10
csim_design
csynth_design
