#include "gemm.h"



// A = scalar * A
void scalar_mult(int scalar, mat_t A[SIZE][SIZE])
{
	Row_Loop:
	for	(size_t i = 0; i < SIZE; i++)
	{
		Col_Loop:
		for	(size_t j = 0; j < SIZE; j++)
		{
			A[i][j] = scalar * A[i][j];
		}
	}
}

// A = A + B
void matrix_add(mat_t A[SIZE][SIZE], mat_t B[SIZE][SIZE])
{
	Row_Loop:
	for	(size_t i = 0; i < SIZE; i++)
	{
		Col_Loop:
		for	(size_t j = 0; j < SIZE; j++)
		{
			A[i][j] = A[i][j] + B[i][j];
		}
	}
}

// X = A B
void matrix_mult(mat_t A[SIZE][SIZE], mat_t B[SIZE][SIZE], mat_t X[SIZE][SIZE])
{
	mat_t X_ij = 0;

	Row_Loop:
	for	(size_t i = 0; i < SIZE; i++)
	{
		Col_Loop:
		for	(size_t j = 0; j < SIZE; j++)
		{
			X_ij = 0;
			DotProduct_Loop:
			for	(size_t k = 0; k < SIZE; k++)
			{
				X_ij += A[i][k] * A[k][j];
			}
			X[i][j] = X_ij;
		}
	}
}

// C = alpha * A B + beta * C
void gemm(int alpha, int beta, mat_t a[SIZE][SIZE], mat_t b[SIZE][SIZE], mat_t c[SIZE][SIZE])
{
	mat_t tmp[SIZE][SIZE];

    // Calculate matrix product of A in B
	matrix_mult(a, b, tmp);
 
    // scale matrices tmp in c using alpha and beta
	scalar_mult(alpha, tmp);
	scalar_mult(beta, c);

    // add tmp and c and store it in c
	matrix_add(c, tmp);
}



