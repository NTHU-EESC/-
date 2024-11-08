// Q4
// In a poker game, each player gets 5 cards and the compare the ranking
// of the cards he/she gets. One of the ranking is "full-house", in which,
// two of the cards have the same point and the other three have the same
// point. For example, if the five cards are {2, 2, 6, 6, 6}, then it is
// a full-house. Please write a C program to perform 1,000,000 experiements
// to find the probability of getting a hand of full-house.
// Each experiment should draw five cards randomly using rand() function,
// and determine if it is a full-house. Program execution example is
// shown below.
//
// $ ./a.out
// The probability of getting a full-house is x.xx%
//

#include <stdio.h>
#include <stdlib.h>
#define N 1000000

int main(void)
{
	int card[5], k, i, exp = 0, valid = 0, n1 = 0, n2 = 0, tc = 0;
		// card[5]: get 5 cards in the beginning
		// k: random type of number ranging from 1 to 13
		// i: counter for loops
		// exp: experiment
		// valid: successful experiment
		// n1, n2: the number of card
		// tc: the number of type
	double p; // probability
	
	while (exp < N) { // test N times
		for (i = 0; i < 5; i++) { // get card[5]
			k = rand() % 13 + 1;
			card[i] = k;
		}	
		for (i = 0; i < 5; i++) { // get the number of type
			if (card[i] != card[0]) {
				++tc;
			}
		}	
		if (tc != 2) { // type number != 2 isn't valid
			++exp;
		} else {
			for (i = 0; i < 5; i++) { // calculate n1 and n2
				if (card[i] == card[0]) {
					++n1;
				} else {
					++n2;
				}
			}
			// check whether the combination is valid
			if ((n1 == 3 && n2 == 2) || (n1 == 2 && n2 == 3)) { 
				++exp;
				++valid;
			} else {
				++exp;
			}
		}
	}
	p = (double)valid / N * 100; // get p
	// print p
	printf("The probability of getting a full-house is %.2lf%%\n", p); 

	return 0;
}

