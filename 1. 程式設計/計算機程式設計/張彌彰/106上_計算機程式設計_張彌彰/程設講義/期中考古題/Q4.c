// Q4 u105061230 郭承賢
// Given two positive integers a and b, we say b divides a if (a % b ==0).
//
// Please write a C program to prompt for 2 integers, N1 and N2,
// and then print out all prime numbers, p, such that p divides N1 but not N2.
//
// Example program output:
// $ ./a.out
// Enter N1: 5775
// Enter N2: 20349
// Prime 1: 5
// Prime 2: 11
// Number of primes found: 2
//

#include <stdio.h>	//declare header

int main(void)		//start the function
{
	int N1,N2,num=1,i,j;
	//num store the order,i and j are used for finding primes
	printf("Enter N1: ");	//tell the user to input N1
	scanf("%d",&N1);		//store N1
	printf("Enter N2: ");	//tell the user to input N2
	scanf("%d",&N2);		//store N2
	if (N1%2 == 0 && N2%2 != 0) {	//test the prime "2"
		printf("Prime %d: 2\n", num);	
		//if 2 meet our requirement,print it 
		num++;	//add the order
	}
	for (i=3; i<N1/2; i+=2) {	//find the prime from odd number
		for (j=2; j*j<i && i%j != 0; j++) {
		}	//use square to find the prime
		if (j*j>i) {			//check if i is a prime
			if (N1%i == 0 && N2%i != 0) {	//test the prime i
				printf("Prime %d: %d\n", num, i);
				//if i meet our requirement,print it
				num++;	//add the order
			}
		}
	}
	printf("Number of primes found: %d\n", num-1);
	//print the total numbers
	return 0;	//if the function is correct,return value 0
}
