// EE231002 Lab04. Pythagorean Triples
// 108061112, 林靖
// Oct. 11, 2019

#include <stdio.h>

//34567891123456789212345678931234567894123456789512345678961234567897123456
//delta

int main()
{
	long double bound = 5000;
	long double m, n;
	long double e, d, f;
	long double a, b, c;
	long double count = 0;

	for (n = 1; n <= bound; n++) {
		for (m = 1; m <= bound; m++) {
			e = 2 * n * n;
			d = (2 * m - 1) * (2 * m - 1);
			f = 2 * n * d;
			a = d + f;
			b = e + f;
			c = d + e + f;
			if (c <= 100) {
				printf("%Lg %Lg %Lg %Lg\n", ++count, a, b, c);
			}
		}
	}
return 0;
}
