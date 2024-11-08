/*
 * exp70.cpp: complex class implementation
 *
 */

#include "exp70.h"
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

Complex::Complex(double r, double i)
/* : x(r), y(i)		// using initializer */
{
	x=r;
	y=i;
}

void Complex::printComplex() const
{
	cout << "(" << x << ", " << y << ")";
/*	x=5;   */
}

double Complex::getReal() const
{
	return x;
}

double Complex::getImag() const
{
	return y;
}

double Complex::getMagnitude() const
{
	double z;

	z=sqrt(x*x+y*y);
	return z;
}

double Complex::getPhase() const
{
	double z;

	if (x==0) return 1.570814;
	z=atan(y/x);
	return z;
}
