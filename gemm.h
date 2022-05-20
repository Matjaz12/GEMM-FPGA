/*******************************************************************************/
#ifndef __GEMM_H__
#define __GEMM_H__

#include <cmath>
using namespace std;

// Compare TB vs HW C-model and/or RTL
#define HW_COSIM

#define SIZE 16


typedef int mat_t;


// Prototype of top level function for C-synthesis
void gemm(
      int alpha,
      int beta,
      mat_t a[SIZE][SIZE],
      mat_t b[SIZE][SIZE],
      mat_t c[SIZE][SIZE]);

#endif // __GEMM_H__ not defined
