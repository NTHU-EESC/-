#include <stdio.h>
#include <stdlib.h>
//#include "function.h"

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void rotateList(Node**,int);

void freeList(Node *head);
Node* createList();
void printList(Node *head);

int main() {
	Node *head = NULL;
	Node *temp;
	int data;
	int k;

    head = createList();
	scanf("%d",&k);
	rotateList(&head,k);
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

Node* createList(){
    Node* head = NULL;
    Node* temp = NULL;
    int data;

    while(1){
        scanf("%d",&data);
        if(data>-1){
            if (temp==NULL) {
                temp = (Node*) malloc(sizeof(Node));
                head = temp;
            } else {
                temp->next = (Node*) malloc(sizeof(Node));
                temp = temp->next;
            }
            temp->data = data;
            temp->next = NULL;
        } else break;
    }
    return head;
}

void printList(Node *head)
{
	Node *temp=head;
	printf("%d", temp->data);
	temp=temp->next;

	for(; temp!=NULL; temp=temp->next)
	{
		printf(" %d", temp->data);
	}
	printf("\n");
}

void rotateList(Node** head,int n){
	int i;
	Node* pt = *head;
	Node*new_head=NULL;
	for(i=1;i<n;i++)
		pt = pt->next;
	new_head = pt->next;
	pt->next = NULL;
	pt = new_head;
	while(pt->next !=NULL)
		pt = pt->next;
	pt->next = *head;
	*head = new_head;
}
