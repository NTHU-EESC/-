// Given a matrix A[N][N] of N^2 double precision numbers, please write a
// function coFactor(A, r, c) to rearrange A into the following form:
// A[r][c] becomes A[N-1][N-1]
// and A[0:N-2][0:N-2] becomes a cofactor of A[r][c].
// For example, if N = 3, before and after calling coFactor(A, 0, 1) are
//
//         Matrix A            After calling coFactor(A, 0, 1)
//  A[0][0] A[0][1] A[0][2]      A[2][0] A[2][2] A[2][1]
//  A[1][0] A[1][1] A[1][2]      A[1][0] A[1][2] A[1][1]
//  A[2][0] A[2][1] A[2][2]      A[0][0] A[0][2] A[0][1]
//
// Note that 0 <= r, c < N

#define N 5

void coFactor(double A[N][N], int r, int c)
{
	double temp; // temp: for swaping two numbers
	int i;       // i: counter for loops
	
	for (i = 0; i < N; i++) { // swap A[r][i] and A[N - 1][i]
		temp = A[r][i];		  // and i ranges from 0 to N - 1
		A[r][i] = A[N - 1][i];
		A[N - 1][i] = temp;
	}
	for (i = 0; i < N; i++) { // swap A[i][c] and A[i][N - 1]
		temp = A[i][c];   // and i ranges from 0 to N - 1
		A[i][c] = A[i][N - 1];
		A[i][N - 1] = temp;
	}

	return;
}
