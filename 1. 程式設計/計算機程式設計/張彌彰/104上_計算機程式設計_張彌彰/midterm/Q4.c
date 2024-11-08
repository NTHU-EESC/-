// Q4 u104061212 馮立俞
// We know the first few prime numbers are
//   2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, ...
//
// Let P1, P2, P3, ..., be the prime numbers ordered in ascending order.
// Then P1=2, P2=3, P3=5, P4=7, and so on. Note that P5>(P4+P6), 11>(7+13)/2.
// A prime number satisfy this property is called a strong Prime.
// Thus, 11 is the first strong prime. The next strong prime is 17.
//
// Please write a C program to find the first 100 strong primes and print
// them output.
//
// Example program output:
// Strong prime #1: 11
// Strong prime #2: 17
// ...
//
// Note. You are free to create necessary functions.
#include <math.h>
#include <stdio.h>
#define N 100

int main(void)
{	
	int a=2,b=3,c=5;
	int counter=1;
	double x=6,i;

	for(;counter<3;x++){
		for(i=2; x/i != 0 && i<x;i++){};
		if(i==x){
			a=b;
			b=c;
			c=x;
			printf("%d  %d %d %d\n",i,a,b,c);
			counter++;
			if(a>(b+c)/2){
				printf("Strong prime #%d: %d",counter++,a);
			}
		}
	}
	return 0;
}
