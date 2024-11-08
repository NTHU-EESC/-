#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct _Node {

    int data;

    struct _Node *next;

} Node;

void rotate_link(Node** p, Node* p_n, Node* pt, int num);
void print_link(Node* p);

int main(void)
{
    int data, num;
    char ch;
    Node* head = NULL;
    Node* pt   = NULL;
    Node* new_pt;
    while(1){
        scanf("%d",&data);
        if(data > 0){
            new_pt = (Node*)malloc(sizeof(Node));
            new_pt->data = data;
            new_pt->next = NULL;
            if(pt == NULL){
                head = new_pt;
                pt   = new_pt;
            }else{
                pt->next = new_pt;
                pt = pt->next;
            }
        }
        else break;
    }
    scanf("%d", &num);
    rotate_link(&head,head->next,pt, num-1);
    if(num==1){
        pt->next = head;
        head = head->next;
        head->next = NULL;
    }
    print_link(head);

    return 0;
}

void rotate_link(Node** p, Node* p_n, Node* pt, int num)
{
    if(num>1){
        rotate_link(p, p_n->next, pt, num-1);
    }else if(num==1){
        pt->next = *p;
        *p = p_n->next;
        p_n->next = NULL;
    }
}

void print_link(Node* p)
{
    while((p->next)!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("%d",p->data);
}

