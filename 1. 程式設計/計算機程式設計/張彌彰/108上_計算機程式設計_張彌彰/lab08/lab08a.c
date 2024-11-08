
// EE231002 Lab08. Matrix Determinant
// 108061112, 林靖
// Nov. 16, 2019

#include <stdio.h>

#if !defined(N)
#define N 3
#endif

double det(double A[N][N], int dim);

int main(void)
{
	int row, column;
	double A[N][N];
	
	printf("Matrix A is\n");
	for (row = 0; row < N; row++) {
		for (column = 0; column < N; column++) {
			scanf("%lg", &A[row][column]);
			printf("%3lg", A[row][column]);
		}
		printf("\n");
	}
	printf("det(A) = %lg\n", det(A, N));
	return 0;
}

double det(double A[N][N], int dim)
{
	int A_row, A_column;
	double sub[N][N];
	int sub_row, sub_column;
	double sum = 0;
	int sign = 1;
	int column_remove;

	if (dim == 3) {
		return (A[0][0] * (A[1][1] * A[2][2] - A[2][1] * A[1][2]) -
				A[0][1] * (A[1][0] * A[2][2] - A[2][0] * A[1][2]) +
				A[0][2] * (A[1][0] * A[2][1] - A[2][0] * A[1][1])	);
	}
	for (column_remove = 0; column_remove < dim; column_remove++) {
		sub_column = 0;
		for (A_column = 0; A_column < dim; A_column++) {
			if (A_column != column_remove) {
				sub_row = 0;
				for (A_row = 1; A_row < dim; A_row++) {
					sub[sub_row][sub_column] = A[A_row][A_column];
					sub_row++;
				}
				sub_column++;
			}
		}
		sum += sign * A[0][column_remove] * det(sub, dim - 1);
		sign *= -1;
	}
	return sum;
}
