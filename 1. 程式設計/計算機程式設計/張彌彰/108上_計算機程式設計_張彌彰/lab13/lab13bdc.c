// EE231002 Lab13. Text Decoding
// 108061112, 林靖
// Date: Dec. 21, 2019

#include <stdio.h>

int main(void)
{
	char buf = 'A';
	int i = 3;
	char dat[4];
	char tab[0x3F + 1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
						 "abcdefghijklmnopqrstuvwxyz"
						 "0123456789+/";
	scanf("---begin---\n");
	while (buf != '=' && buf != '-') {
		for (dat[i] = 0x00;
			 tab[(int)dat[i]] != buf;
			 dat[i]++) ;
		if (i > 0)
			printf("%c",
				dat[i - 1] << (i * 2) |
				dat[i] >> (6 - i * 2));
		if (i == 3) i = 0;
		else i++;
		while ((buf = getchar()) == '\n') ;
	}
	return 0;
}
