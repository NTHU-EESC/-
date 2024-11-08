// EE231002 Lab06. Permutations
// 108061112, 林靖
// Oct. 25, 2019

#include <stdio.h>
#define N 4

int main(void)
{
	int count = 0;
	int A[N], i;
	int J = -2, K;
	int temp, R;

	for (i = N; i; --i) {
		A[N - i] = i;
	}
	while (J + 1) {
		printf("permutation #%d: ", ++count);
		for (i = 0; i < N; ++i) {
			printf("%d ", A[i]);
		}
		printf("\n");
		for (J = N - 1; A[J - 1] < A[J] && J; --J) ;
		for (K = N - 1, --J; A[J] < A[K]; --K) ;
		temp = A[J];
		A[J] = A[K];
		A[K] = temp;
		for (R = N; ++K < --R; ) {
			temp = A[K];
			A[K] = A[R];
			A[R] = temp;
		}
	}
	printf("  Total number of permutations is %d\n", count);
	return 0;
}
