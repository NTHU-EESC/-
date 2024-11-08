#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define GNDINTERVAL 0.1

double  *groundscan(double a[6]);
double fx(double a[6] , double x);

int main()
{
	double a[6] = {1,0,-5,0,4,0};
	double  *p;
	int i;

	p = groundscan(a);

	for(i=0 ; i<5 ; i++)
		printf("%g\n",*(p + i) );

	//printf("%lg\n",fx(a,x));

	return 0;
}

double fx(double a[6] , double x)
{
	double sum = 0;
	int i;

	for(i = 5 ; i >= 0 ; i--)
		sum += a[5 - i] * powl( x , i );

	return sum;
}


double  *groundscan(double a[6])
{
	double x;
	double root[5];
	double *proot = root;
	int i;
	int ind;


	if  ( fx(a,-10) > 0 )   ind = 1;
	else    ind = -1;

	for(x = -10 , i = 0 ; x <= 10 ; x += GNDINTERVAL ) //+-10 COULD BE WIDENED
		if( ( fx( a , x ) * ind ) <= 0 ){
			ind *= -1;
			root[i++] = x;
		}

	return proot;
}
