#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

void show_array(int arr[], int n);
void merge(int a[], int na, int b[], int nb, int c[]);

int main(void)
{
    int na, nb;
    int A[SIZE] = {0};
    int B[SIZE] = {0};
    int C[SIZE*2] = {0};

    int i;
    FILE *fin;

    fin = fopen("merge.txt", "r");
    if (fin==NULL) {
        perror("merge.txt");
        exit(EXIT_FAILURE);
    }

    fscanf(fin, "%d", &na);
    for (i=0; i<na; i++) {
        fscanf(fin, "%d", &A[i]);
    }

    fscanf(fin, "%d", &nb);
    for (i=0; i<nb; i++) {
        fscanf(fin, "%d", &B[i]);
    }

    show_array(A, na);
    printf("\n");

    show_array(B, nb);
    printf("\n");

    merge(A, na, B, nb, C);
    show_array(C, na+nb);
    printf("\n");

    return 0;
}
void show_array(int arr[], int n)
{
    if (n>0) {
        printf("%d ", *arr);
        show_array(arr+1, n-1);
    }
}
void merge(int a[], int na, int b[], int nb, int c[])
{
    if (na==0 && nb==0) {
        return ;
    } else if (na==0 && nb>0) {
        *c = *b;
        merge(a,na,b+1,nb-1,c+1);
    } else if (na>0 && nb==0) {
        *c = *a;
        merge(a+1,na-1,b,nb,c+1);
    } else {
        if(*a>*b){
            *c = *b;
            merge(a,na,b+1,nb-1,c+1);
        }
        else{
            *c = *a;
            merge(a+1,na-1,b,nb,c+1);
        }
    }
}
