// Q1 u104061212 馮立俞
// A positive integer is said to be a perfect number if it is equal to the
// sum of its proper divider. That is, n (n>0) is perfect if
//
//   n = sum of all p, (p<n) and (n % p == 0)
//
// Please write a function to test if the input positive integer n is perfect
// or not. The function returns 1 if n is perfect, otherwise it returns 0.
//
// For example, isPerfect(28) returns 1.

int isPerfect(int n)
{
	int i,sum;

	for(i=2,sum=1;i<n;i++){		//
		if(n%i==0)sum += i;		//find factors and add them
	}
	if(sum==n)return 1;
	else return 0;

}
