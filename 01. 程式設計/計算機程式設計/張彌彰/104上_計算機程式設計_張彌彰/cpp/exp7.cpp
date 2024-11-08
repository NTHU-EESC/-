/*
 * exp7.cpp: const object and const member functions
 *    to compile: g++ exp7.cpp exp71.cpp
 */

#include <iostream>
#include "exp70.h"
using namespace std;

int main(void)
{
    const Complex One(1.0, 0.0);
    Complex a(1.0, 1.0);
    Complex b(2.0, 2.0);

    cout << "a=";
    a.printComplex();
    cout << endl;

    a=One;
    cout << "a=";
    a.printComplex();
    cout << endl;

    cout << "One=\n";
    One.printComplex();
    cout << endl;
    cout << "real part=" << One.getReal() << endl;

/*    One=b;   */
}
