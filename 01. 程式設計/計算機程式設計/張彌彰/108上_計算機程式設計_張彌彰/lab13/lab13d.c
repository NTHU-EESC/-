// EE231002 Lab13. Text Decoding
// 108061112, 林靖
// Date: Dec. 21, 2019

#include <stdio.h>

int main(void)
{
	int end = 0;
	int i;
	char dat[4];
	char tab[0x3F + 1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
						 "abcdefghijklmnopqrstuvwxyz"
						 "01234567890+/";
	scanf("---begin---\n");
	while (dat) {
		while ((dat[i] = getchar()) != '\n') ;
		if (dat[i] == '-')
			end = 1;
		else 
		for (j = 0; tab[j] != dat[i]; j++) ;
		dat[i] = j;
		if (i > 0)
			printf("%c",
				dat[i - 1] << i + i |
				dat[i] >> 6 - i - i);
	}
	return 0;
}
