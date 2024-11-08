/* EE231002 Lab05. Permutations
   106061145, Jyun-Wei Huang
   Date: 2017/10/23
*/

#include <stdio.h>
#define N 7

int main(void)
{
	int A[N], i, j, k, l, m, temp, last = 0, counter = 1;
	/* A[N] = array
	   i = loop for first permutation 
	   j = loop for step 1
	   k = loop for step 2
	   l = loop for reverse sequence (step 4)
	   m = loop for printing every permutation
	   temp = swap numbers
	   last = boolean for last permutation
	   counter = total amound of found permutation
	*/

	printf("permutation #1:");	// output first permutation
	
	for (i = 0; i < N; i++) {	// array from A0 to A(N-1)
		A[i] = N - i;			// assign a number to array
		printf(" %d", A[i]);	// print each number
	
		if (i == N - 1)			// if last number
			printf("\n");		// print newline
	}
	
	while (!last) {	// repeat until the last permutation
		
		int x = -1; 	// x = first index 
		int y = -1;		// y = second index
	
		for (j = 0; j <= N - 2; j++) { 
		// find largest index j such that A[j] > A[j+1]
			if (A[j] > A[j+1])  // index found
				x = j;		// save first index to x
		}
	
		if (x == -1)	// no such index exists
			last = 1;	// it's the last permutation
		
		if (!last){		// if not the last permutaion
			
			counter++;	// add one to counter
			
			for (k = x; k <= N - 1; k++) {
			// find largest index k such that A[j] > A[k]
				if (A[x] > A[k]) // index found
					y = k; // save second index to x
			}
	
			temp = A[x];
			A[x] = A[y];
			A[y] = temp; // swap A[j] with A[k]
	
			for (l = x + 1; l <= (N + x) / 2; l++) {
			// reverse the sequence from A[j+1] up to the last element 
				temp = A[N + x - l];
				A[N + x - l] = A[l];
				A[l] = temp; // swap two numbers at a time 
				
			}
		
			printf("permutation #%d:", counter); //print result
			
			for (m = 0; m < N; m++) { // array from A0 to A(N-1)

				printf(" %d", A[m]); // print each number
	
				if (m == N - 1)		// if last number
					printf("\n");	// print newline
			}
		}
	}
	printf("  Total number of permutations is %d", counter);
	// print total number of permutations
	return 0;
}
