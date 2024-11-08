// Q3 u105061245 蕭郁澄
// Given an N-element integer array A[N], where N is an even number.
// Please write a function that swaps A[2*i] and A[2*i+1], 0 <= i < N/2.
//
// For example, if A[6]={1, 2, 3, 4, 5, 6} after calling the function
// we have A[]={2, 1, 4, 3, 6, 5}.

#include <stdio.h>
#define N 6

void oddEven(int A[N])
{
	int i;				// loop variable
	int temp;			// temporarily store the value of A[2*i]
	
	for ( i=0 ; i< N/2 ; i++ )
	{					// swap the A[2*i] and A[2*i+1]
		temp = A[2*i];
		A[2*i] = A[2*i+1];
		A[2*i+1] = temp;
	}
}

