// Q2 u105061230 郭承賢
// Given an N-element integer array A[N], with all elements different.
// Please write a C program to find the largest element A[k], with k an
// even number.
//
// For example, if N=10, and A[N]={7, 10, 9, 8, 5, 6, 1, 4, 3, 2} then
//
// $ ./a.out
// A[2]=9
//
// Note that your program should be general enough to handle different N and
// A array.
//

#include <stdio.h>	//declare header
#define N 10	//define N
int A[N]={7, 10, 9, 8, 5, 6, 1, 4, 3, 2};
//declare an Array that we want to find the largest number
int main(void)	//the start of the function
{
	int large=0,i=0,k=0;
	//large store largest number,k store index,i is used in loop
	for (i=0; i<=N; i+=2) {	//find the even index
		if (A[i]>large) {	//find the largest number
			large = A[i];	//store the number
			k=i;			//store index
		}
	}
	printf("A[%d]=%d\n",k,large);	//print the index and number
	return 0;	//if the function is correct return value 0
}
