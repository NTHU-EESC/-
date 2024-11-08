// EE231002 Lab13. Text Decoding
// 108061112, 林靖
// Date: Dec. 21, 2019

#include <stdio.h>		// Standard input and output library.

int main(void)			// Called at program startup.
{
	char buf;			// Buffer: store a char read in.
	char dat[4];		// Every 4 char read in can convert to 3 char to print.
	int i = 0;			// Index for dat[], range: 0~3.
	char tab[0x3F + 1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" // Table: convert buf to
						 "abcdefghijklmnopqrstuvwxyz" //   8-bit range 0x00~0x3F
						 "0123456789+/";			  //   and store into dat[].
	scanf("---begin---\n");					// Ignore the first line.
	buf = getchar();						// Read first char in second line.
	while (buf != '=' && buf != '-') {		// Stop if the char is '=' or '-'.
		for (dat[i] = 0x00;					// Look up the table to convert the
			 tab[(int)dat[i]] != buf;		//   char stored in buf to 8-bit
			 dat[i]++) ;					//   range 0~0x3F and store in dat[]
		if (i > 0)							// When collected enough information
			putchar(dat[i - 1] << (i * 2) |	// Print out the bits as char
					dat[i] >> (6 - i * 2)); //   after shifting and "ORing" them
		if (i == 3) i = 0;					// Update index for dat[] and make
		else i++;							//   sure that i is in the range 0~3
		while ((buf = getchar()) == '\n') ;	// Read in the next char (skip '\n')
	}
	return 0;								// Normal program termination
}
