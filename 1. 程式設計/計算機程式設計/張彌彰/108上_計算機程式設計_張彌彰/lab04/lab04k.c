// EE231002 Lab04. Pythagorean Triples
// 108061112, 林靖
// Oct. 11, 2019

#include <stdio.h>

#define BOUND 20000

#define LIMIT 142

#define CALCULATE_gcdMN									\
	for (u = m, v = n; (u %= v) && (v %= u); ) ;		\
	gcdMN = u + v;

#define CALCULATE_ak_bk_ck_WHEN_k_IS_1		\
	ak = a = m * m - n * n;					\
	bk = b = 2 * m * n;						\
	ck = c = m * m + n * n;

#define CALCULATE_ak_bk_ck		\
	ak = a * k;					\
	bk = b * k;					\
	ck = c * k;

//34567891123456789212345678931234567894123456789512345678961234567897123456789
//epsilon ggg iii kkk

int main()
{
	unsigned short m, n;
	unsigned short u, v;
	unsigned short gcdMN;
	unsigned short a, b, c;
	unsigned short k;
	unsigned short ak, bk, ck;
	unsigned short count = 0;

	for (m = 2; m <= LIMIT; m += 2) {
		for (n = 1; n < m; n += 2) {
			CALCULATE_gcdMN;
			if (1 == gcdMN) {
				k = 1;
				CALCULATE_ak_bk_ck_WHEN_k_IS_1;
				while (ck <= BOUND) { 
					++count;
					printf("Pythagorean Triple #%u is (%hi,%hi,%hi)\n", count, ak, bk, ck);
					++k;
					CALCULATE_ak_bk_ck;
				}
			}
		}
	}

	for (m = 3; m <= LIMIT; m += 2) {
		for (n = 2; n < m; n += 2) {
			CALCULATE_gcdMN;
			if (1 == gcdMN) {
				k = 1;
				CALCULATE_ak_bk_ck_WHEN_k_IS_1;
				while (ck <= BOUND) { 
					++count;
					printf("Pythagorean Triple #%u is (%hi,%hi,%hi)\n", count, ak, bk, ck);
					++k;
					CALCULATE_ak_bk_ck;
				}
			}
		}
	}

return 0;
}
