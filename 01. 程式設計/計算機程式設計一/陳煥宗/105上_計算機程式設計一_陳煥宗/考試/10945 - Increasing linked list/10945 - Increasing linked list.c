#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void insert_increase_list(Node**, int);
void printList(Node *head);
void freeList(Node*);

int main() {
	Node *head = NULL;
	Node *temp;
	int data;

	while(1){
		scanf("%d", &data);
		if (data >= 0) {
			insert_increase_list(&head, data);
		} else break;
	}

	printList(head);
	freeList(head);
	return 0;
}

void freeList(Node *head)
{
	Node *temp;
	for(temp=head; temp!=NULL; temp=head)
	{
		head = head->next;
		free(temp);
	}
}

void printList(Node *head)
{
	Node *temp;
	for(temp = head; temp!=NULL; temp=temp->next)
	{
		printf("%d ", temp->data);
	}
	printf("\n");
}

void insert_increase_list(Node ** pt,int data){
	Node * new_pt;
	if(pt == NULL){
		new_pt = (Node*)malloc(sizeof(Node));
		new_pt->data = data;
		new_pt->next = NULL;
		*pt = new_pt;
	}else if(data <= (*pt)->data){
		new_pt = (Node*)malloc(sizeof(Node));
		new_pt->next = *pt;
		new_pt->data = data;
		*pt = new_pt;
	}else{
		insert_increase_list(&((*pt)->next) ,data);
	}
}

