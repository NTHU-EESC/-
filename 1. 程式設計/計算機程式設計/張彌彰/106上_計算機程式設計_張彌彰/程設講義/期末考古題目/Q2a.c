// Q2 u105061245 蕭郁澄
// Please write a function to find the number of 'i' or 'I' character
// given a string, STR.
// For example, if STR="I am very interested in computer programming."
// After calling countI(STR) it returns 4.
//

#include <stdio.h>
int countI(char *STR);
int main(void) 
{
	char sentence[80];
	int a;
	gets(sentence);
	a = countI(sentence);
	printf("no of i is %d", a);
	return 0;
}
int countI(char *STR)
{
	int count = 0, i;
	for (; *STR != '\0'; STR++) {
		if (*STR == 'i' || *STR == 'I') count++;
	}
	return count;
	}

