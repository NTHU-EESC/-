// Q3 u104061212 馮立俞
// The trigonometric sine function can be approximated by the infinite
// series as
//               x^3     x^5     x^7     x^9
// sin(x) = x - ----- + ----- - ----- + ----- -  ....
//                3!      5!      7!      9!
//
// please write a function that given an input x, it calculates sin(x)
// with an accuracy of 1e-7, which is defined as a macro eps.
//
// For example, sine(3.1415926/4) = 0.707107
//              sine(3.1415926/6) = 0.5
//

#define eps 1e-7
#include<stdio.h>

double sine(double x);

int main(void)
{
	double x=3.1415926/6.0;
	printf("%lg",x);
	printf("%lg",sine(x));
}

double sine(double x)
{
	static double y=0,counter=-1;
	static int N=3;
	int i,j;
	double a,up,down;
	
	if(y==0)
		y=x;
	for(i=N,up=1;i>0;i--)
		up=up*x;
	for(j=N,down=1;j>0;j--)
		down=down*j;
	y += up/down*counter;
	counter *= -1;
	N += 2;
	a++;
	if(a>3)
		return y;
	sine(x);
}

