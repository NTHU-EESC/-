#include<stdio.h>
char x[10] = {0,'A','B','C','D','E','F','G','H','I'};
int main(void)
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%c%c%c",x[a],x[b],x[c]);
    return 0;
}
