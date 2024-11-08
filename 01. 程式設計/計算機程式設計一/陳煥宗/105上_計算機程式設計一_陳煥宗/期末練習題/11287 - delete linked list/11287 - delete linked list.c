#include <stdio.h>
#include <stdlib.h>
//#include "function.h"
#include<stddef.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void deleteNode(Node **,int);
Node* createList();

void printList(Node *head){
    Node *temp;
    for(temp = head; temp!=NULL; temp=temp->next) {
        printf("%d ", temp->data);
    }
}

void freeList(Node *head){
    Node *temp;
    for(temp=head; temp!=NULL; temp=head){
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *head;
    int data;

    head = createList();

    while(1){
        scanf("%d", &data);
        if(data>-1){
            deleteNode(&head,data);
        }else break;

    }

    printList(head);
    freeList(head);
    return 0;
}

Node* createList()
{
    Node* np;
    Node* head;
    int input;
    scanf("%d", &input);
    if(input==-1) return NULL; //***
    else{
        head = malloc(sizeof(Node));
        head->data = input;
        head->next = NULL;
        np = head;
        while(1){
            scanf("%d", &input);
            if(input>-1){
                np->next = (Node*)malloc(sizeof(Node)); //***
                np = np->next;
                np->data = input;
                np->next = NULL;
            }
            else break;
        }

    }
    return head;
}

void deleteNode(Node** head,int data)
{
    int i, j, k;
    Node* p = *head;
    Node* tmp;
    while(p->next != NULL){
        if(p->data == data){
            //tmp = *head;
            *head = p->next;
            free(p);
            p = *head;

        }
        else if(p->next->data != data) p = p->next;
        else{
            tmp = p->next;
            p->next = tmp->next;
            tmp->next = NULL;
            free(tmp);
        }
    }
}

/*void deleteNode(Node **head, int del){
    Node *np = *head, *nq = NULL;
    while(np->data == del){
        *head = np->next;
        free(np);
        np = *head;
    }
    while(np->next!=NULL){
        if(np->next->data == del){
            nq = np->next->next;
            free(np->next);
            np->next = nq;
        }
        else
            np = np->next;
    }
    return;
}*/
