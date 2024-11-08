// EE231002 Lab04. Pythagorean Triples
// 108061112, 林靖
// Oct. 11, 2019

#include <stdio.h>

//34567891123456789212345678931234567894123456789512345678961234567897123456789
//epsilon

int main()
{

int eff;
for (eff = 0; eff < 100; eff++) {

	unsigned short bound = 142;
	unsigned short limit = 20000;
	unsigned short m, n;
	unsigned short u, v;
	unsigned short a, b, c;
	unsigned short k, ck;
	unsigned short count = 0;

	for (n = 3; n <= bound; n += 2) {
		for (m = 2; m < n; m += 2) {
			u = m;
			v = n;
			while ((u %= v) && (v %= u)) ;
			if ((1) == (u + v)) {
				a = n * n - m * m;
				b = 2 * m * n;
				c = n * n + m * m;
				for (k = 1, ck = (c * k); ck <= limit; ck = (c * ++k)) {
					printf("%hi %hi %hi %hi\n", ++count, a * k, b * k, ck);
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

}

return 0;
}
