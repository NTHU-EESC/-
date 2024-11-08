// Q4 u105061245 蕭郁澄
// Please write a function to find the largest prime factor given three
// integers, A, B and C, A, B, C >= 1. That is, the function PrimeFactor
// finds the largest prime number k, such that k divides A, B, and C.
// If no such prime number exists, it returns 0.

#include <stdio.h>
#include <stdlib.h>

int PrimeFactor(int A,int B,int C)
{
	int i,j,k=1;	// index variables.
	int prime[1000]={0};
	int max=A;		// assume A is the max number among A,B and C.
	int con;		// con means condition.
	int pf=0;		// pf means the large prime factor.
	
	if ( A < B ) max=B;
	if ( A < C && max==A ) max=C;
	if ( B < C && max==B ) max=C;
	// find the max number of three input number.
	prime[0] = 2;
	// because '2' is the first prime number.
	for ( i=3 ; i <= max ; i++ ){
		con=1;
		for ( j=1 ; j*j<i && con ; j++ ){
			if ( i % j != 0) 
				con=1;
			else 			// con=0 means i is not a prime number.
				con=0;
			if ( ( j*j < i ) && ((j+1)*(j+1) > i ) && con){
				prime[k++]=i;
			}
		}
	}
	for ( i=0 ; i<k ; i++ ){
		if ( prime[i] != 0){
			if ( A % prime[i] == 0 ){
				if ( B % prime[i] == 0 ){
					if ( C % prime[i] == 0){
						pf = prime[i];		// pf is the primefactor.
					}
				}
			}
		}
	}
	return pf;
}

