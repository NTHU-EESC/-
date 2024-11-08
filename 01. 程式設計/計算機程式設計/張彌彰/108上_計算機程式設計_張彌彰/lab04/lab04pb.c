// EE231002 Lab04. Pythagorean Triples
// 108061112, 林靖
// Oct. 11, 2019

#include <stdio.h>

#define BOUND 20000

#define LIMIT 141

#define CALCULATE_gcdMN								\
	for (u = m, v = n; (u %= v) && (v %= u); ) ;	\
	gcdMN = u + v;

#define CALCULATE_a_b_c			\
	ak = a = m * m - n * n;		\
	bk = b = 2 * m * n;			\
	ck = c = m * m + n * n;

#define CALCULATE_ak_bk_ck		\
	ak += a;					\
	bk += b;					\
	ck += c;

//34567891123456789212345678931234567894123456789512345678961234567897123456789
//p pb

int main()
{
	unsigned short m, n;
	unsigned short u, v;
	unsigned short gcdMN;
	unsigned short a, b, c;
	unsigned short ak, bk, ck;
	unsigned short count = 0;

	for (m = 2; m <= LIMIT; m += 2) {
		for (n = 1; n < m; n += 2) {
			CALCULATE_gcdMN;
			if (1 == gcdMN) {
				CALCULATE_a_b_c;
				if (ak < bk) {
					while (ck <= BOUND) {
						printf("Pythagorean Triple #%hu", ++count); 
						printf(" is (%hu,%hu,%hu)\n", ak, bk, ck);
						CALCULATE_ak_bk_ck;
					}
				} else {
					while (ck <= BOUND) {
						printf("Pythagorean Triple #%hu", ++count); 
						printf(" is (%hu,%hu,%hu)\n", bk, ak, ck);
						CALCULATE_ak_bk_ck;
					}
				}
			}
		}
	}

	for (m = 1; m <= LIMIT; m += 2) {
		for (n = 2; n < m; n += 2) {
			CALCULATE_gcdMN;
			if (1 == gcdMN) {
				CALCULATE_a_b_c;
				if (ak < bk) {
					while (ck <= BOUND) {
						printf("Pythagorean Triple #%hu", ++count); 
						printf(" is (%hu,%hu,%hu)\n", ak, bk, ck);
						CALCULATE_ak_bk_ck;
					}
				} else {
					while (ck <= BOUND) {
						printf("Pythagorean Triple #%hu", ++count); 
						printf(" is (%hu,%hu,%hu)\n", bk, ak, ck);
						CALCULATE_ak_bk_ck;
					}
				}
			}
		}
	}

	printf("Total number of Pythagorean triples found is %hu\n", count);
	return 0;
}
