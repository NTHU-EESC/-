#include<stdio.h>
int main(void)
{
    int x, b;
    int a[11];
    scanf("%d",&x);
    b = 0;
    x = x + 1;
    while(x!=0){
        a[b] = x%2;
        b++;
        x = x/2;

    }
    b--;
    printf("%d %d\n",a[0],a[2]);
    while(b>=0){
        printf("%d",a[b]);
        b--;
    }
    b++;
    while(a[b]==0){
        b++;
    }
    printf(" %d",b);
    return 0;
}
