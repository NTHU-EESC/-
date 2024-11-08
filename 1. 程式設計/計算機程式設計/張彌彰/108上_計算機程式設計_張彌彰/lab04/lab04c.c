// EE231002 Lab04. Pythagorean Triples
// 108061112, 林靖
// Oct. 11, 2019

#include <stdio.h>

//34567891123456789212345678931234567894123456789512345678961234567897123456789
//gamma

int main()
{
	unsigned long bound = 142;
	unsigned long limit = 20000;
	unsigned long m, n;
	unsigned long u, v;
	unsigned long a, b, c;
	unsigned long k;
	unsigned long count = 0;

	for (n = 3; n <= bound; n += 2) {
		for (m = 2; m < n; m += 2) {
			u = m;
			v = n;
			while ((u %= v) && (v %= u)) ;
			if ((1) == (u + v)) {
				a = n * n - m * m;
				b = 2 * m * n;
				c = n * n + m * m;
				for (k = 1; (c * k) <= limit; k++) {
					printf("%lu %lu %lu %lu\n", ++count, a * k, b * k, c * k);
				}
			}
		}
	}
	for (n = 2; n <= bound; n += 2) {
		for (m = 1; m < n; m += 2) {
			u = m;
			v = n;
			while ((u %= v) && (v %= u)) ;
			if ((1) == (u + v)) {
				a = n * n - m * m;
				b = 2 * m * n;
				c = n * n + m * m;
				for (k = 1; (c * k) <= limit; k++) {
					printf("%lu %lu %lu %lu\n", ++count, a * k, b * k, c * k);
				}
			}
		}
	}
return 0;
}
