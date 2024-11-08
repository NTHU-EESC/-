// Q3 u107061112 王昊文
// Given the following recursion relation
//
// f(n) = 1,                if n == 0,
//                 1
//      = 1 + -----------,  otherwise.
//             1 + f(n-1)
//
// Please write a C program to approximate f(n) as n approaches infinite.
// Note this is can be done by finding n such that
//   | f(n) - f(n-1) | < 1e-7.
//
// Program output should have the following format:
// $ ./a.out
// f = 1.41421

#include <stdio.h>
#define eps 1e-7

double function();
int main(void)
{
	printf("f = %g\n", function()); 
	return 0;
}
double function()
{	
	int n, stay = 1;
	double Ans, temp_Ans = 1;
	for (n = 2; stay; n++) {
		Ans = 1 + (1 / (1 + temp_Ans));
		if (Ans - temp_Ans < 1e-7 && Ans - temp_Ans > -(1e-7))
			stay--;
		else 
			temp_Ans = Ans;
	}
	return Ans;
}
