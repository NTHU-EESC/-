#include<stdio.h>
#include <stdlib.h>  //有malloc
void SeletionSort(int* a, const int n);
void check(int* a, int* b, int*n);

int n_f, diff = 0; //function "check" 的回傳值

int main(void)
{
    int i, j, k;
    int N[2];
    //int donate[100000] = {0};
    //int bank[100000] = {0};

    scanf("%d",&N[0]);
    int* donate = (int*)malloc(N[0]*sizeof(int)); //*
    for(i=0;i<N[0];i++) scanf("%d",&donate[i]);
    scanf("%d",&N[1]);
    int* bank = (int*)malloc(N[1]*sizeof(int)); //*
    for(i=0;i<N[1];i++) scanf("%d",&bank[i]);

    SeletionSort(donate, N[0]);
    SeletionSort(bank, N[1]);

    printf("L1\tL2\n");
    printf("%d\t%d\n", N[0], N[1]);

    check(donate, bank, N);

    printf("%d differences\n", diff);

    return 0;
}

void SeletionSort(int* a, const int n)
{
    int temp;
    int i, j, k;
    for(i=0; i<n; i++){
        j = i;
        for(k=i+1; k<n; k++) if(a[j]>a[k]) j = k;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

void check(int* a, int* b, int*n)
{
    int i, j, k;
    j = i = 0;
    while((i<n[0])&&(j<n[1])){
        if(a[i] == b[j]){
            printf("%d\t%d\n", a[i], b[j]);
            //a_f[n_f] = a[i]; b_f[n_f] = b[j];
            i++;
            j++;
        }
        else if(a[i] > b[j]){
            //a_f[n_f] = 0; b_f[n_f] = b[j];
            printf("\t%d\tX\n", b[j]);
            diff++;
            j++;
        }
        else{
            //a_f[n_f] = a[i]; b_f[n_f] = 0;
            printf("%d\t\tX\n", a[i]);
            diff++;
            i++;
        }
        n_f++;
    }
    if(i<n[0]){
        for(k=i;k<n[0];k++){
            //a_f[n_f] = a[k]; b_f[n_f] = 0;
            printf("%d\t\tX\n", a[k]);
            diff++;
            n_f++;
        }
    }
    if(j<n[1]){
        for(k=j;k<n[0];k++){
            //b_f[n_f] = b[k]; a_f[n_f] = 0;
            printf("\t%d\tX\n", b[k]);
            diff++;
            n_f++;
        }
    }
}

