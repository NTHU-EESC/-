/* EE231002 Lab07. Matrix Determinant
   106061145, Jyun-Wei, Huang
   Date: 2017/11/13
*/

#include <stdio.h>

//#if !defined(N)
#define N 8
//#endif

int i, j; 				// for loop
double mat[N][N]; 		// original determinant
void readdet(void);		// read det function
void printdet(void);	// print det funtion
double det(double A[N][N], int dim); // recursive function

int main(void) 
{
	readdet(); 	// read det function
	printdet();	// print det funtion
	printf("det(A) = %g\n", det(mat, N)); // print det result
	return 0;

}

double det(double A[N][N], int dim)
{
	if (dim == 2) return A[0][0] * A[1][1] - A[0][1] * A[1][0]; 
	// if dimension is 2, begin calculate the result
	else {									// if dimension is more than 2
		int row, sign = 1;					// row = determinant row, sign = positive or negative
		double storenum[N][N], sum = 0;		// create a storenum array to calculate the next smaller array
											// set det result sum = 0
		for (row = 0; row < dim; row++) {	// pick the num in the first column in every row
			int storerow = 0, storecol = 0; // set storenum array indexes to 0
			for (i = 0; i < dim; i++) {		// begin pick num to store in storenum array (every row)
				for (j = 1; j < dim; j++) { // every column except the first one
					if (i != row) {			// don't pick the numbers in the same row
						storenum[storerow][storecol] = A[i][j]; // store found nums to storenum
						storecol++;			// move to the next space in storenum
						if (storecol == dim - 1) {	// because storenum array has to be one size less than current one
							storecol = 0;	// set col index to 0
							storerow++;		// move to next line in storenum
						}									
					}						
				}
			} // now we have saved the new matrix called storenum
 			sum += sign * A[row][0] * det(storenum, dim - 1);  // recursive, in order to add the result
			sign *= (-1);	// change the sign 
		} 
		return sum; // return the result
	}
}

void readdet(void)
{
	for (i = 0; i < N; i++) { 
		for (j = 0; j < N; j++) {
			scanf(" %lf", &mat[i][j]); // input determinant numbers
		}
	}
}

void printdet(void)
{
	printf("Matrix A is\n"); 	// print matrix A
	for (i = 0; i < N; i++) { 	 
		printf("  ");			// print space
		for (j = 0; j < N; j++) {
			printf("%g ", mat[i][j]); // print num
			if (j == N - 1)
				printf("\n"); // newline
		}
	}
}
			

