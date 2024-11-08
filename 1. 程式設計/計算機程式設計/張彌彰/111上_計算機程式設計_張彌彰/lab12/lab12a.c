#include <stdio.h>
#include <stdlib.h>

typedef struct factor {
	int prime;
	int power;
	struct factor *next;
} FACTOR;

FACTOR *factorize(int N);
FACTOR *GCD(FACTOR *A, FACTOR* B, FACTOR *C);
FACTOR *LCM(FACTOR *A, FACTOR *B, FACTOR *C);
void write(FACTOR *A);

int main(int argc, char **argv)
{
	FACTOR *A, *B, *C, *gcd, *lcm;

	A = factorize(atoi(argv[1]));
	printf("A = ");
	write(A);
	B = factorize(atoi(argv[2]));
	printf("B = ");
	write(B);
	C = factorize(atoi(argv[3]));
	printf("C = ");
	write(C);
	gcd = GCD(A, B, C);
	lcm = LCM(A, B, C);
	printf("GCD = ");
	write(gcd);
	printf("LCM = ");
	write(lcm);
	return 0;
}

FACTOR *factorize(int N)
{
	int dev;
	FACTOR *new, *head = NULL, *tail = NULL;

	for (dev = 2; N > 1; dev++) {
		if (N % dev == 0) {
			new = (FACTOR *) malloc(sizeof(FACTOR));
			new->prime = dev;
			new->power = 0;
			new->next = NULL;
		}
		while (N % dev == 0) {
			new->power++;
			N /= dev;
		}

		if (head == NULL) head = new;
		else tail->next = new;
		tail = new;
	}
	return head;
}

FACTOR *GCD(FACTOR *A, FACTOR *B, FACTOR *C)
{
	FACTOR *Acurr = A, *Bcurr = B, *Ccurr = C;
	FACTOR *head = NULL, *new, *tail = NULL;
	int min;

	while(Acurr != NULL && Bcurr != NULL && Ccurr != NULL) {
		if (Acurr->prime < Bcurr->prime || Acurr->prime < Ccurr->prime) {
			Acurr = Acurr->next;
		}
		else if (Bcurr->prime < Acurr->prime || Bcurr->prime < Ccurr->prime) {
			Bcurr = Bcurr->next;
		}
		else if (Ccurr->prime < Acurr->prime || Ccurr->prime < Bcurr->prime) {
			Ccurr = Ccurr->next;
		}
		else if (Acurr->prime == Bcurr->prime && Acurr->prime == Ccurr->prime) {
			new = (FACTOR *) malloc(sizeof(FACTOR));
			new->prime = Acurr->prime;
			min = Acurr->power;
			if (Bcurr->power < min) min = Bcurr->power;
			if (Ccurr->power < min) min = Ccurr->power;
			new->power = min;
			new->next = NULL;
			if (head == NULL) head = new;
			else tail->next = new;
			Acurr = Acurr->next;
			Bcurr = Bcurr->next;
			Ccurr = Ccurr->next;
			tail = new;
		}
	}
	return head;
}

FACTOR *LCM(FACTOR *A, FACTOR *B, FACTOR *C)
{
	FACTOR *Acurr = A, *Bcurr = B, *Ccurr = C;
	FACTOR *head = NULL, *new, *tail = NULL;

	while (Acurr != NULL || Bcurr != NULL || Ccurr != NULL) {
		new = (FACTOR *) malloc(sizeof(FACTOR));
		new->next = NULL;
		if (Acurr->prime ==  Bcurr->prime && Acurr->prime == Ccurr->prime) {
			new->prime = Acurr->prime;
			new->power = Acurr->power;
			if (new->power < Bcurr->power) new->power = Bcurr->power;
			if (new->power < Ccurr->power) new->power = Ccurr->power;
			Acurr = Acurr->next;
			Bcurr = Bcurr->next;
			Ccurr = Ccurr->next;
		}
		else if ((Acurr->prime < Bcurr->prime && Acurr->prime < Ccurr->prime) || 
				(Acurr != NULL && Bcurr == NULL && Ccurr == NULL)) {
			new->prime = Acurr->prime;
			new->power = Acurr->power;
			Acurr = Acurr->next;
		}
		else if ((Bcurr->prime < Acurr->prime && Bcurr->prime < Ccurr->prime) || 
				(Bcurr != NULL && Acurr == NULL && Ccurr == NULL)) {
			new->prime = Bcurr->prime;
			new->power = Bcurr->power;
			Bcurr = Bcurr->next;
		}
		else if ((Ccurr->prime < Acurr->prime && Ccurr->prime < Bcurr->prime) || 
				(Ccurr != NULL && Acurr == NULL && Bcurr == NULL)) {
			new->prime = Ccurr->prime;
			new->power = Ccurr->power;
			Ccurr = Ccurr->next;
		}
		else if ((Acurr->prime == Bcurr->prime && Bcurr->prime < Ccurr->prime) ||
				(Acurr != NULL && Bcurr != NULL && Ccurr == NULL)) {
			new->prime = Acurr->prime;
			new->power = Acurr->power;
			if (new->power < Bcurr->power) new->power = Bcurr->power;
			Acurr = Acurr->next;
			Bcurr = Bcurr->next;
		}
		else if ((Bcurr->prime == Ccurr->prime && Ccurr->prime < Acurr->prime) ||
				(Bcurr != NULL && Ccurr != NULL && Acurr == NULL)) {
			new->prime = Bcurr->prime;
			new->power = Bcurr->power;
			if (new->power < Ccurr->power) new->power = Ccurr->power;
			Bcurr = Bcurr->next;
			Ccurr = Ccurr->next;
		}
		else if ((Ccurr->prime == Acurr->prime && Acurr->prime < Bcurr->prime) ||
				(Ccurr != NULL && Acurr != NULL && Bcurr == NULL)) {
			new->prime = Ccurr->prime;
			new->power = Ccurr->power;
			if (new->power < Acurr->power) new->power = Acurr->power;
			Ccurr = Ccurr->next;
			Acurr = Acurr->next;
		}
		if (head == NULL) head = new;
		else tail->next = new;
		tail = new;
	}
	return head;
}

void write(FACTOR* A) 
{
	int i;
	int product = 1;
	FACTOR *curr = A;

	while (curr != NULL) {
		for(i = 0; i < curr->power; i++) {
			product *= curr->prime;
		}
		if (curr->power == 1) {
			printf("%d ", curr->prime);
		} else {
			printf("%d ^ %d ", curr->prime, curr->power);
		}
		if (curr->next != NULL) printf("* ");
		curr = curr->next;
	}
	printf("= %d\n", product);	
}
