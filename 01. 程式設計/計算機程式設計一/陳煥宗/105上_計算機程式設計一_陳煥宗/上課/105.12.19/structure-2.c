#include<stdio.h>

typedef
struct{
    int x;
    int y;
} Point; //struct的名稱

typedef double Real;
typedef int Integer;
int main(void)
{
    Point pt[10];
    Integer x = 3;
    Real z = 2.3;

    pt[0].x = 3;
    pt[0].y = 5;

    Point poi = {5, 7};
    Point *pp;

    pp = &poi;
    (*pp).x = 10;
    pp->x = 10; //用在指標

    return 0;
}
