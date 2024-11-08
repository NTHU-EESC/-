/*
 * exp5.cpp: function with default parameters
 *
 */

#include <iostream>

using std::cin;
using std::cout;

void f(int a=1, int b=1, int c=1)
{
    cout << a <<' '<< b <<' '<< c << "\n";
}

int main(void)
{
	int a=10,b=20,c=30;

    cout << a <<' '<< b <<' '<< c << "\n";
	f(a,b,c);
	f(a,b);
	f(a);
	f();
}
