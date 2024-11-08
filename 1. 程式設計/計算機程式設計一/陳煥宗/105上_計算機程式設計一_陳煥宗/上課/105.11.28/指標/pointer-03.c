#include<stdio.h>

int f(double z[], int n) //int f(double z[], int n) = int f(double* z, int n)
{
    int i;
    for(i=0;i<n;i++){
        *z = 100.0 * i;  // *z是一個double
        z++;  // z是一個指標，z++表到下一個位置
        //z[i] = 100.0 * i;
    }
}

int main(void)
{
    double x[50] = {/*100,200,300,400,500*/};
    int i;
    printf("%p\n",x);
    f(x,50);
    for(i=0;i<50;i++){
        printf("%f\n",x[i]);
    }
    return 0;
}


