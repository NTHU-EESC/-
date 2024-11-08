// EE231002 Lab05. Blackjack Probabilities
// 111061234, 呂恆毅
// Date: 2022/10/17

#include <stdio.h>
#include <stdlib.h>

int main(void)                                  // I/O library
{
	int i, j;                                   // looping index
	int p, sum, determ;                         // points, currently sum,
	                                            // 	   a determination
	int A, ca;                                  // Currently, how many Ace,
	                                            // 	   how many card I have
	double to, canu;                            // total successful times,
	                                            // 	   and sum of the points

	printf(" Points  Probability  #Cards\n");    // output the title
	for (i = 4; i <= 21; i++) {                 // arrange the outputs by
	                                            // 	   its points
		canu = 0;                               // reset variable to 0
		to = 0;                                 // reset variable to 0
		for (j = 0; j < 100000; j++) {          // test for 100000 times
			sum = 0;                            // reset variable to 0
			A = 0;                              // reset variable to 0
			ca = 0;                             // reset variable to 0
			p = rand() % 13 + 1;                // ask for an arbitary point
			ca++;                               // change the amount of cards
			                                    // the points J Q K A should
			                                    //	   represent
			if (p > 10) p = 10;
			else if (p == 1) {
				p = 11;
				A++;                            // change how many A I have
			}
			sum = sum + p;                      // change the sum of points
			do {
				p = rand() % 13 + 1;            // ask for an arbitary point
				                                // the points J Q K A should
				                                // 	   represent
				if (p > 10) p = 10;
				else if (p == 1) {
					p = 11;
					A++;                        // change how many A I have
				}
				ca++;                           // change the amount of cards
				sum = sum + p;                  // change the sum of points
				                                // modify the point of A to 1
				if (sum > 21 && A != 0) {       //     necessary
					sum = sum - 10;             // change the sum of points
					A--;                        // change how many A I have
				}
				if (sum == i) {                 // if the sum of points match
					                            //     the target card number
					to++;                       // change the successful times
					canu = canu + ca;           // change the total card 
					                            //     numbers
					determ = 1;                 // change the determination
				}
				else if (sum > i) determ = 1;   // change the determination
				else determ = 0;                // change the determination
			}
			while (determ == 0);                // determine whether staying 
			                                    //     in the loop
		}
		canu = canu / to;                       // calculate the average
		                                        // 	   amount of cards
		to = to / 1000;                         // calculate the probabilaty
	                                            // output the result
		printf("%4d%12.2lf%%%10.2lf\n", i, to, canu);
	}
	return 0;
}
