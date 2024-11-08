/*
 * exp61.c: class example, complex number, with separated interface and implementation
 *
 */

#include <iostream>
#include "exp60.h"

using std::cin;
using std::cout;

int main(void)
{
	Complex a(1.0, 1.0);
	Complex b(2.0, 2.0);

	cout << "a=";
	a.printComplex();
	cout << "\n";

	cout << "a real = " << a.getReal() << "\n";
	cout << "a imag = " << a.getImag() << "\n";
	cout << "a magnitude = " << a.getMagnitude() << "\n";
	cout << "a phase = " << a.getPhase() << "\n";

	cout << "b=";
	b.printComplex();
	cout << "\n";

	cout << "b real = " << b.getReal() << "\n";
	cout << "b imag = " << b.getImag() << "\n";
	cout << "b magnitude = " << b.getMagnitude() << "\n";
	cout << "b phase = " << b.getPhase() << "\n";

//	cout << "a.x=" << a.x << " a.y=" << a.y << "\n";
}
