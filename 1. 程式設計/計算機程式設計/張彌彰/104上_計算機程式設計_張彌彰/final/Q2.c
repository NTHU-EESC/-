// Q2 u104061212 馮立俞
// Given a string, please write a function to count the number of capital
// letters in the string. For example, if the string is
//
//   char *str = "Today is Monday. And everyone works today."
//
// Then countCap(str) returns 3.
#include<stdio.h>

int countCap(char *str)
{
	int i,sum;				//sum=N of Capital

	for(i=0,sum=0;*(str+i) != 0 ;i++){			//Find until NULL
		if(*(str+i)<91 && *(str+i) > 64)sum++;	//Compare with ASCII
	}
	return sum;
}
