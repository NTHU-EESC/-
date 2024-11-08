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

POLY *div(POLY *P1, double c)
{
	POLY *P2;		// P2 is a new poplyniminal.
	
	P2 = malloc(sizeof(P1));

	while ( P1 != NULL )
	{
		P2->degree = P1->degree;	// the degree is same.
		P2->coef = (P1->coef)/c;	//divide the coef of P1 by c.
		P1=P1->next;				// go to the next.
		P2=P2->next;				// go to the next.
	}
	return P2;
}

