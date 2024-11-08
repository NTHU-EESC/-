// EE231002 Lab04. Pythagorean Triples
// 108061112, 林靖
// Oct. 11, 2019

#include <stdio.h>
#include <math.h>

//34567891123456789212345678931234567894123456789512345678961234567897123456

int main()
{
	double bound = 20000;
	double a, c;
	unsigned long b;
	unsigned long bSquare;
	unsigned long count = 0;

	for (a = 1; a <= bound ; a++) {
		for (c = 1; c <= bound; c++) {
			bSquare = c * c - a * a;
			if (0 != bSquare) {
				b = sqrt(bSquare);
				if (b * b == bSquare) {
					if (a <= b && b <= c) {
						printf("%lu %.0lf %lu %.0lf\n", ++count, a, b, c); 
					}
				}
			}
		}
	}
return 0;
}
