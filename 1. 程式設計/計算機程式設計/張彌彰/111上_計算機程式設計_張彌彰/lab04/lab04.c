// EE231002 Lab04. Pythagorean Triples
// 111060023, 黃柏霖
// Date: 2022/10/14

#include <stdio.h>						// include i/o header
#include <math.h>						// include math header

int main(void)
{
	double  a, b, c;					// the length of three sides
	unsigned short count = 0;			// count how many Pythagorean triples
	int max = 20000;					// the maximum length of  c	
	double sqrt2 = sqrt(2);				// set sqrt(2) as a const

 	for (c = 1; c <= max; c++) {		// find c
		for (a = 1; a < c /  sqrt2; a++) {	//each a is smaller than c / sqrt2
			b = sqrt (c * c - a * a);	// compute b
			if (b == (int)b) {			// determine whether b is int
			count++;					// number of Pythagorean sets +1
			printf("Pythagorean Triple #%d is (%lg, %lg, %lg)\n",
				count, a, b, c);		// print the set
			}
		}
	}
	printf("Total number of Pythagorean triples found is %d\n",
		count);							// print how many sets are found
	return 0;
}
