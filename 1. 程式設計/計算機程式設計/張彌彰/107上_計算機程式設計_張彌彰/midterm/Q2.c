// Q2 u107061112 王昊文
// Given a double array A[N], please write a function MUL to
//
// 1. replace A[0] by A[0]*A[1],
// 2. move A[2:N-1] to A[1:N-2],
// 3. reset A[N-1] to 0.
//
// Thus, before calling MUL we have
//     A = {A[0],      A[1], A[2], ..., A[N-2], A[N-1]}
// then after calling MUL we have 
//     A = {A[0]*A[1], A[2], A[3], ..., A[N-1], 0}
//
// Note that your function should be general enough to handle different N
// and A array.
//

#include <stdio.h>

#define N 10

void MUL(double A[N])
{
	int i;
	for (i = 0; i < N; i++) {
		if (i == 0)
			A[i] = A[i] * A[i + 1];
		if (i > 0 && i < N - 1) 
			A[i] = A[i + 1];
		if (i == N - 1)
			A[i] = 0;
	}
}
