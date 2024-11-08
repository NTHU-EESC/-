#include <stdio.h>
#include <stdlib.h>
typedef struct _node {
    int x;
    struct _node *next;  //�ۤv�̭��]�t�ۤv�u��Ϋ���  //����g"Node"�A�]������compiler�ä����D"Node"
} Node;  //Node = struct node

int main(void)
{
    Node head = {0,NULL};
    Node *p, *q;

    int n, i;
    scanf("%d",&n);

    for(i=0;i<n;++i){
        p = (Node*)malloc(sizeof(Node));
        p -> x = i;
        p -> next = head.next;
        head.next = p;
    }

    /*for(i=0,p=head.next;i<n;++i){
        printf("%d->",p->x);
        p = p->next;
    }
    printf("NULL\n");*/

    //p=head.next;
    while(p!=NULL){
        printf("%d->",p->x);
        p = p->next;
    }
    printf("NULL\n");

    /*for(i=0,p=head.next;i<n;++i){
        q = p->next;
        free(p);
        p = q;
    }*/

    p=head.next;
    while(p!=NULL){
        q = p->next;
        free(p);
        p = q;
    }

    return 0;
}
