// EE231002 Lab12. Linked Lists
// 108061112, 林靖
// Date: Dec. 14, 2019

#include <stdio.h>					// Standard input and output library
#include <stdlib.h>					// Defined malloc(), atoi(), EXIT_FAILURE

typedef struct factor {				// node for a prime factor
	int prime;						// 		prime factor
	int power;						// 		associated power
	struct factor *next;			// 		pointer for the next prime factor
} FACTOR;							// Linked list for each prime factor

FACTOR *factorize(int N);
// This function factorizes the input N into its prime factors and their
// 		associated powers, and returns a linked list that contains all these
// 		prime factors.

FACTOR *GCD(FACTOR *A, FACTOR *B);
// This function takes two linked lists of prime factors as input, and finds the
// 		Greatest Common Divisor of these two inputs. Note that it returns a
// 		linked list of prime factors.

FACTOR *LCM(FACTOR *A, FACTOR *B);
// This function takes two linked lists of prime factors as input, and finds the
// 		Least Common Multiple of these two inputs. Note that it also returns a
// 		linked list of prime factors.

void write(FACTOR *A);
// This function prints out all the prime factors and their associated powers.
// 		In addition, it recalculates the product of all the factors and prints
// 		out at the end.

int main(int argc, char *argv[])			// Called at program startup
{
	FACTOR *p_A;							// Point to 1st node of factorized A
	FACTOR *p_B;							// Point to 1st node of factorized B

	p_A = factorize(atoi(argv[argc - 2]));	// Take two command line arguments
	p_B = factorize(atoi(argv[argc - 1]));	//		as the inputs to the program

	printf("A =");
	write(p_A);								// Print factorized A out
	printf("B =");
	write(p_B);								// Print factorized B out
	printf("GCD =");
	write(GCD(p_A, p_B));					// Print the GCD of A and B out
	printf("LCM =");
	write(LCM(p_A, p_B));					// Print the LCM of A and B out
	
	return 0;								// Normal program termination
}

// This function factorizes the input N into its prime factors and their
// 		associated powers, and returns a linked list that contains all these
// 		prime factors.
FACTOR *factorize(int N)
{
	int divisor = 2;				// For testing whether N is divisible
	FACTOR *p_head = NULL;			// Point to the 1st node of factorized N
	FACTOR *p_tail;					// Point to the last node of factorized N
	FACTOR *p_new;					// Point to the newly created node

	while(N > 1) {					// Keep trying division until N becomes 1
		if (N % divisor == 0) {		// If N is divisible by the divisor
			p_new = (FACTOR *)malloc(sizeof(FACTOR)); // Allocate a block of
			if (p_new == NULL)						  //  memory and test to see
				exit(EXIT_FAILURE);					  //  if it's a null pointer
			p_new->prime = divisor;	
			for (p_new->power = 0;
				 N % divisor == 0;
				 N /= divisor,
				 p_new->power++) ;
			p_new->next = NULL;
			if (p_head == NULL) {
				p_head = p_new;
			} else {
				p_tail->next = p_new;
			}
			p_tail = p_new;
		}
		if (divisor > 2)
			divisor += 2;
		else
			divisor += 1;
	}

	return p_head;
}

// This function takes two linked lists of prime factors as input, and finds the
// 		Greatest Common Divisor of these two inputs. Note that it returns a
// 		linked list of prime factors.
FACTOR *GCD(FACTOR *A, FACTOR *B)
{
	FACTOR *p_head = NULL;
	FACTOR *p_tail;
	FACTOR *p_new;

	while (A != NULL && B != NULL) {
		if (A->prime < B->prime) {
			A = A->next;
		} else if (A->prime > B->prime) {
			B = B->next;
		} else {
			p_new = (FACTOR *)malloc(sizeof(FACTOR));
			if (p_new == NULL)
				exit(EXIT_FAILURE);
			p_new->prime = A->prime;
			if (A->power < B->power)
				p_new->power = A->power;
			else
				p_new->power = B->power;
			p_new->next = NULL;
			if (p_head == NULL) {
				p_head = p_new;
			} else {
				p_tail->next = p_new;
			}
			p_tail = p_new;
			A = A->next;
			B = B->next;
		}
	}

	return p_head;
}

// This function takes two linked lists of prime factors as input, and finds the
// 		Least Common Multiple of these two inputs. Note that it also returns a
// 		linked list of prime factors.
FACTOR *LCM(FACTOR *A, FACTOR *B)
{
	FACTOR *p_head = NULL;
	FACTOR *p_tail;
	FACTOR *p_new;

	while (A != NULL || B != NULL) {
		p_new = (FACTOR *)malloc(sizeof(FACTOR));
		if (p_new == NULL)
			exit(EXIT_FAILURE);
		if (B == NULL ||
			A != NULL && A->prime < B->prime) {
			p_new->prime = A->prime;
			p_new->power = A->power;
			A = A->next;
		} else if (A == NULL ||
				   B != NULL && A->prime > B->prime) {
			p_new->prime = B->prime;
			p_new->power = B->power;
			B = B->next;
		} else {
			p_new->prime = A->prime;
			if (A->power > B->power)
				p_new->power = A->power;
			else
				p_new->power = B->power;
			A = A->next;
			B = B->next;
		}
		p_new->next = NULL;
		if (p_head == NULL) {
			p_head = p_new;
		} else {
			p_tail->next = p_new;
		}
		p_tail = p_new;
	}

	return p_head;
}

// This function prints out all the prime factors and their associated powers.
// 		In addition, it recalculates the product of all the factors and prints
// 		out at the end.
void write(FACTOR *A)
{
	int i;
	int product = 1;

	if (A == NULL)
		printf(" 1");

	for ( ; A != NULL; A = A->next) {
		printf(" %d", A->prime);
		if (A->power > 1)
			printf("^%d", A->power);
		if (A->next != NULL)
			printf(" *");
		for (i = 0; i < A->power; i++)
			product *= A->prime;
	}

	printf(" = %d\n", product);

	return;
}
