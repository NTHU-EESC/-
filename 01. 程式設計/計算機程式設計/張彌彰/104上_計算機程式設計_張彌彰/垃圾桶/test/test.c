#include <stdio.h>
#include <stdlib.h>

typedef struct num{
	int i;
	struct num *next;
} NUM;

void PRINT(NUM *p);

int main()
{
	int temp;
	NUM *head;
	NUM *p;

	head = malloc( sizeof(NUM) );
	p = head;
	scanf(" %d",&temp);
	while(temp > 0){
		p->i = temp;
		p->next = malloc(sizeof(NUM));
		p = p->next;
		scanf(" %d",&temp);
	}
	p=NULL;
	PRINT(head);

	return 0;
}

void PRINT(NUM *p)
{
	do{
		printf(" %d\n",p->i);
		p = p->next;
	}while(p!=NULL);
}
