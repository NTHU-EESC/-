// Q2 110060007 黃俊穎
// Given a floating point matrix, A[N][N], please write a program to find
// the sum of all fraction part of each element in A.
//
// For example, if N = 3 and
// A[N][N] = {{1.1, 2.2, 3.3},
//            {4.4, 5.5, 6.6},
//            {7.7, 8.8, 9.9}}
// then your program should execute
// 
// $ ./a.out
// Sum of fraction of each element: 4.5
//
// Note that your program should be able to handle different N and A array
// and both N and matrix A are given in the source file (no need to read in).

#include <stdio.h>

#define N 3

double A[N][N] = {{1.1, 2.2, 3.3},
                  {4.4, 5.5, 6.6},
                  {7.7, 8.8, 9.9}};

int main(void)
{
    int row;                       // row variable to do first loop
	int column;                    // column variable to do second loop
    double sum = 0;                // initialize value of sum
	double fraction_num;           // fraction of each element

    // start find each fraction of element and sum up
    for (row = 0; row < N; row++) {
	    for (column = 0; column < N; column++) {
		    fraction_num = A[row][column] - (int)A[row][column];
		    sum += fraction_num;
		}
	}
	// print out the result
    printf("Sum of fraction of each element: %lg", sum);
	return 0;
}
