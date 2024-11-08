#include <stdio.h>
#include <stdlib.h>
//#include "function.h"

void read_input(int* a, int* b, int N);
void write_output(int* b, int N);
int trace(int* a, int* b, int i);

int main(void) {
    char ch;
    int N,i,t;
    int a[100]={0}, b[100]={0};

    scanf("%d\n", &N);  // N <= 100
    read_input(a, b, N);
    for(i=0;i<N;i++) {
        trace(a, b, i); //for each person, do tracing!
    }
    write_output(b, N);

    return 0;
}

void read_input(int* a, int* b, int N)
{
    int i, j;
    for(i=0;i<N-1;i++){
        scanf("%d,",&a[i]);
    }
    scanf("%d",&a[N-1]);
    for(i=0;i<N-1;i++){
        scanf("%d,",&b[i]);
    }
    scanf("%d",&b[N-1]);
    /*for(i=0;i<N;i++){
        printf("%d ",a[i]);
    }
    for(i=0;i<N;i++){
        printf("%d ",b[i]);
    }*/
}

void write_output(int* b, int N)
{
    int i, j;
    for(i=0;i<N-1;i++) printf("%d,",b[i]);
    printf("%d",b[N-1]);
}

int trace(int* a, int* b, int i)
{
    int j;
    if(b[i]) return b[i];
    else{
        j = trace(a, b, a[i]-1);
        b[i] = j;
    }
}
