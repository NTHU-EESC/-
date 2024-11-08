/*
 * exp4.cpp:
 *   reference parameters and variables
 */

#include <iostream>
using std::cin;
using std::cout;

void f(int a, int &b, int *c)
{
    cout << a <<' '<< b <<' '<< *c << "\n";
    a=20;
    b=30;
    *c=40;
    cout << a <<' '<< b <<' '<< *c << "\n";
}

int main(void)
{
    int a=1,b=2,c=3;

    cout << a <<' '<< b <<' '<< c << "\n";
    f(a,b,&c);
    cout << a <<' '<< b <<' '<< c << "\n";

/* reference variable must be initialized */
/* a and d are aliases to each other      */
    int &d=a;
    cout << a << ' ' << d << "\n";
    d=50;
    cout << a << ' ' << d << "\n";
}
