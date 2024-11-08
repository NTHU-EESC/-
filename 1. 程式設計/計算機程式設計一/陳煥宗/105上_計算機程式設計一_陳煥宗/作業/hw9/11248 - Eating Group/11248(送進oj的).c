#include <stdio.h>
#include <stdlib.h>
#include "function.h"

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
