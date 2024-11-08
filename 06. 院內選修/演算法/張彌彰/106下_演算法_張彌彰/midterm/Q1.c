// Q1 104061212 馮立俞
// GOOGLE stock 3 largest increase/decrease
#include<stdio.h>
#include<stdlib.h>

typedef struct sSTKprice{
	int year, month,day;
	double price, change;
} STKprice;

typedef struct node{
	STKprice data;
	struct node *next;
}Node;

int main(){
	int Ndays;
	STKprice *Prices, inc[3], dec[3];
	int i;
	Node *head, *temp, *temp2;
	
	scanf("%d", &Ndays);
	Prices = malloc( Ndays * sizeof(STKprice));

	for (i = 0; i < Ndays; i++){
		scanf("%d %d %d %lf, ", &Prices[i].year, &Prices[i].month, &Prices[i].day,
								&Prices[i].price);
	}
	Prices[0].change = 0;
	for(i = 1; i< Ndays; i++)
		Prices[i].change = Prices[i].price - Prices[i-1].price;

	inc[0].change = 0;
	inc[1] = inc[2] = inc[0];

	dec[0].change = 0;
	dec[1] = dec[2] = dec[0];

	for(i = 0; i < Ndays; i++){
		if(Prices[i].change > inc[0].change){
			inc[2] = inc[1];
			inc[1] = inc[0];
			inc[0] = Prices[i];
		}
		else if(Prices[i].change > inc[1].change){
			inc[2] = inc[1];
			inc[1] = Prices[i];
		}
		else if(Prices[i].change > inc[2].change){
			inc[2] = Prices[i];
		}
	}


	for(i = 0; i < Ndays; i++){
		if(Prices[i].change < dec[0].change){
			dec[2] = dec[1];
			dec[1] = dec[0];
			dec[0] = Prices[i];
		}
		else if(Prices[i].change < dec[1].change){
			dec[2] = dec[1];
			dec[1] = Prices[i];
		}
		else if(Prices[i].change < dec[2].change){
			dec[2] = Prices[i];
		}
	}

	for(i = 0; i <3; i++){
		printf("inc:%d y%dm %dd %d$ %lf %lf\n",i, inc[i].year, inc[i].month, inc[i].day,
										inc[i].price,inc[i].change);
		printf("dec:%d y%dm %dd %d$ %lf %lf\n",i, dec[i].year, dec[i].month, dec[i].day,
										dec[i].price,dec[i].change);
	}
	

}
