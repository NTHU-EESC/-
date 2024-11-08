// Q3 110060007 黃俊穎
// Please write a program to find all solutions for the following
// Diophantine equation with 1 <= a, b, c <= max.
//
//    a + b^3 = c^2
//
// Example program output:
//
// $ ./a.out
// Sol 1: 1 + 2^3 = 3^2
// Sol 2: 8 + 2^3 = 4^2
// ...
// Number of solutions found: xx

#include <stdio.h>

#define max 100

int main(void)
{
    int a, b, c;                  // variables of the equation
    int b_max;                    // the upper bound of the variable b
	int nas = 0;                  // number of solutions found

	// start finding the b's maximum in the equation
	for (b = 1; b * b * b - max * max - max < 0; b++) {
    	b_max = b;                // find the maximum of b value
	}

	// start finding solutions of the equation
	for (c = 2; c <= max; c++) {
	    // c starts from 2 because a + b^3 is always larger than 1
		for (b = 1; b <= b_max; b++) {
			a = c * c - b * b * b;
			if (a > 0 && a <= max) {
			    // detect if a is between the valid range
				printf("Sol %d: %d + %d^3 = %d^2\n", ++nas, a, b, c);
				// show the results of all valid sets of solution
			}
		}
	}

	printf("Number of solutions found: %d\n", nas);
	// show the total number of solutions
	return 0;
}
