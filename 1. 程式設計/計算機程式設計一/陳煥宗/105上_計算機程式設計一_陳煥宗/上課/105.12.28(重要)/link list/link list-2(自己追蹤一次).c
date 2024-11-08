#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
    int x;
    struct _node *next;  //自己裡面包含自己只能用指標  //不能寫"Node"，因為此時compiler並不知道"Node"
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
