/*EE231002 Lab03 Pythogorean Triples 
*104061212,Li-yu,Feng
*Date 2015/10/12
*/

#include <math.h>
#include <stdio.h>

int main(void)
{

	int a,b,c,num;						//num represents nuber set counted
	double C,SUM;						//SUM=a^2+b^2
	num=0;
	
	for (a=1 ;a<=14142 ;a++){			//a,b Max.<=((20000^2)/2)^0.5~=14142
	for (b=a;b<=14142;b++){				//initially, b=a, so a<=b
		SUM=a*a+b*b;
		c=sqrt(SUM);				//compare to test if c is an int
		C=sqrt(SUM);
			if (c==C){
			printf("Pythagorean Triple #%d is (%d,%d,%d)\n",++num,a,b,c);
			}
		}
	}	
	printf("Total number of Pythagorean triples found is %d\n",num);
	return 0;

}
