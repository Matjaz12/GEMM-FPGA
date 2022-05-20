#include "gemm.h"
#include <iostream>
using namespace std;

void matrix_print(mat_t A[SIZE][SIZE])
{
	for	(size_t i = 0; i < SIZE; i++)
	{
		for	(size_t j = 0; j < SIZE; j++)
		{
			cout << A[i][j];
		}
		cout << endl;
	}
}

int main()
{

	// Test bench inputs
	mat_t a[SIZE][SIZE] = {{1,2,3},{4,5,6},{7,8,9}};
	mat_t b[SIZE][SIZE] = {{1,2,3},{4,5,6},{7,8,9}};
	mat_t c[SIZE][SIZE] = {{0,0,0},{0,0,0},{0,0,0}};
	int a1 = 1;
	int b1 = 3;

	// Expected results
	mat_t ref[SIZE][SIZE] = {{30,36,42},{66,81,96},{102,126,150}};

	int err_cnt = 0;

	#ifdef HW_COSIM
	   // Run the AutoESL matrix multiply block
	   gemm(a1, b1, a, b, c);
	#endif

	   // Print result matrix
	   //cout << setw(6);
	   for (int i = 0; i < SIZE; i++)
	   {
		  for (int j = 0; j < SIZE; j++)
		  {
			#ifdef HW_COSIM
				 // Check HW result against SW
				 if (c[i][j] != ref[i][j])
					err_cnt++;
			#else
					 cout << sw_result[i][j];
			#endif
		  }
	   }

	#ifdef HW_COSIM
	   if (err_cnt)
		  cout << "ERROR: " << err_cnt << " mismatches detected!" << endl;
	   else
		  cout << "Test passes." << endl;
	#endif
	   return err_cnt;
}


/*
#include "gemm.h"
#include <iostream>
using namespace std;

void matrix_print(mat_t A[SIZE][SIZE])
{
	for	(size_t i = 0; i < SIZE; i++)
	{
		for	(size_t j = 0; j < SIZE; j++)
		{
			cout << A[i][j];
		}
		cout << endl;
	}
}

int main()
{

	// Test bench inputs
	mat_t a[SIZE][SIZE] = {{1,2,3},{4,5,6},{7,8,9}};
	mat_t b[SIZE][SIZE] = {{1,2,3},{4,5,6},{7,8,9}};
	mat_t c[SIZE][SIZE] = {{0,0,0},{0,0,0},{0,0,0}};
	int a1 = 1;
	int b1 = 3;

	// Expected results
	mat_t ref[SIZE][SIZE] = {{30,36,42},{66,81,96},{102,126,150}};

	int err_cnt = 0;

	#ifdef HW_COSIM
	   // Run the AutoESL matrix multiply block
	   gemm(a1, b1, a, b, c);
	#endif

	   // Print result matrix
	   //cout << setw(6);
	   for (int i = 0; i < SIZE; i++)
	   {
		  for (int j = 0; j < SIZE; j++)
		  {
			#ifdef HW_COSIM
				 // Check HW result against SW
				 if (c[i][j] != ref[i][j])
					err_cnt++;
			#else
					 cout << sw_result[i][j];
			#endif
		  }
	   }

	#ifdef HW_COSIM
	   if (err_cnt)
		  cout << "ERROR: " << err_cnt << " mismatches detected!" << endl;
	   else
		  cout << "Test passes." << endl;
	#endif
	   return err_cnt;
}
*/
