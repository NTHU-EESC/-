// EE231002 Lab04. Pythagorean Triples
// 108061112, 林靖
// Oct. 11, 2019

#include <stdio.h>

//34567891123456789212345678931234567894123456789512345678961234567897123456789
//fff

int main()
{
	unsigned bound = 142;
	unsigned limit = 20000;
	unsigned m, n;
	unsigned u, v;
	unsigned a, b, c;
	unsigned k, ak, bk, ck;
	unsigned count;

	count = 0;

	n = 3;
	do {
		m = 2;
		do {
			u = m;
			v = n;
			while ((u %= v) && (v %= u)) ;
			if ((1) == (u + v)) {
				a = n * n - m * m;
				b = 2 * m * n;
				c = n * n + m * m;
				k = 1;
				ak = a;
				bk = b;
				ck = c;
				do {
					++count;
					printf("%u %u %u %u\n", count, ak, bk, ck);
					++k;
					ak = a * k;
					bk = b * k;
					ck = c * k;
				} while (ck <= limit);
			}
			m += 2;
		} while (m < n);
		n += 2;
	} while (n <= bound);

	n = 2;
	do {
		m = 1;
		do {
			u = m;
			v = n;
			while ((u %= v) && (v %= u)) ;
			if ((1) == (u + v)) {
				a = n * n - m * m;
				b = 2 * m * n;
				c = n * n + m * m;
				k = 1;
				ak = a;
				bk = b;
				ck = c;
				do {
					++count;
					printf("%u %u %u %u\n", count, ak, bk, ck);
					++k;
					ak = a * k;
					bk = b * k;
					ck = c * k;
				} while (ck <= limit);
			}
			m += 2;
		} while (m < n);
		n += 2;
	} while (n <= bound);
return 0;
}
