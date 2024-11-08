// Given an array A of N distinct integers, where N is an odd number.
// Please write a program to find the average of A's elements, M, and
// then print out the sum of all elements less than M.
// For example, A[N] = {1, 2, 8, 9, 3, 4, 5, 6, 7}, then execution of the
// program should be:
//
// $ ./a.out
// The sum of A[i] less than 5 is 10
//
// Note that 5 is the average of array A in this example.

#include <stdio.h>

#define N 9
int A[N] = {1, 2, 8, 10, 3, 4, 5, 6, 7};

int main(void)
{
	int sum = 0; // sum: first store sum of all numbers in A and 
				 // then store sum of numbers in A less than average of A
	int i;		 // i: counter for loops
	double M;    // M: average of A

	for (i = 0; i < N; i++) { // sum up all numbers in A
		sum += A[i];
	}
	M = (double)sum / N;      // calculate average of A
	sum = 0;                  // initialize sum 
	for (i = 0; i < N; i++) { // sum up numbers in A less than M
		if (A[i] < M) sum += A[i];
	}
	printf("The sum of A[i] less than %lf is %d\n", M, sum); // print result
}

