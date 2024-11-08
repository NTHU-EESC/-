// Q2 
// Given an integer array A[N], with N distinct elements, you program performs
//
// 1. Find A[j], such that A[j] is the smallest element in array A,
// 2. Find A[k], such that A[k] is the largest element in array A,
// 3. Reverse all elements in between A[j] and A[k], including A[j] and A[k].
//    And then print out the resulting array A.
//
// For example, N = 10, and A[N] = {6, 11, 2, 12, 17, 4, 28, 25, 16, 14}
// Your program execute to get
// $ ./a.out
// Original: 6 11 2 12 17 4 28 25 16 14
// min: A[2] 2
// max: A[6] 28
// After processing: 6 11 28 4 17 12 2 25 16 14

#include <stdio.h>
#define N 10

int main(void)
{
	int A[N] = {6, 11, 2, 12, 17, 4, 28, 25, 16, 14};
	int min = 0, max = 0, i, temp;  
		// min: index of the smallest element
		// max: index of the largest element
		// i: counter for loops
		// temp: temporary number for swaping

	printf("Original:");
	for (i = 0; i < N; i++) { // print the original array
		printf(" %d", A[i]);
	}
	printf("\n");
	for (i = 1; i < N; i++) { // find max and min
		if (A[i] > A[max]) {
			max = i;
		}
		if (A[i] < A[min]) {
			min = i;
		}
	}
	printf("min: A[%d] %d\n", min, A[min]); // print min
	printf("max: A[%d] %d\n", max, A[max]); // print max
	while (min < max) { // reverse element between min and max
		temp = A[min];
		A[min] = A[max];
		A[max] = temp;
		++min;
		--max;
	}
	printf("After processing:");
	for (i = 0; i < N; i++) { // print the after processing array
		printf(" %d", A[i]);
	}
	printf("\n");

	return 0;
}


