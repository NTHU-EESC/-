// It is known that for any positive integer N we can represent this number
// by a linked list of it's prime factors and the associated powers using the
// structure defined below. For this question, you are given two linked lists
// representing two integers, A and B, and you need to write a function that
// generates a new linked list, which represents the integer of A/GCD(A,B),
// that is, the resulting linked list is A divided by the greatest common
// divisor of A and B. This function AmodB(A, B) manipulates those two input
// linked lists only. No other functions should be called.
// Note that you can assume that the linked list has the prime factor arranged
// in ascending order.

#include <stdlib.h>

typedef struct factor {     // node for a prime factor
    int prime;              // prime factor
    int power;              // associated power
    struct factor *next;    // pointer for the next prime factor
} FACTOR;

FACTOR *AmodB(FACTOR *A, FACTOR *B) // return linked list of A/GCD(A,B)
{
	FACTOR *new, *old, *GCD = NULL, *result = NULL;
		// *new: pointer for current node in a linked list
		// *old: pointer for previous node in a linked list
		// *GCD: pointer for the first node of GCD linked list
		// *result: pointer for the first node of A/GCD linked list

	// stop the loop if either A or B is NULL
	while (A != NULL && B != NULL) {
		if (A->prime == B->prime) {       // if A's prime == B's prime
			new = malloc(sizeof(FACTOR)); // create a node
			new->prime = A->prime;        // store prime
			new->power = A->power > B->power ? B->power : A->power;
										  // store the smaller power
			A = A->next;                  // A goes to the next node
			B = B->next;                  // B goes to the next node
			if (GCD == NULL) {            // at the beginning of linked list
				GCD = old = new;          // set GCD = old = new
			} else {                      // at the middle of linked list
				old->next = new;          // old points to new
				old = new;                // old becomes new
			}	
		} else if (A->prime > B->prime) { // if A's prime > B's prime
			B = B->next;                  // B goes to the next node
		} else {                          // if A's prime < B's prime
			A = A->next;                  // A goes to the next node
		}
	}
	new = old = NULL;                     // initialize new and old
	while (A != NULL) {                   // stop the loop if A is NULL
		new = malloc(sizeof(FACTOR));     // create a node
		if (A->prime == GCD->prime) {     // if A's prime == GCD's prime
			if (A->power > GCD->power) {  // if A's power > GCD's power
				new->prime = A->prime;    // store prime
				new->power = A->power - GCD->power;
										  // store A's power - GCD's power
				if (result == NULL) {     // at the beginning of linked list
					result = old = new;   // set result = old = new
				} else {                  // at the middle of linked list
					old->next = new;      // old points to new
					old = new;            // old becomes new
				}
			}
			A = A->next;                  // A goes to next node
			GCD = GCD->next;              // GCD goes to next node
		} else {                          // if A's prime != GCD's prime or
										  // GCD == NULL
			new->prime = A->prime;        // store A's prime
			new->power = A->power;        // store A's power
			if (result == NULL) {         // at the beginning of linked list
				result = old = new;       // set result = old = new
			} else {                      // at the middle of linked list
				old->next = new;          // old points to new
				old = new;                // old becomes new
			}
			A = A->next;                  // A goes to next node
		}
	}
	
	return result;                        // return A/GCD linked list
}
