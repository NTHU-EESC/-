// EE231002 Lab06. Permutations
// 108061112, 林靖
// Oct. 25, 2019

#include <stdio.h>	// Standard input and output library
#define N 4			// Given a set of N distinct elements

int main(void)		// Called at program startup
{
	int A[N];		// Stores a permutation
	int i;			// To initialize & print A[N], to reverse sequence in step 4
	int j = N;		// To find such index j in step 1
	int k;			// To find such index k in step 2
	int temp;		// To swap in step 3, to reverse sequence in step 4
	int count = 0;	// Number of permutations generated

	for (i = N; i; i--) {	// Initialize A[N] from 1 to N
		A[N - i] = i;		// In reversed order
	}
	while (j >= 0) {				// If j < 0, no such index exists (the end)
		for (i = N; ++j < --i; ) {	// Step 4, reverse A[j + 1] ~ A[N - 1] :
			temp = A[j];	//
			A[j] = A[i];	// Mirror the elements by reflection
			A[i] = temp;	//
		}
		printf("permutation #%d: ", ++count);	// # of permutations generated
		for (i = 0; i < N; i++) {	// To print out all the elements in A[N]
			printf("%d ", A[i]);	// To print out the permutation
		}
		printf("\n");	// (new line)
		for (j = N - 2; A[j] < A[j + 1] && j >= 0; j--) ; // Step 1, find such j
		for (k = N - 1; A[j] < A[k]; k--) ;				  // Step 2, find such k
		temp = A[j];	//
		A[j] = A[k];	// Step 3, swap A[j] with A[k]
		A[k] = temp;	//
	}
	printf("  Total number of permutations is %d\n", count); // (total number)
	return 0;	// Indicates normal program termination
}
