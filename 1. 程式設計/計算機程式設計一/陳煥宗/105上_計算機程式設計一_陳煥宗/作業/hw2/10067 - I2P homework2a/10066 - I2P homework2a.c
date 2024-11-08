#include<stdio.h>
int main(void)
{
    int x,a,b;
    float z;
    scanf("%d",&x);
    a = x%10;
    b = x/100;
    z = (x*2.0-(b-a)*100-(a-b))/2.0;
    printf("%.1f\n",z);
    return 0;
}

