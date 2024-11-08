// Q3 u105061230 郭承賢
// Given an N-element integer array A[N], where N is an even number.
// Please write a function that swaps A[i] and A[N/2+i], 0 <= i < N/2.
//
// For example, if A[6]={1, 2, 3, 4, 5, 6} after calling the function
// we have A[]={4, 5, 6, 1, 2, 3}.

#include <stdio.h>	//declare header
#define N 6			//define N


void swapHalf(int A[N])	//the start of the function
{
	int i,num;	//declare variable used in loop and swap
	for (i=0; i<N/2; i++) {	//swap half of the array
		num = A[i]; 		//store the value of A[i]
		A[i] = A[N/2+i];	//swap value
		A[N/2+i]=num;		//swap value
	}
	return;	//the end of the function
}
