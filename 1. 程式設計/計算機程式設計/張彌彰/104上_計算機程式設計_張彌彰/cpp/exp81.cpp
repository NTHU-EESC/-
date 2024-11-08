/*
 * exp81.cpp: this pointer and cascaded function calls
 *
 */

#include "exp80.h"
#include <iostream>
#include <cmath>

using namespace std;

Complex::Complex(double r, double i)
// : x(r), y(i)		// using initializer
{
	x=r;
	y=i;
}

void Complex::printComplex() const
{
	cout << "\n print using implicit handler (";
	cout << x << ", " << y << ")\n";
	cout << "\n print using this pointer     (";
	cout << this->x << ", " << this->y << ")\n";
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

Complex &Complex::incReal()
{
	x=x+1.0;
	return (*this);
}

Complex &Complex::incImag()
{
	y=y+1.0;
	return (*this);
}
