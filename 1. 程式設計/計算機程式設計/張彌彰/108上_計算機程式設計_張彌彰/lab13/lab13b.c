// EE231002 Lab13. Text Decoding
// 108061112, 林靖
// Date: Dec. 21, 2019

#include <stdio.h>

int main(void)
{
	char a[4];
	int end = 0;
	int i;

	scanf("---begin---\n");
	while(!end) {
		for (i = 0; i < 4; i++) {
			a[i] = getchar();
			if (a[i] >= 'a') a[i] += 0x1A - 'a';
			else if (a[i] >= 'A') a[i] -= 'A';
			else if (a[i] >= '0') a[i] += 0x34 - '0';
			else if (a[i] == '/') a[i] = 0x3F;
			else if (a[i] == '+') a[i] = 0x3E;
			else if (a[i] == '\n') i--;
			else if (a[i] == '-') end = 1;
			if (i) printf("%c", a[i - 1] << 2 * i | a[i] >> 6 - 2 * i);
		}
	}
	return 0;
}
