// EE231002 Lab12. Linked Lists
// 108061112, 林靖
// Date: Dec. 14, 2019

#include <stdio.h>
#include <stdlib.h>

typedef struct factor {				// node for a prime factor
	int prime;						// 		prime factor
	int power;						// 		associated power
	struct factor *next;			// 		pointer for the next prime factor
} FACTOR;

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

int main(int argc, char *argv[])
{
printf("\nint main(int argc, char *argv[]) called, argc = %d\n\n", argc);
	int i_A;
	int i_B;
	FACTOR *head_factorized_A;
	FACTOR *head_factorized_B;

	i_A = atoi(argv[argc - 2]);
	i_B = atoi(argv[argc - 1]);
printf("i_A = %d, i_B = %d\n", i_A, i_B);

	head_factorized_A = factorize(i_A);
	head_factorized_B = factorize(i_B);

	printf("A =");
	write(head_factorized_A);
	printf("B =");
	write(head_factorized_B);
	printf("GCD =");
	write(GCD(head_factorized_A, head_factorized_B));
	printf("LCM =");
	write(LCM(head_factorized_A, head_factorized_B));
	
printf("\nint main(int argc, char *argv[]) returning, 0\n\n");
	return 0;
}


// This function factorizes the input N into its prime factors and their
// 		associated powers, and returns a linked list that contains all these
// 		prime factors.
FACTOR *factorize(int N)
{
printf("\nFACTOR *factorize(int N) called, N = %d\n\n", N);
	int divisor = 2;
	FACTOR *p_head = NULL;
	FACTOR *p_tail;
	FACTOR *p_new;

	while(N > 1) {
printf("divisor = %d\n", divisor);
		if (N % divisor == 0) {
			p_new = (FACTOR *)malloc(sizeof(FACTOR));
			if (p_new == NULL) {
				puts("Error: malloc failed");
				exit(EXIT_FAILURE);
			}
			p_new->prime = divisor;
//puts("p_new->prime = divisor");
			for (p_new->power = 0;
				 N % divisor == 0;
				 N /= divisor,
				 p_new->power++) ;
			p_new->next = NULL;
//puts("p_new->next = NULL");
			if (p_head == NULL) {
				p_head = p_new;
//puts("p_head = p_new");
			} else {
				p_tail->next = p_new;
			}
			p_tail = p_new;
printf("prime = %d, power = %d\n", p_new->prime, p_new->power);
		}
		if (divisor >= 3)
			divisor += 2;
		else
			divisor += 1;
	}
printf("\nFACTOR *factorize(int N) returning\n\n");
	return p_head;
}

// This function takes two linked lists of prime factors as input, and finds the
// 		Greatest Common Divisor of these two inputs. Note that it returns a
// 		linked list of prime factors.
FACTOR *GCD(FACTOR *A, FACTOR *B)
{
printf("\nFACTOR *GCD(FACTOR *A, FACTOR *B) called\n\n");
	FACTOR *p_head = NULL;
	FACTOR *p_tail;
	FACTOR *p_new;

	while (A != NULL && B != NULL) {
printf("(A->prime, A->power) = (%d, %d)\n", A->prime, A->power);
printf("(B->prime, B->power) = (%d, %d)\n", B->prime, B->power);
		if (A->prime < B->prime) {
printf("A->prime < B->prime\n");
			A = A->next;
		} else if (A->prime > B->prime) {
printf("A->prime > B->prime\n");
			B = B->next;
		} else {
			p_new = (FACTOR *)malloc(sizeof(FACTOR));
			if (p_new == NULL) {
				puts("Error: malloc failed");
				exit(EXIT_FAILURE);
			}
			p_new->prime = A->prime;
			if (A->power < B->power)
				p_new->power = A->power;
			else
				p_new->power = B->power;
			p_new->next = NULL;
//puts("p_new->next = NULL");
			if (p_head == NULL) {
				p_head = p_new;
//puts("p_head = p_new");
			} else {
				p_tail->next = p_new;
			}
			p_tail = p_new;
printf("(p_new->prime, p_new->power) = (%d, %d)\n", p_new->prime, p_new->power);
			A = A->next;
			B = B->next;
		}
	}

printf("\nFACTOR *GCD(FACTOR *A, FACTOR *B) returning\n\n");
	return p_head;
}

