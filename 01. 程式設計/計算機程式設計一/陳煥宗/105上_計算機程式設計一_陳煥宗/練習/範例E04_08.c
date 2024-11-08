#include<stdio.h>
int main(void)
{
    int x;
    printf("Please enter three intergers:\n");
    scanf("%*d %d %*d",&x);
    printf("only the middle one is stored: %d",x);
    return 0;
}
