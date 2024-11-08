// EE231002 Lab06. Matrix Determinant
// 110060007, 黃俊穎
// 2022/01/01

#include <stdio.h>
#if !defined(N)
#define N 3
#endif

double det(double A[N][N], int dim);    // determinant function declaration

int main(void)                          // start main function
{
    int row, column;                    // variables of array
	double A[N][N];

	// print out the result
	printf("Matrix A is\n");
	for (row = 0; row < N; row++) {
		for (column = 0; column < N; column++) {
			scanf("%lg", &A[row][column]);
			printf("  %lg", A[row][column]);
		}
	   	printf("\n");
	}
	printf("det(A) = %lg\n", det(A, N)); // print out determinant

	return 0;                            // finish main function
}

// function to calculate determinant value by recursion
double det(double A[N][N], int dim)
{
	int i, j, k;                         // counters in following loops
	double sub[N][N];                    // save recursive arrays
	double sum = 0;                      // initialize of determinant
	int sign = 1;                        // change '+','-' in sum
	int row;                             // row for input array

	if (dim == 1) {
		sum = A[0][0];                   // way of 1*1 determinant
	}
	else if (dim == 2) {
		                                 // way of 2*2 determinant
		sum = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	} else {
		for (i = 0; i < dim; i++) {     // decide title number
			row = 0;                    // prevent title to be other column
			for (j = 0; j < dim; j++) {
				if (j != i) {           // subarray's row downgrade
               		for (k = 1; k < dim; k++) {
					    sub[row][k - 1] = A[j][k];
						                // subarray's column downgrade
					}
					row++;              // store value for next subarray
			    }
		    }
			// formula to calculate determinant
			sum += sign * A[i][0] * det(sub, dim - 1);
			// subarray determinant will be positive and negative
			sign *= -1;
		}
	}
	return sum;                        // return sum value to main function
}