// This function takes two linked lists of prime factors as input, and finds the
// 		Least Common Multiple of these two inputs. Note that it also returns a
// 		linked list of prime factors.
FACTOR *LCM(FACTOR *A, FACTOR *B)
{
printf("\nFACTOR *LCM(FACTOR *A, FACTOR *B) called\n\n");
	FACTOR *p_head = NULL;
	FACTOR *p_tail;
	FACTOR *p_new;

	while (A != NULL && B != NULL) {
printf("(A->prime, A->power) = (%d, %d)\n", A->prime, A->power);
printf("(B->prime, B->power) = (%d, %d)\n", B->prime, B->power);
		p_new = (FACTOR *)malloc(sizeof(FACTOR));
		if (p_new == NULL) {
			puts("Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		if (A->prime < B->prime) {
printf("A->prime < B->prime\n");
			p_new->prime = A->prime;
			p_new->power = A->power;
			A = A->next;
		} else if (A->prime > B->prime) {
printf("A->prime > B->prime\n");
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
printf("(p_new->prime, p_new->power) = (%d, %d)\n", p_new->prime, p_new->power);
		p_new->next = NULL;
//puts("p_new->next = NULL");
		if (p_head == NULL) {
			p_head = p_new;
//puts("p_head = p_new");
		} else {
			p_tail->next = p_new;
		}
		p_tail = p_new;
	}

	while (A != NULL) {
printf("(A->prime, A->power) = (%d, %d)\n", A->prime, A->power);
		p_new = (FACTOR *)malloc(sizeof(FACTOR));
		if (p_new == NULL) {
			puts("Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		p_new->prime = A->prime;
		p_new->power = A->power;
		p_new->next = NULL;
		if (p_head == NULL) {
			p_head = p_new;
//puts("p_head = p_new");
		} else {
			p_tail->next = p_new;
		}
		p_tail = p_new;
		A = A->next;
printf("(p_new->prime, p_new->power) = (%d, %d)\n", p_new->prime, p_new->power);
	}

	while (B != NULL) {
printf("(B->prime, B->power) = (%d, %d)\n", B->prime, B->power);
		p_new = (FACTOR *)malloc(sizeof(FACTOR));
		if (p_new == NULL) {
			puts("Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		p_new->prime = B->prime;
		p_new->power = B->power;
		p_new->next = NULL;
		if (p_head == NULL) {
			p_head = p_new;
//puts("p_head = p_new");
		} else {
			p_tail->next = p_new;
		}
		p_tail = p_new;
		B = B->next;
printf("(p_new->prime, p_new->power) = (%d, %d)\n", p_new->prime, p_new->power);
	}

printf("\nFACTOR *LCM(FACTOR *A, FACTOR *B) returning\n\n");
	return p_head;
}

// This function prints out all the prime factors and their associated powers.
// 		In addition, it recalculates the product of all the factors and prints
// 		out at the end.
void write(FACTOR *A)
{
printf("\nvoid write(FACTOR *A) called\n\n");
	int i;
	int product = 1;

	if (A == NULL)
		printf(" 1");

	while (A != NULL) {
		for (i = 0; i < A->power; i++)
			product *= A->prime;
		printf(" %d", A->prime);
		if (A->power > 1)
			printf("^%d", A->power);
		if (A->next != NULL)
			printf(" *");
		A = A->next;
	}

	printf(" = %d\n", product);

printf("\nvoid write(FACTOR *A) returning\n\n");
	return;
}

