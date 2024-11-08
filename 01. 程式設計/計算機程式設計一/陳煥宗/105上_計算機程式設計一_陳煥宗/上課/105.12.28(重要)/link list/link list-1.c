#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
    int x;
    struct _node *next;  //�ۤv�̭��]�t�ۤv�u��Ϋ���  //����g"Node"�A�]������compiler�ä����D"Node"
} Node;  //Node = struct _node
/*

head|x|next|
        |
        V
        |x|next|
             |
             V
        np-> |x|next|

              */

int main(void)
{
    Node head;

    head.x = 0;
    head.next = NULL;
    //head = {0,NULL};  //�W����浥�P�󦹦�

    head.next = (Node *) malloc (sizeof(Node));
    (head.next)->x = 1;
    (head.next)->next = NULL;
    printf("%d %d\n", head.x, (head.next)->x);
    free(head.next);

    Node * p;
    p = (Node*)malloc(sizeof(Node));
    p -> x = 1;
    p -> next = NULL;
    printf("%d %d\n", head.x, (head.next)->x);
    free(head.next);

    return 0;
}
