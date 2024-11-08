/* EE231002 Lab11. Blackjack Strategy
   106061145, 黃俊瑋
   Date: 2017/12/15
*/ 

/* blackjack player functions
* 4 functions are needed
* bet_init: before cards are dealt, initial bet is made
* hit_or_stand: after cards are dealt, player needs to make a decision
* whether to hit or stand
* shuttle: when the decks of cards are all used, dealer reshuffle
* the decks, and each player is notified
* deal_one_card: when each card is dealt by the dealer, each player is
* notified what card is dealt
*
*/

#include <stdio.h>
#include "card.h"
extern int step_display;
extern int Nhand;
int flownum=0; // flownum
int numcards=1;	// number of cards dealt
double decks; // number of decks remaining
int truenum; // calculate truenum
char play4_name[7]="me";

// this function places a bet before cards are dealt
// input: the amount of credit left for the user
// output: how much the player want to bet for this round

int play4_bet_init(const int credit)
{
	step_display=0; // by turning off this, it speed up the game
	Nhand=1000; // number of hands to be played
	decks = (208-numcards)/52; // count decks
	truenum = flownum/decks; // count truenum
	if (credit>8000) return 5;
	else if (truenum>2) return 5*(truenum-1);
	else return 3; // count how much money to bet
}

// this function decides if to hit for more cards or not
// input: player's cards (and number of cards)
// dealer's cards (and number of cards)
// Note, at this time dealer has only one card
// output: 1 to hit; 0 to stand, 2: double (receive only 1 card), 
// 3: surrender

int play4_hit_or_stand(const struct CARD mycard[], int Nmycard,
						const struct CARD dealercard[], int Ndealercard)
{
	if (with_ace(mycard, Nmycard) == 1) {
		if (sum_cards(mycard, Nmycard) <= 17) { 
			if (dealercard[0].value == FIVE || 
				dealercard[0].value == SIX)  return 2;
			else if (dealercard[0].value == FOUR &&
				sum_cards(mycard, Nmycard) >= 15) return 2;
			else if (dealercard[0].value == THREE &&
				sum_cards(mycard, Nmycard) == 17) return 2;
			else return 1;
				
		}
		else if (sum_cards(mycard, Nmycard) == 17) {
			if (dealercard[0].value <= SIX) return 2;
			else if (dealercard[0].value >= NINE) return 1;
			else return 0;
		}
		else return 0;
	} // soft card

	else { 
		if (sum_cards(mycard, Nmycard) <= 7) {
			if (dealercard[0].value == JACK) return 3;
			else return 1;
		}
		else if (sum_cards(mycard, Nmycard) == 8) return 1;
		else if (sum_cards(mycard, Nmycard) == 9) {
			if (dealercard[0].value >= THREE &&
				dealercard[0].value <= SIX) return 2;
			else return 1;
		} 
		else if (sum_cards(mycard, Nmycard) == 10) {
			if (sum_cards(mycard, Nmycard) <= 9) return 2;
			else return 1;
		}
		else if (sum_cards(mycard, Nmycard) == 11) return 2;
		else if (dealercard[0].value <= SIX) {
			if (sum_cards(mycard, Nmycard) <= 3 &&
				sum_cards(mycard, Nmycard) == 12) return 1;
			else return 0;
		} 
		else if (sum_cards(mycard, Nmycard) >= 17) return 0;
		else if (dealercard[0].value <= NINE) return 1;
		else if (sum_cards(mycard, Nmycard) <= 13) return 1;
		else return 3;
	} // hard card
}

// this function is called when the cards are reshuffled
// input: none
// output: none
void play4_shuffle()
{
	numcards=0;
	flownum=0; // set variables back to 0
	return;
}

// this function is called when a card is dealt by the dealer
// input: the card being dealt
// output: none
void play4_deal_one_card(const struct CARD cd)
{
	numcards++; // add one to numcards
	if (cd.value <= SIX) flownum++; // if card value < 6, add one to flownum
	else if (cd.value >= TEN) flownum--; // if card value>10 flownum - 1
}
