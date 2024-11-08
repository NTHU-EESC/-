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
//epsilon ggg iii lll nnn

int main()
{
	unsigned m, n;
	unsigned u, v;
	unsigned gcdMN;
	unsigned a, b, c;
	unsigned k;
	unsigned ak, bk, ck;
	unsigned count = 0;

	for (m = 2; m <= LIMIT; m += 2) {
		for (n = 1; n < m; n += 2) {
			CALCULATE_gcdMN;
			if (1 == gcdMN) {
				k = 1;
				CALCULATE_ak_bk_ck_WHEN_k_IS_1;
				do { 
					++count;
					printf("Pythagorean Triple #%u ", count); 
					printf("is (%u,%u,%u)\n", ak, bk, ck);
					++k;
					CALCULATE_ak_bk_ck;
				} while (ck <= BOUND);
			}
		}
	}

	for (m = 3; m <= LIMIT; m += 2) {
		for (n = 2; n < m; n += 2) {
			CALCULATE_gcdMN;
			if (1 == gcdMN) {
				k = 1;
				CALCULATE_ak_bk_ck_WHEN_k_IS_1;
				do { 
					++count;
					printf("Pythagorean Triple #%u ", count); 
					printf("is (%u,%u,%u)\n", ak, bk, ck);
					++k;
					CALCULATE_ak_bk_ck;
				} while (ck <= BOUND);
			}
		}
	}

return 0;
}
