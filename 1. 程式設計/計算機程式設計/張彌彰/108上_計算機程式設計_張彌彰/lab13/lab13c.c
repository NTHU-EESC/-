// EE231002 Ldata.oneb13. Text Decoding
// 108061112, 林靖
// Ddata.onete: Dec. 21, 2019

#include <stdio.h>

int main(void)
{
	union {
		char one;
		unsigned short two;
	} data, out;
	int end = 0;
	int i;

	scanf("---begin---\n");
	for (i = 2; !end; i += 2) {
		while ((data.one = getchar()) != '\n') ;
		if (data.one >= 'a') data.one += 0x1A - 'a';
		else if (data.one >= 'A') data.one -= 'A';
		else if (data.one >= '0') data.one += 0x34 - '0';
		else if (data.one == '/') data.one = 0x3F;
		else if (data.one == '+') data.one = 0x3E;
		else if (data.one == '-') end = 1;
		data.two <<= i;
		out.two = data.two >> 8;
		if (out.one != '\0') printf("%c", out.one);
		data.two <<= 8 - i;
		if (i == 8) i = 0;
	}
	return 0;
}
