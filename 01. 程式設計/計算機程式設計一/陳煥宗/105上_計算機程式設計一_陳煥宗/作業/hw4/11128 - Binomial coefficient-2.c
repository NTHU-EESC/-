#include <stdio.h>
int func(int i,int j)
{
	if(i == j || j == 0)
		return 1;
	else
		return(func(i-1,j-1)+func(i-1,j));
}

int main(void)
{
	int i=0;
	int input=0;
	int out[100];
	scanf("%d", &input);
	for(i=0;i<=input;i++)
	{
		out[i]= func(input,i);
		printf("%10d", out[i]);
	}
	return 0;
}
