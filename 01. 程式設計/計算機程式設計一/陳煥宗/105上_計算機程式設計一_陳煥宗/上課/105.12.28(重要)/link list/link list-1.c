#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
    int x;
    struct _node *next;  //自己裡面包含自己只能用指標  //不能寫"Node"，因為此時compiler並不知道"Node"
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
    //head = {0,NULL};  //上面兩行等同於此行

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
