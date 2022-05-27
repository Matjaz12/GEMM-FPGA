/*******************************************************************************/
#ifndef __GEMM_H__
#define __GEMM_H__

#include <cmath>
using namespace std;

// Compare TB vs HW C-model and/or RTL
#define HW_COSIM

#define SIZE 16
/*
 * SIZE 	 = 3 ... 3x3 matrix
 * SIZE		 = 16 ... 16x16 matrix
 * SIZE      = 32 ... 32x32 matrix
 * SIZE		 = 64 ... 64x64 matrix
 */

typedef int mat_t;


// Prototype of top level function for C-synthesis
void __attribute__ ((noinline)) gemm(
      int alpha,
      int beta,
      mat_t a[SIZE][SIZE],
      mat_t b[SIZE][SIZE],
      mat_t c[SIZE][SIZE]);

#endif // __GEMM_H__ not defined
