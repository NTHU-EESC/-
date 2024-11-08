
// Q4 108061112 林靖
// We have practiced factorizing an positive integer by its prime factors
// and associated powers. For example,
//
// 100 = 2^2 x 5^2
//
// And the NODE defined below is shown to be a good data structure for
// the linked list of the prime factorization.
//

#include <stdlib.h>					// Standard library

typedef struct sFactor {
    int prime;
    int power;
    struct sFactor *next;
} Factor;

// Given 3 linked lists that represent 3 positive integers, please write
// a function to find the Greatest Common Divider (GCD) of those 3 integers.
// The function returns a linked list of prime factors and their associated
// powers.

Factor *GCD3(Factor *A, Factor *B, Factor *C)
{

	Factor *head = NULL;			// Point to the 1st node of factorized N
	Factor *tail;					// Point to the last node of factorized N
	Factor *new;					// Point to the newly created node

	while (A != NULL && B != NULL && C != NULL) {
											// Until one of A B C point to NULL
		if (A->prime < B->prime ||
			A->prime < C->prime) {			// If this factor of A is smaller
			A = A->next;					//		Look for larger factor of A
		} else if (B->prime < A->prime
				   B->prime < C->prime) {	// If this factor of B is smaller
			B = B->next;					//		Look for larger factor of B
		} else if (C->prime < A->prime
				   C->prime < B->prime) {	// If this factor of B is smaller
			C = C->next;					//		Look for larger factor of C
		} else {							// If these factors are equal
			new = (FACTOR *)malloc(sizeof(FACTOR)); // Allocate a block of
			if (new == NULL)						//    memory and test to see
				exit(EXIT_FAILURE);					//    if it's a null pointer
			new->prime = A->prime;		// Save this factor into the new node
			new->power = A->power;		// Finding the smaller power to save
			if (new->power < B->power)
				new->power = B->power;	// Power of B is smaller so save it
			if (new->power < C->power)
				new->power = C->power;	// Power of C is smaller so save it
			new->next = NULL;		// Mark the end of this linked list
			if (head == NULL)		// If this new node is the 1st node created
				head = new;			//		Make head point to this new node
			else					// Otherwise
				tail->next = new;	//		Make tail->next point to new node
			tail = new;				// Make tail point to the newly created node
			A = A->next;			// Look for larger factor of A
			B = B->next;			// Look for larger factor of B
			C = C->next;			// Look for larger factor of C
		}
	}

	return head;					// Return the 1st node of the GCD of A and B

}
