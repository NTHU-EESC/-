#include<stdio.h>
int func1(void);
int func2(void);
int main(void)
{
func1();
return 0;
}
int func1(void)
{
func2();
return 0;
}
int func2(void)
{
printf("Hello world!\n");
return 0;}
