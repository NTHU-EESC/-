// EE231002 Lab02 Grouping Digits
// 111060023, 黃柏霖
// Date: 2022/9/26

#include <stdio.h>							// I/O header

int main(void)
{
	int N;									// the input of a large number
	int group1;								// the group of 1 ~ 10^3
	int group2;								// the group of 10^3 ~ 10^6
	int group3;								// the group of 10^6 ~ 10^9
	
	printf("Input a positive integer N (1000000000 < N < 2140000000): "
		);									// prompt for input
	scanf("%d", &N);						// get input
	group1 = N % 1000;						// compute the group1
	N /= 1000;								// make group1 disappear from N
	group2 = N % 1000;						// compute the group2
	N /= 1000;								// make group2 disappear from N
	group3 = N % 1000;						// compute the group3
	N /= 1000;								// make group3 disappear from N
	printf("N: %d,%3.3d,%3.3d,%3.3d\n", N, group3, group2,				//used "%03d" and get a minus of point, the current code is corrent now
		group1);							// print the answer
	return 0;
}
