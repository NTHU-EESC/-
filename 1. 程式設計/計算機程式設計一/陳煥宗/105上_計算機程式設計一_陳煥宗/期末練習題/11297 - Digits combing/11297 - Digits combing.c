#include <stdio.h>
#include <stdlib.h>
//#include "function.h"
int getAns(int *ar, int  n);
int cmp(const void *a, const void *b);
int main(){
    int digits[22];
    int i, n;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&digits[i]);
    }
    printf("%d\n",getAns(digits, n));
    return 0;
}

int getAns(int *ar, int  n)
{
    int i;
    int ans=0;
    qsort(ar,n,sizeof(int),cmp);
    /*for(i=0; i<n; i++){
        printf("%d",ar[i]);
    }*/
    if(ar[0]==0){
        for(i=1;i<n;i++){
            if(ar[i]!=0){
                ar[0] = ar[i];
                ar[i] = 0;
                break;
            }
        }
    }
    for(i=0;i<n;i++){
        ans = 10*ans+ar[i];
    }
    return ans;
}

int cmp(const void *a, const void *b)
{
    const int* va = (const int *)a;
    const int* vb = (const int *)b;
    return *va-*vb;
}
