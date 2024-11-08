#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
    int x;
    struct _node *next;  //�ۤv�̭��]�t�ۤv�u��Ϋ���  //����g"Node"�A�]������compiler�ä����D"Node"
} Node;  //Node = struct node

int main(void)
{
    Node head = {0,NULL};
    Node * p;

    p = (Node*)malloc(sizeof(Node));
    p -> x = 1;
    p -> next = NULL;
    head.next = p;

    p = (Node*)malloc(sizeof(Node));
    p -> x = 2;
    p -> next = head.next;
    head.next = p;

    printf("%d %d %d\n", head.x, (head.next)->x, (head.next)->next->x);

    free(head.next);

    return 0;
}
