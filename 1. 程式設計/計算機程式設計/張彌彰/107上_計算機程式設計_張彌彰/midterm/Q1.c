// Q1 u107061112 王昊文
// Given an integer array A[N] with N different numbers.
// Please write a program to find the average of the negative elements of A.
//
// For example, if N = 10, and
// A[10] = {-16, 4, -17, 2, -4, -6, 14, 11, -12, 3}
//
// $ ./a.out
// A has 5 negative elements and the average is -11
//
// Note that your program should be general enough to handle different N
// and array A.
//

#include <stdio.h>

#define N 10

int A[10] = {-16, 4, -17, 2, -4, -6, 14, 11, -12, 3};

int main(void)
{
	int i;
	double sum = 0;
	int count = 0;
	double average;
	for (i = 0; i < N; i++) {
		if (A[i] < 0) {
			sum += A[i];
			count++;
		}
	}
	average = sum / count;
	printf("A has %d negative elements and the average is %g\n",
	count, average);
	return 0;
}
