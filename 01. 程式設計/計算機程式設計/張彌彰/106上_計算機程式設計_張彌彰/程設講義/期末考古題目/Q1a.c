// Q1 u105061245 蕭郁澄
// A polynomial is constructed using the structure defined below.
// Please write a function to divide a polynomial P1 by a real number c, c!=0.
// For example, if P1 = a2 x^2 + a1 x + a0.
// Then after calling div(P1,c), it returns a new polynomial P2,
// P2 = a2/c * x^2 + a1/c * x + a0/c.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct sPoly {
    int degree;             // the degree of the node
    double coef;            // the coefficient of the node
    struct sPoly *next;     // pointer to the next node
} POLY;

POLY *divk(POLY *P1, double c);

int main(void)
{
	POLY *new1, *new2, *temp, *first=NULL;
	
	new1 = malloc (sizeof(POLY));
	new1->degree = 2;
	new1->coef = 6;
	new1->next = NULL;
	if (first == NULL) first=new1;
	else temp->next = new1;
	temp = new1;
	
	new2 = divk(new1, 2);
	
	printf("%lf", new2->coef);
	return 0;
}

POLY *divk(POLY *P1, double c)
{
	POLY *P2, *first=NULL, *temp;
	
	while (P1 != NULL) {
	P2 = malloc (sizeof(POLY));
	P2->degree = P1->degree;
	P2->coef = P1->coef/c;
	P2->next = NULL;
	if (first == NULL) first=P2;
	else temp->next = P2;
	temp = P2;
	
	P1=P1->next;
	P2=P2->next;
		
	}
	return first;
}
