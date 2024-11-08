#include<stdio.h>

int f(int* z) //z = &(x+1)
{
    int i, n;
    n = z[-1]; //n = *(z-1) //所以n取到49
    for(i=0;i<n;i++){
        z[i] = 100.0 * i; //把位置上的直改掉
    }
}

int main(void)
{
    int x[50] = {49};
    int i;
    printf("%p %p\n",x,&x[0]);
    f(x+1);
    for(i=0;i<50;i++){
        printf("%d\n",x[i]); //讀取&x[i]上的值
    }
    return 0;
}
