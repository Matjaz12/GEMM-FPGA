# General Matrix Multiplication (GEMM)

## About
The project was developed for course [Computer Systems](https://www.fri.uni-lj.si/en/course/63509).
 

## Info
Vivado HLS is used to optimize GEMM operation. In these seminar we explore the use
of `pipeline` directive and `array_reshape` directive. We analyse performance
and hardware resources utilization using matricies of 3 different sizes:
`16 x 16, 32 x 32, 64 x 64`. 

## Report
Report of the work done is available `report.pdf`. In `analysis/` folder all of 
the synthesis results are also avaiable. 

## Usage
### Vivado
In order to use the source code you should include `gemm.cpp` and `gemm.h` in your Vivado project. \
Select `gemm` as the top function. You can also include the test bench file: `gemm_tb.cpp`.


### Test matrices
You can generate random test matrices and expected result of GEMM operation
using the python script as follows: `python gemm.py <MATRIX_SIZE> <VALUES_RANGE> <ALPHA> <BETA>`. 
The script prints the matricies in C format in the terminal, you can simply copy and 
paste the terminal output into test bench file `gemm_tb.cpp`.
