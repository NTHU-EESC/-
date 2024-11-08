/*
 * exp8.cpp: this pointer and member function
 *    to compile: g++ exp8.cpp exp81.cpp
 */

#include <iostream>
#include "exp80.h"

using namespace std;

int main(void)
{
    Complex a(1.0, 1.0);
    Complex b(2.0, 2.0);

    cout << "a=";
    a.printComplex();
    cout << endl;
    
    a.incReal().incImag();

    cout << "a=";
    a.printComplex();
    cout << endl;
}
