// Q4 u105061245 蕭郁澄
// Given two positive integers a and b, we say b divides a if (a % b ==0).
//
// Please write a C program to prompt for 2 integers, N1 and N2,
// and then print out all prime numbers, p, such that p divides N2 but not N1.
//
// Example program output:
// $ ./a.out
// Enter N1: 20349
// Enter N2: 5775
// Prime 1: 5
// Prime 2: 11
// Number of primes found: 2
//

#include <stdio.h>

int N1, N2;						// two input numbers.
int P[1500];					// the array to store primes.

int prime (int n)
{	
	// the function is to find prime numbers.
	// if n is a prime number,then the function return 1.
	// else the function return 0.
	int div;					// div means divisor.

	if ( n == 1 ) return 0;		// 1 is not a prime number.
	for ( div = 2 ; div*div <= n ; div++ )
	{							// find the prime number.
		if ( n % div == 0) return 0;
	}							
	return 1;
}

int main(void)
{
	int i, j=1;					// index variables.
	int order=0;				// total number of primes.

	printf("Enter N1:");		
	scanf("%d" ,&N1);			// scanf the input N1.
	printf("Enter N2:");
	scanf("%d" ,&N2);			// scanf the input N2.
	
	P[0]=2;						// the first number is 2.
	for ( i=3 ; ( i*i <= N1 ) && ( i*i <= N2 ) ; i+=2 )
	{							
		// if n > 2, then all even numbers are not prime numbers.
		if(prime(i))			// call prime function to find prime numbers.
		{
			P[j] = i;			// assign prime number i to P[]. 
			j++;
		}
	}
	for ( i=0 ; i<j ; i++ )
	{
		if ( (N2 % P[i] == 0) && (N1 % P[i] != 0))
		{						
			// if the P[i] divises N2 and not divises N1,then P[i] is answer.
			order++;			// each time add 1 to order.
			printf("Prime %d: %d\n" , order , P[i]);
		}
	}
	printf("Number of primes found: %d\n" , order); 
	return 0;
}
