#include<stdio.h>

int f(int* z) //z = &(x+1)
{
    int i, n;
    n = z[-1]; //n = *(z-1) //�ҥHn����49
    for(i=0;i<n;i++){
        z[i] = 100.0 * i; //���m�W�����ﱼ
    }
}

int main(void)
{
    int x[50] = {49};
    int i;
    printf("%p %p\n",x,&x[0]);
    f(x+1);
    for(i=0;i<50;i++){
        printf("%d\n",x[i]); //Ū��&x[i]�W����
    }
    return 0;
}
