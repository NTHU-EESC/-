// Q4 u107061112 王昊文
// Given two positive integers d and N, d < N, d is said to be a divisor
// of N if N % d = 0.
// A positive integer N is a perfect number if the sum of all its divisors
// equals to N. For example, 6 is a perfect number since it has 3 divisors:
// 1, 2 and 3, and 1 + 2 + 3 = 6.
//
// Please write a C program to find the first 4 perfect numbers.
//
// Example output:
// $ ./a.out
//   Perfect number #1: 6
//   Perfect number #2: ??
//   Perfect number #3: ??
//   Perfect number #4: ??
//

#include <stdio.h>

int main(void)
{
	int i, j;
	int sum = 0;
	int counter = 1;
	for (i = 3; ;i++) {
		for (j = 1; j < i; j++) {
			if (i % j == 0)
				sum += j;
		}
		if (sum == i) {
			printf("Perfect Number #%d: %d\n", counter, i);
			counter++;
		}
		else if (counter > 5)
			return 0;
		sum = 0;
	}
}
