/* EE231002 Lab03. Balanced Prime Numbers
   106061145, Jyun-Wei, Huang
   Date: 10/10/2017
*/

#include <stdio.h>
int main(void)

{
	int sum = 1, n, i, found, prev, mid, next;
	/* declare variables, 
	   sum = amount of balanced prime numbers, 
	   n, i = for loops, 
	   found = boolean, 
	   prev, mid, next = store prime numbers	
	*/
	for (n = 2; sum <= 1000 ; n++){				// test each number
		found = 0; 								// initialize found boolean
		for (i = 2; !found && i * i <= n; i++){	// a factor wouldn't exceed the square root of a checked number
			if (n % i == 0)						// check whether n has a factor
				found = 1;							// factor discovered, found = 1
		}
		if (!found){							// activates when found = 0, that is, factor wasn't discovered
			prev = mid;							// move number forward
			mid = next;							// move number forward
			next = n;							// store found prime number to the last
			
			if (mid * 2 == prev + next){		// check whether n is a balanced prime number
				if (sum <= 10 || sum >= 991)	// print first ten and last ten numbers
					printf("Balanced Prime Number #%d: %d\n", sum, mid); // print balanced prime number
			
			sum++;								// add 1 to the amount of balanced prime numbers
			}
		}
	}
	return 0;
}
