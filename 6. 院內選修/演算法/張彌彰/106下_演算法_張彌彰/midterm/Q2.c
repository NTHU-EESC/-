// Q2 104061212 馮立俞
// GOOGLE 1000th lowest price of all time
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
	STKprice *Prices;
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
	
	printf("ok\n");

	head = malloc(sizeof(Node));
	head->next = malloc(sizeof(Node));
	head->data = Prices[0];
	head->next->data = Prices[1];
	
	for(i= 2; i < Ndays; i++){
		printf(" %d\n", i);
		temp2 = malloc(sizeof(Node));
		temp2->data = Prices[i];
		if(Prices[i].price <= head->data.price){
				temp2->next = head;
				head = temp2;
				continue;
		}
		for(temp = head; temp!= NULL; temp = temp->next){
			if(temp->next == NULL && Prices[i].price >= temp->data.price){
				temp->next = temp2;break;
			}
			else if(Prices[i].price <= temp->next->data.price && 
					Prices[i].price >= temp->data.price){
				temp2->next = temp->next;		
				temp->next = temp2;
				break;
			}

		}
		
	}

	for(i = 0, temp = head; i<1000; i++, temp = temp->next)
		printf("i= %d y %dm %dd %d $%g\n",i, temp->data.year, temp->data.month,
										temp->data.day, temp->data.price);
	

}

