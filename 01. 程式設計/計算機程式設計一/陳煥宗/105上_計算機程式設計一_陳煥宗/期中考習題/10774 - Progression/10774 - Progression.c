#include<stdio.h>
int main(void)
{
    int x,y,z;
    int i,k,j;
    int a[100],b[100];
    scanf("%d %d %d %d",&a[1],&a[2],&a[3],&a[4]);
    if((a[4]-a[3])==(a[3]-a[2])){
        printf("%d %d",a[4]+(a[2]-a[1]),a[2]-a[1]);
    }
    else{
        printf("%d %d",a[4]*(a[2]/a[1]),a[2]/a[1]);
    }
}
