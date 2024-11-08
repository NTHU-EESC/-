// EE231002 Lab05. Permutations
// 110060007, 黃俊穎
// 2022/01/01

#include <stdio.h>                  // I/O library
#define N 7                         // question setting number
#define true 1                      // set true value equal to 1
#define false 0                     // set false value equal to 0

int main(void)                      // start the main function
{
    int A[N], Ans[N];               // array for answer and storage
	int i, j, k, t;                 // variables for loops and string
    int arr_j, arr_k;               // number in given array
	int index_j, index_k;           // number of given array
    int total_num = 1;              // initialize number of factorial
    int saver;                      // storage for swapping number
	int all_index;                	// value of string number
	int T_F = true;
	// a decided value to decide if the string still run in loops
	int counter = 1;                // count for permutation number

    // initialize array, storage array and value of factorial
    for (i = 0; i < N; i++) {
        A[i] = i + 1;
        Ans[i] = i + 1;
	  	total_num *= (i + 1);
   	}

    // show sequence for printing
	while (T_F) {
       	// set step 1 to be terminated condition
	    T_F = false;
	    printf("permutation #%d:", counter++);

        // show the result of every sequence
		for (i = 0; i < N; i++) {
	        printf(" %d", Ans[i]);
	   	}
        printf("\n");               // skip to next line
	   	all_index = N;              // save total number in an array

        // step 1: find the largest index such that A[j] < A[j + 1]
    	for (j = 0; j < N - 1; j++) {
		    if (A[j] < A[j + 1]) {
	            arr_j = A[j];       // save the value in A[j]
                index_j = j;        // save j
				T_F = true;         // continue following command
	       	}
       	}

        // step 2: find the largest index k such that A[j] < A[k]
        for (k = index_j; k < N; k++) {
            if (arr_j < A[k]) {
                arr_k = A[k];       // save the value in A[k]
        	    index_k = k;        // save k
           	}
       	}
        // step 3: swap A[j] with A[k]
        saver = arr_k;
        arr_k = arr_j;
      	arr_j = saver;
    	A[index_j] = arr_j;
      	A[index_k] = arr_k;

        // step 4: reverse the sequence from A[j + 1] up to and 
     	// including the last element A[N - 1]
        for (i = 0; i <= index_j; i++) {
            Ans[i] = A[i];
			// fill in first part value in storage array
       	}
        for (i = index_j + 1; i < N; i++) {
            Ans[i] = A[all_index - 1];
			// fill in second part value in storage array
         	all_index--;
			// fill in corresponding index decreasingly
       	}
    	// reverse storage to original array to do next permutation
       	for (i = 0; i < N; i++) {
   	        A[i] = Ans[i];         // redo for next permutation
      	}
    }
    // print out the result
   	printf("  Total number of permutations is %d\n", total_num);
    return 0;                       // finish the main function
}
