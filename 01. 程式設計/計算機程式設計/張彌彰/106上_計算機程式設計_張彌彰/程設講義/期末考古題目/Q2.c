// Q2 u105061245 蕭郁澄
// Please write a function to find the number of 'i' or 'I' character
// given a string, STR.
// For example, if STR="I am very interested in computer programming."
// After calling countI(STR) it returns 4.
//

#include <stdio.h>

int countI(char *STR)
{
	int i,num=0;	// i is index variable.
	//num to cout the number of 'i' or 'I' character.

	for( i=0 ; STR[i]!='\0'; i++){
  		if( STR[i]==73 || STR[i]==105){	
		//By ASCII ,73 is 'I' and 105 is 'i'.
			num++;
		}
	}
	return num;		// return the number of 'i' or'I' character.
}
