#include<stdio.h>
char x[10] = {0,'A','B','C','D','E','F','G','H','I'};
int main(void)
{
    int a,b,c,d;
    scanf("%d",&d);
    c = d%10;
    b = (d%100 - c)/10;
    a = (d-10*b-c)/100;
    printf("%c%c%c",x[a],x[b],x[c]);
    return 0;
}
