// Q2 u105061245 蕭郁澄
// Given an N-element integer array A[N], with all elements different.
// Please write a C program to find the smallest element A[k], with k an
// odd number.
//
// For example, if N=10, and A[N]={7, 10, 9, 8, 5, 6, 1, 4, 3, 2} then
//
// $ ./a.out
// A[9]=2
//
// Note that your program should be general enough to handle different N and
// A array.
//

#include <stdio.h>
#define N 10
int A[N]={7, 10, 9, 8, 5, 6, 1, 4, 3, 2};

int main(void)
{
	int i,j=1;					// i is the variable N in the A[N].
	int min = A[1];			// initialize the min

	for ( i=1 ; i < N ; i= i+2)
	{	// ensure the i is an odd number and less than N.)
		if ( A[i] < min )
		{
			min = A[i];
			j = i;
		}
		// if the A[i] smaller than min,then we assign A[i] to min.
	}
	printf("A[%d]=%d\n" , j , min);
	// print the anser.
}
