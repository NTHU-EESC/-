#include<stdio.h>
// a pointer is a variable that can record some address
// x_addr = &x
int f(int* x_addr) //"*"����m�����
{
    printf("%lu bytes\n",sizeof(x_addr));
    printf("In f(): %p at %p\n",x_addr,&x_addr ); //"&"�����m //%p x_addr = x����m //%p &x_addr = x_addr�ۤv����m
    *x_addr = 10; //"*"
}

int main(void)
{
    int x = 5;
    printf("%d at %p\n",x,&x);
    f(&x);
    printf("%d at %p\n",x,&x);
    return 0;
}
