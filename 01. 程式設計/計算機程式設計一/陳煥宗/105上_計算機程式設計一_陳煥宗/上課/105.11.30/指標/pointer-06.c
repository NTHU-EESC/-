#include<stdio.h>
int main(void)
{
    double* p[101];
    double data[101];
    int i;

    for(i=0;i<101;i++) p[i] = &data[i];
    // *p[2] = data[2]
    p[1] = p[3];
    p[2] = p[3];
    p[5] = p[4];

    *p[1] = 2.5;
    *p[2] = 3.5;
    *p[4] = 1.5;

    for(i=1;i<=5;i++) printf("%f\n",*p[i]);

    return 0;

}
