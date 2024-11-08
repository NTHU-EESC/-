#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(float a[], int na, float b[], int nb, float c[]);
void show_array(float a[], int na);
void arrange(float a[], int na);

int main(void)
{
    float a[100]={0}, b[100]={0}, c[200]={0};
    int na, nb;
    int i, j;

    FILE *fin;
    fin = fopen("insertion.txt", "r");
    if (fin == NULL) {
        perror("insertion.txt");
        exit(EXIT_FAILURE);
    }

    fscanf(fin, "%d", &na);
    for (i=0; i<na; i++) {
        fscanf(fin, "%f", &a[i]);
    }

    fscanf(fin, "%d", &nb);
    for (i=0; i<nb; i++) {
        fscanf(fin, "%f", &b[i]);
    }

    show_array(a, na);
    printf("\n");

    show_array(b, nb);
    printf("\n");

    arrange(b, nb);
    merge(a,na,b,nb,c);
    show_array(c, na+nb);

    return 0;
}

void merge(float a[], int na, float b[], int nb, float c[])
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

void arrange(float a[], int na)
{
    int i, j;
    double x;

    for(i=0;i<na;i++){
        j = i;
        x = a[i];
        while(j>0 && a[j-1]>x){
            a[j] = a[j-1];
            j = j-1;
        }
        a[j] = x;
    }
}

void show_array(float a[], int na)
{
    if(na>0){
        printf("%.1f ",*a);
        show_array(a+1,na-1);
    }
}
