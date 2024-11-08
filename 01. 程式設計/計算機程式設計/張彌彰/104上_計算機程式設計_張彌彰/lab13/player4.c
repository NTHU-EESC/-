/*EE231002 Lab13. Blackjack Strategy
  ID:104061212, Li-Yu,Feng
  Date:2015/12/25
*/

/* blackjack player functions
 * 4 functions are needed
 * bet_init: before cards are dealt, initial bet is made
 * hit_or_stand: after cards are dealt, player needs to make a decision
 * whether to hit or stand
 * shuffle: when the decks of cards are all used, dealer reshuffle
 * the decks, and each player is notified
 * deal_one_card: when each card is dealt by the dealer, each player is
 * notified what card is dealt
 */
#include <stdio.h>
#include "card.h"

static struct CARDCOUNT{
	struct CARD card;
	int Ncard;
}cardcount[52];

int Ntotalcard;
int cOunt=0;
extern int step_display;
extern int Nhands;
char play4_name[7]="Pen";


// this function places a bet before cards are dealt
// input: the amount of credit left for the user
// output: how much the player want to bet for this round
// algorithm:according to  high and low algorithm from Internet,bet higher
//if the card set appeal to us
int play4_bet_init(const int credit)
{

	step_display=0; // by turning off this, it speed up the game
	Nhands=10000; // number of hands to be played
	if(cOunt > 10)return cOunt;
	else return 3;
}
// this function decides if to hit for more cards or not
// input: player's cards (and number of cards)
// dealer's cards (and number of cards)
// Note, at this time dealer has only one card
// output: 1 to hit; 0 to stand, 2: double (receive only 1 card), 3: surrender
// algorithm: being safe as priority,double if a soft Ace is got
int play4_hit_or_stand(const struct CARD mycard[], int Nmycard,
		const struct CARD dealercard[], int Ndealercard)
{
	int i,point,Nsafecard = 0 ,Nbjcard=0,softsum = 0;

	point = sum_cards( mycard , Nmycard );
	for(i=0;i < 4*(21-point);i++)
		Nsafecard += cardcount[i].Ncard;			//number of safecard
	for(i=0;i < Nmycard;i++)
		softsum +=  card_point_hard( mycard[i] );	//hard or soft?
	for( i = 4*(21-point)-1 ; i > 4*(21-point-3)-1 ; i--)
		Nbjcard += cardcount[i].Ncard;				//chance to get bj?
		
	if ( is_blackjack(mycard,Nmycard)) return 0;
	else if( (double)Nbjcard / Ntotalcard > 0.55 &&
			with_ace( mycard , Nmycard ) && (point == softsum) ){
		return 2;
	}
	else if((double)Nsafecard / Ntotalcard > 0.5)
		return 1;
	else if (point<16)
		return 1;
	if(point>18) return 0;
	else if ((double)Nbjcard / Ntotalcard > 0.5)
		return 1;
	else if(point > 15 && sum_cards(dealercard,Ndealercard)>7)
		return 0;
	else return 0;
	
		
}
// this function is called when the cards are reshuffled
// input: none
// output: none
// algorithm:reinitialize cardcount array ,cOunt and Ntotalcard
void play4_shuffle()
{
	int i;

	for(i=0;i<52;i++){
		cardcount[i].Ncard = Ndeck;
	}
	Ntotalcard = 52* Ndeck;
	cOunt=0;

}
// this function is called when a card is dealt by the dealer
// input: the card being dealt
// output: none
// algorithm:count the cards
void play4_deal_one_card(const struct CARD cd)
{
	static int start=1;
	int i,j=0,k=0;

	if(start){
		for(i=0 ; i<52 ; i++){
			cardcount[i].card.suit = i % 4;
			cardcount[i].card.value = i / 4;	//from low to high value
			cardcount[i].Ncard = Ndeck;
		}
		Ntotalcard = 52 * Ndeck;
		cOunt=0;
		start=0;
	}
	for( i = 0 ; cd.suit != cardcount[i].card.suit || 
		cd.value != cardcount[i].card.value;i++)
	cardcount[i].Ncard--;					//find corresponding card
	Ntotalcard--;
	if(i < 30 && i > 3)
		cOunt ++;
	else if(i<4 ||i > 35)
		cOunt --;							//H & L algorithm from Internet

}
