// EE231002 Lab06. Permutations
// 108061112, 林靖
// Oct. 25, 2019

#include <stdio.h>
#define N 4

int main(void)
{
	int A[N];
	int i;
	int j = N; 
	int k;
	int temp;
	int count = 0;

	for (i = N; i; i--) {
		A[N - i] = i;
	}
	while (j >= 0) {
		for (i = N; ++j < --i; ) {
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
		printf("permutation #%d: ", ++count);
		for (i = 0; i < N; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
		for (j = N - 2; A[j] < A[j + 1] && j >= 0; j--) ;
		for (k = N - 1; A[j] < A[k]; k--) ;
		temp = A[j];
		A[j] = A[k];
		A[k] = temp;
	}
	printf("  Total number of permutations is %d\n", count);
}
