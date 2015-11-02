############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2012 Xilinx Inc. All rights reserved.
############################################################
open_project cordiccart2pol
set_top cordiccart2pol
add_files cordiccart2pol.cpp
add_files cordiccart2pol.h
add_files -tb cordiccart2pol_test.cpp
open_solution "solution1"
set_part  {xc7z020clg484-1}
create_clock -period 10
csim_design
csynth_design
