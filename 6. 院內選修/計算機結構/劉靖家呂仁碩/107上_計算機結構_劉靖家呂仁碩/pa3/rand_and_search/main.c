#include <stdio.h>
#include "util.h"

/**
 * Don't modify this
 */
#define __rand(x) rand_ ## x
#define _rand(x) __rand(x)
#define rand _rand(RAND_VER)

#define __search(x) search_ ## x
#define _search(x) __search(x)
#define search _search(SEARCH_VER)

/**
 * RAND_VER
 * 0: implement in main.c
 * 1: implement in rand_1.S
 * 2: implement in rand_2.S
 * 3: implement in rand_3.S
 */
#define RAND_VER 3

/**
 * SEARCH_VER
 * 0: implement in main.c
 * 1: implement in search_1.S
 * 2: implement in search_2.S
 * 3: implement in search_3.S
 */
#define SEARCH_VER 3

void rand(int32_t *a, int32_t len, int32_t seed);
int32_t search(int32_t *a, int32_t len, int32_t target);

void rand_0(int32_t *a, int32_t len, int32_t seed)
{
	a[0] = seed;
	for (int i = 1; i < len; i++) {
		int32_t tmp = a[i - 1];
		tmp = (tmp ^ (tmp << 1) ^ (tmp << 6) ^ (tmp << 7)) & 0x80;
		a[i] = (a[i - 1] >> 1) | tmp;
	}
}

int32_t search_0(int32_t *a, int32_t len, int32_t target)
{
	for (int32_t i = 0; i < len; i++)
		if (a[i] == target)
			return i;
	return -1;
}

#define NUM_SRCS 223
#define NUM_TGTS 10
int32_t srcs_c[NUM_SRCS], srcs_asm[NUM_SRCS];
int32_t tgts[NUM_TGTS] = {94, 300, 129, 246, 0, 2, 104, 256, 123, 65};
int32_t idxes_c[NUM_TGTS], idxes_asm[NUM_TGTS];

int compare(int32_t *nums_c, int32_t *nums_asm, int len, char *s)
{
	for (int i  = 0; i < len; i++) {
		if (nums_c[i] == nums_asm[i]) {
			printf("[%s %d] %d == %d\n", s, i, nums_c[i], nums_asm[i]);
		} else { 
			printf("[%s %d] %d != %d\n", s, i, nums_c[i], nums_asm[i]);
			return 1;
		}
	}
	return 0;
}

int main(void)
{
	const int32_t seed = 123;
	uintptr_t m, n;

	/* print configurations */
	printf("   ********************************\n");
	printf("   **  RAND   version = %d        **\n", RAND_VER);
	printf("   **  SEARCH version = %d        **\n", SEARCH_VER);
	printf("   ********************************\n\n");

	/* generating golden results, i.e., srcs_c and idxes_c */
	rand_0(srcs_c, NUM_SRCS, seed);
	for (int i = 0; i < NUM_TGTS; i++)
		idxes_c[i] = search_0(srcs_c, NUM_SRCS, tgts[i]);

	/* run your rand() and compare with the golden result (srcs_c) */
	m = read_csr(mcycle);
	rand(srcs_asm, NUM_SRCS, seed);
	n = read_csr(mcycle);
	printf("Comparing your rand() result with golden result\n");
	if (compare(srcs_c, srcs_asm, NUM_SRCS, "rand") != 0) {
		printf("Your rand() is wrong\n");
		return 2;
	} else {
		printf("Your rand() is correct, cycle count = %lu\n\n", (long)(n - m));
	}

	/* run your search() and compare with the golden result (idxes_c) */
	m = read_csr(mcycle);
	for (int i = 0; i < NUM_TGTS; i++)
		idxes_asm[i] = search(srcs_asm, NUM_SRCS, tgts[i]);
	n = read_csr(mcycle);
	printf("Comparing your search() result with golden result\n");
	if (compare(idxes_c, idxes_asm, NUM_TGTS, "search") != 0) {
		printf("Your search() is wrong\n");
		return 2;
	} else {
		printf("Your search() is correct, cycle count = %lu\n\n", (long)(n - m));
	}

	return 0;
}
