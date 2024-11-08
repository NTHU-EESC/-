// Q4 u104061212 馮立俞
// Please write a program to find the probability of getting a pair of the
// same cards when 3 cards are randomly drawn from a perfectly shuffled
// deck of 52 cards. Your program should perform 10000 experiments. Each
// experiment starts with a deck of 52 cards, and 3 cards are drawn randomly.
// If two of the cards have the same value (different suits, of course) and
// the third card is different, then a successful experiment is recorded.
// Report the final probability in percent of success.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int _3card[3],sDeck[52]={0};
	int i,j,k;				//loop index
	int sum;				//success count

	for(k=0,sum=0 ; k<10000 ; k++){			//10000 experiment
		for(i=0;i<3;i++){
			for( ; sDeck[j=rand()%52] ; ){};	//deal 3 different cards
			_3card[i]=j/4;						//assign with their suit
			sDeck[j]=1;							//record card dealt
		}
		if(_3card[0]==_3card[1] && _3card[0]!=_3card[2] ||
		   _3card[0]==_3card[2] && _3card[0]!=_3card[1] ||
	   	   _3card[1]==_3card[2] && _3card[0]!=_3card[1] )sum++;//required situ
	}
	printf("success prob. :%g %%",(double)sum/10000*100);//print prob.
	return 0 ;
}

