/*
 * exp80.h: this pointer and cascaded function calls
 *
 */

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
  public:
    Complex(double=0,double=0);    // constructor
    void printComplex() const;     // print out real and imaginery
    double getReal() const;
    double getImag() const;
    double getMagnitude() const;
    double getPhase() const;
    Complex &incReal();
    Complex &incImag();
  private:
    double x,y;
};
#endif
