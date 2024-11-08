#include<stdio.h>
int main(void){
    int a[40], c[40], d[40];
    int i, k, b;
    scanf("%d",&b);
    c[1] = 1;
    printf("%10d",c[1]);
    for(i=2; i<b+2; i++){

        for(k=2; k<i+1; k++){

            if(k==i)
                d[k] = 1;
            else
                d[k]=c[k]+c[k-1];
        }
        for(k=2; k<i+1; k++)
            c[k] = d[k];
    }
    for(k=2; k<b+2; k++)
        printf("%10d",c[k]);


    return 0;
}
