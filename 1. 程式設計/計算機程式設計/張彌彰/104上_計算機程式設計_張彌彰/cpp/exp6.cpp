/*
 * exp6.cpp: class example, complex number
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

class Complex {
  public:
    Complex(double=0,double=0);
    void printComplex();
    double getReal();
    double getImag();
    double getMagnitude();
    double getPhase();
  private:
    double x,y;
};

/* constructor */
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
    return sqrt(x*x+y*y);
}

double Complex::getPhase()
{
    if (x==0) {
        if (y==0) return 0;
        else if (y>0) return 1.570814;
        else return -1.570814;
    }
    return atan(y/x);
}

int main(void)
{
    Complex a(1.0, 1.0);
    Complex b(2.0, 2.0);

    cout << "a=";
    a.printComplex();
    cout << endl;

    cout << "a real = "  << a.getReal()      << endl;
    cout << "a imag = "  << a.getImag()      << endl;
    cout << "a mag = "   << a.getMagnitude() << endl;
    cout << "a phase = " << a.getPhase()     << endl;

    cout << "b=";
    b.printComplex();
    cout << endl;

    cout << "b real = "  << b.getReal()      << endl;
    cout << "b imag = "  << b.getImag()      << endl;
    cout << "b mag = "   << b.getMagnitude() << endl;
    cout << "b phase = " << b.getPhase()     << endl;

    a=b;

    cout << "a=";
    a.printComplex();
    cout << endl;

    /* exmple of not to access private members */
/*  cout <<"a.x="<< a.x <<" a.y="<< a.y <<"\n"; */
}
