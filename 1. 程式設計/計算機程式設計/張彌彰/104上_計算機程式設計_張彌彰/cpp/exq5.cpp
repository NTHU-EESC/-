/*
 * exq5.cpp: constructor/destructor
 *
 */

#include <iostream>
using namespace std;

/* complex number class */
class Complex {
public:
    /* uninit constructor */
    Complex() {};
    /* initialization constructor */
    Complex(double,double);
    /* copy constructor */
    Complex(Complex &);
    /* C1 + C2 */
    Complex  operator+(Complex);
    /* C1 += C2; */
    Complex& operator+=(Complex&);
    /* print to output */
    void print();
private:
    double x,y;
};
Complex::Complex(double r,double i=0)
{
    x=r; y=i;
}
Complex::Complex(Complex &a)
{
    x=a.x; y=a.y;
}
Complex Complex::operator+(Complex a)
{
    Complex z(x+a.x,y+a.y);
    return z;
}
Complex &Complex::operator+=(Complex& a)
{
    x += a.x;
    y += a.y;
    return (*this);
}
void Complex::print()
{
    cout << "(" << x << "," << y << ")";
}
int main(void)
{
    Complex One(1,0);
    Complex z1(3,0);
    Complex z2(0);
    Complex z3=One;

    {
        Complex z2;
        z2=z1+One;
        z2.print(); cout << endl;
    }
    z2 += One;
    z2.print(); cout << endl;
}
