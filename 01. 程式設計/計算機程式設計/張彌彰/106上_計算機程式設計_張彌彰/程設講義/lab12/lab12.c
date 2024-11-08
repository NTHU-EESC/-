/* EE231002 Lab12. GCD and LCM.
   106061145, ¿¿¿   
   Date: 12/20/2017
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct factor {		// node for a prime factor
	int prime;				// prime factor
	int power;				// associated power
	struct factor *next;	// pointer for the next prime factor
} FACTOR;

FACTOR *factorize(int N); // factorize num, N = num 
FACTOR *GCD(FACTOR *A, FACTOR *B); // set up GCD link, input *A and *B links
FACTOR *LCM(FACTOR *A, FACTOR *B); // set up LCM link, input *A and *B links
void write(FACTOR *A);		// print prime factors and powers, input *A link

int main(int argc, char *argv[])
{	
	int num1, num2;			// input nums
	FACTOR *A, *B;			// save links
	
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);	// convert input to num

	printf("A = ");
	A = factorize(num1);
	write(A);
	printf("B = ");
	B = factorize(num2);
	write(B);	// print factorized results
	
	printf("GCD = ");
	write(GCD(A, B)); // print GCD
	
	printf("LCM = ");
	write(LCM(A, B)); // print LCM
	
	return 0;
}

FACTOR *factorize(int N)
{
	int i, power; // i = each prime num, power = power num
	FACTOR *first = NULL, *temp, *new_factor; 	// linked list

	// divide num by each prime, until num = 1
	// increment power each time num is divided by the same prime
	for (i = 2; N != 1; i++) {
		power = 0;
		while (N % i == 0) {
			N /= i;
			power++;	
		}
		// set up linked list
		if (power != 0) {
			new_factor = malloc(sizeof(FACTOR));
			new_factor->prime = i;
			new_factor->power = power;
			new_factor->next = NULL;
			if (first == NULL) first = new_factor;
			else temp->next = new_factor;
			temp = new_factor;
		}
	}
	return first;	
}

FACTOR *GCD(FACTOR *A, FACTOR *B)
{
	// declare linked list pointers
	FACTOR *first = NULL, *temp, *new_factor = NULL; 
	
	// search for the common prime num, exit until a or b ended
	while ( A != NULL && B != NULL) {
		if (A->prime < B->prime) A = A->next; // shift A
		else if (A->prime > B->prime) B = B->next;	// shift B
		else {		
			// we found a common prime num!
			// store prime num
			new_factor = malloc(sizeof(FACTOR));
			new_factor->prime = A->prime; 
				
			// store smaller power
			if (A->power >= B->power) new_factor->power = B->power;
			else new_factor->power = A->power; 
			
			// connect nodes
			new_factor->next = NULL;
			if (first == NULL) first = new_factor;
			else temp->next = new_factor;
			temp = new_factor;	
			
			// shift A and B
			A = A->next;				
			B = B->next; 
		}
	}
	
	// if no CD, return 1 * 1, else return linked list
	if (new_factor == NULL) {
		new_factor = malloc(sizeof(FACTOR));
		new_factor->prime = 1;
		new_factor->power = 1;
		new_factor->next = NULL;
		return new_factor;
	}
	else return first;
}

FACTOR *LCM(FACTOR *A, FACTOR *B)
{
	// declare linked list pointers
	FACTOR *first = NULL, *temp, *new_factor; 
	
	// store all prime num, exit until a or b ended
	while ( A != NULL && B != NULL) {
		
		// if A and B has different prime num, store it
		// else, store bigger power one
		if (A->prime < B->prime) {
			new_factor = malloc(sizeof(FACTOR));
			new_factor->prime = A->prime;
			new_factor->power = A->power;
			new_factor->next = NULL;
			if (first == NULL) first = new_factor;
			else temp->next = new_factor;
			temp = new_factor;
			A = A->next; // shift A
		}
		else if (A->prime > B->prime) {
			new_factor = malloc(sizeof(FACTOR));
			new_factor->prime = B->prime;
			new_factor->power = B->power;
			new_factor->next = NULL;
			if (first == NULL) first = new_factor;
			else temp->next = new_factor;
			temp = new_factor;
			B = B->next;	// shift B
		}
		else {
			// we found a common prime num
			// store prime num
			new_factor = malloc(sizeof(FACTOR));
			new_factor->prime = A->prime; 
				
			// store bigger power
			if (A->power >= B->power) new_factor->power = A->power;
			else new_factor->power = B->power; 
			
			// connect nodes
			new_factor->next = NULL;
			if (first == NULL) first = new_factor;
			else temp->next = new_factor;
			temp = new_factor;
				
			// shift A and B
			A = A->next;				
			B = B->next; 
		}
		
	}
	// A or B has come to NULL, need to finish linking the remaining primes
	
	if  (A == NULL && B != NULL) { // B is the one remaining
		while (B != NULL) {
			new_factor = malloc(sizeof(FACTOR));
			new_factor->prime = B->prime;
			new_factor->power = B->power;
			new_factor->next = NULL;
			temp->next = new_factor;
			temp = new_factor;
			B = B->next;	// shift B
		}
	}
	else { // A is the one remaining
		while (A != NULL) { 
			new_factor = malloc(sizeof(FACTOR));
			new_factor->prime = A->prime;
			new_factor->power = A->power;
			new_factor->next = NULL;
			temp->next = new_factor;
			temp = new_factor;
			A = A->next;	// shift A
		}
	}
	// return linked list
	return first;
}

void write(FACTOR *A)
{
	int sum = 1, power; 	// initialize variables
	
	//	print linked list
	for (; A != NULL; A = A->next) {
		
		// if power = 1, don't need to print power, else, need
		if (A->power == 1) printf("%d", A->prime);
		else printf("%d^%d", A->prime, A->power);
		
		// if isn't last prime, print "*" sign
		if (A->next != NULL) printf(" * ");
		
		// save power num
		power = A->power; 
		
		// calculate total sum
		for (; power != 0; power--) {
			sum *= A->prime;
		}
	} 
	// print sum
	printf(" = %d\n", sum);
}
