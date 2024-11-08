/*
 * exp60.cpp: complex member function implementation
 *
 */

#include "exp60.h"
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

Complex::Complex(double r, double i)
{
	x=r;
	y=i;
}

void Complex::printComplex()
{
	cout << "(" << x << ", " << y << ")";
}

double Complex::getReal()
{
	return x;
}

double Complex::getImag()
{
	return y;
}

double Complex::getMagnitude()
{
	double z;

	z=sqrt(x*x+y*y);
	return z;
}

double Complex::getPhase()
{
	double z;

	if (x==0) {
		if (y==0) return 0;
		else return 1.570814;
	}
	z=atan(y/x);
	return z;
}
