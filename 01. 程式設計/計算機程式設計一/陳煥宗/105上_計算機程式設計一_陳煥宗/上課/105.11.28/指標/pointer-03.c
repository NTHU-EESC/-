#include<stdio.h>

int f(double z[], int n) //int f(double z[], int n) = int f(double* z, int n)
{
    int i;
    for(i=0;i<n;i++){
        *z = 100.0 * i;  // *z�O�@��double
        z++;  // z�O�@�ӫ��СAz++���U�@�Ӧ�m
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


