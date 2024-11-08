
// Q1 108061112 林靖
// Given an NxN int matrix A, please write a function to
//   1. Swap row 0 and row r, 0 <= r <= N - 1,
//   2. Swap column 0 and column c, 0 <= c <= N - 1.
//
// For example,
//
// A = { A00, A01, A02, A03,
//       A10, A11, A12, A13,
//       A20, A21, A22, A23,
//       A30, A31, A32, A33 }
//
// After calling pivot(A, 1, 2) we get
//
// A = { A12, A11, A10, A13,
//       A02, A01, A00, A03,
//       A22, A21, A20, A23,
//       A32, A31, A30, A33 }
//

#define N 4

void pivot(int A[N][N], int r, int c)
{
	int tmp;		// to swap
	int i;			// loop index

	for (i = 0; i < N; i++) {		// to swap row 0 and row r
		tmp = A[0][i];
		A[0][i] = A[r][i];			// swap
		A[r][i] = tmp;
	}
	for (i = 0; i < N; i++) {		// to swap column 0 and column c
		tmp = A[i][0];
		A[i][0] = A[i][c];			// swap
		A[i][c] = tmp;
	}

	return;			// termination
}

#include <stdio.h>

int main(void)
{
	int A[N][N] = { 0, 1, 2, 3,
       10, 11, 12, 13,
       20, 21, 22, 23,
       30, 31, 32, 33 };
	int i, j;

	pivot(A, 1, 2);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf(" %d", A[i][j]);
		}
		printf("\n");
	}
}
