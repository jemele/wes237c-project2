############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2012 Xilinx Inc. All rights reserved.
############################################################
open_project ifsynth
set_top ifsynth
add_files ifsynth.cpp
add_files -tb ifsynth_test.cpp
open_solution "solution1"
set_part  {xc7z020clg484-1}
create_clock -period 10
csim_design
csynth_design
