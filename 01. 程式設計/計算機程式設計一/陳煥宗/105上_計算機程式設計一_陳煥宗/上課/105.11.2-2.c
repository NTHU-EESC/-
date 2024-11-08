#include<stdio.h>
void level(int n);
int main(void)
{
    level(10);
    return 0;
}
void level(int n)
{
    if (n==0) return;//不回傳任何值，因為void()
    else {
        printf("%d-->",n);
        level(n-1);
        printf("<--%d",n);
    }
}
