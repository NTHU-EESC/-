#include<stdio.h>
void sort(double a [], int n) //�i�ۤv��g�@�������\��  //int f(double a[], int n) = int f(double* a, int n)  //�i�Ѧ�pointer-03
{
    int i, j;
    double x;

    for(i=0;i<n;i++){
        j = i;
        x = a[i];
        while(j>0 && a[j-1]>x){
            a[j] = a[j-1];
            j = j-1;
        }
        a[j] = x;
    }
}
int main(void){
    double data[101];
    double q;
    int i, n = 0;

    while(n<101 && scanf("%lf", &q)==1){
        data[n] = q;
        n++;
    }

    sort(data, n);

    for(i=0;i<n;i++){
        printf("%f\n",data[i]);
    }

    return 0;

}
