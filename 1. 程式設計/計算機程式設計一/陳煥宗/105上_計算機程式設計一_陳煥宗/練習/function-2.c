#include<stdio.h>
int func1(int);
int func2(int);
int main(void)
{
    int x;
    x = func1(100);
    printf("x = %d\n",x);
    return 0;
}
int func1(int x)//x=100
{
    return func2(x)+1;
}
int func2(int y)//y=100
{
    return y+1;
}
