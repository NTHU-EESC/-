// Q2 u104061212 馮立俞
// Given a string, please write a function to count the number of capital
// letters in the string. For example, if the string is
//
//   char *str = "Today is Monday. And everyone works today."
//
// Then countCap(str) returns 3.
#include<stdio.h>
int countCap(char *str);
int main(void)
{
	printf("%d\n",countCap("HelWWWloWorld"));
	
	return 0;
}

int countCap(char *str)
{
	int i,sum;				//sum=N of Capital

	for (; *str != '\0'; str++) {
		if (*str < 91 && *str > 60) sum++;
	} 
	return sum;
}
