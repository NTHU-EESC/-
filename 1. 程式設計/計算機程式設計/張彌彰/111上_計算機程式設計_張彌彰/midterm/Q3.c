// Q3 
// Please write a C program to find all solutions for the following
// Diophantine equation
//
//  a^3 + b^3 = c^2
//
// for 1 <= a <= b <= c <= 500.
// Your program should execute as efficiently as possible.
// Example program output is
//
// $ ./a.out
// Set #1: 1 2 3
// Set #2: a2 b2 c2
// ...
//   Number of solutions found: n
//

#include <stdio.h>
#include <math.h>
#define N 500

int main(void)
{
	int a, b, c, n = 0, end = 0;
		// a, b, c for the equation
		// n for index
		// end for checking whether c > N
	double c0;
		// c0 for checking whether fraction part is 0
	
	// find a, b, c
	for (b = 1; b <= N && end == 0; b++) {
		// b range from 1 to N 
		// loop will terminate if c > N
		for (a = 1; a <= b; a++) { // a range from 1 to b
			c = c0 = sqrt(a * a * a + b * b * b);
				// store double value into c0 and integer value into c
			if (c0 > N) { // check whether c is out of range
				end = 1;
			}
			if (c == c0 && end == 0) { // check the fraction part of c0
				++n;
				printf("Set #%d: %d %d %d\n", n, a, b, c);
			}
		}
	}
	// print total number of sets
	printf("  Number of solutions found: %d\n", n); 

	return 0;
}

