/* EE2310 Lab08. Blackjack
   106061145, Jyun-Wei, Huang
   Date: 2017/11/20
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main(void)
{
	// printing table
	int point, hit, k, value, flag; 
	/*  point = 2 to 20
		hit = next hit 
		k = draw new card
		value = convert new card to number	
	*/
	double totexp, exp, tot, totbust, bust, counter;
	/*  totexp = adding total expected value
		exp = actual expected value 
		tot = actual total value = point + new card
		totbust = busted times
	*/

	printf("Points  E(hit)  %% Busted\n"); 
	
	for(point = 2; point < 21; point++) { // from 2 points to 20 points 
		printf("%4d", point);
		totexp = 0;
		tot = 0;
		exp = 0;
		totbust = 0;
		bust = 0;
		
		for(hit = 1; hit <= MAX; hit++) {
			k = rand() % 13 + 1;
			
			// 13 12 11 to 10, a to 1 or 11
			if (k >= 10) value = 10;
			else if (k == 1) {
				if (point > 10) value = 1;
				else value = 11;
			}
			else value = k;
			
			tot = value + point;
			if (tot > 21) totbust++;
			totexp += tot;
			
		}
		
		bust = totbust / MAX * 100;
		exp = totexp / MAX;
		printf("%10.2f %8.4g\n", exp, bust);
		
	}
	
	// calculating probability
	counter = 0;
	for (hit = 1; hit <= MAX; hit++) {
		
		tot = 0;
		flag = 0;
		
		while (tot < 21) {
		
			k = rand() % 13 + 1;
		
			if (k >= 10) value = 10;
			else if (k == 1) {
				if (tot + 11 > 21) value = 1;
				else {
					value = 11;
					flag = 1;
				}
			}
			else value = k;
			
			tot += value;

			if (tot > 21 && flag == 1) {
				tot -= 10; 
				flag = 0;
			}					
		}
		if (tot == 21) counter++;
	}
	
	printf("Probability of getting 21 points is %.2f%%\n", counter / MAX * 100);
		
	return 0;
}





			


