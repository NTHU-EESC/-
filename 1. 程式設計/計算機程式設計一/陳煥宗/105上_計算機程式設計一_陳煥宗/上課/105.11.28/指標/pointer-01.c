#include<stdio.h>
// a pointer is a variable that can record some address
// x_addr = &x
int f(int* x_addr) //"*"取位置的其值
{
    printf("%lu bytes\n",sizeof(x_addr));
    printf("In f(): %p at %p\n",x_addr,&x_addr ); //"&"取其位置 //%p x_addr = x的位置 //%p &x_addr = x_addr自己的位置
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
