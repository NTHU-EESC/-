#include <stdio.h>	
int a, b, prime, testprime, total, found;
int main(void)		
{
	scanf("%d%d", &a, &b);
	for (prime=2;prime<=a ; prime++){
		found = 0;
		for (testprime=2; testprime*testprime<=prime&&prime%testprime != 0; testprime++){}
		
		if (testprime*testprime>prime&&a%prime == 0&& (b%prime)!= 0){
			total++;
			printf("prime %d, %d", total, prime);
		}
	}
	printf("total %d", total);
	return 0;
}
