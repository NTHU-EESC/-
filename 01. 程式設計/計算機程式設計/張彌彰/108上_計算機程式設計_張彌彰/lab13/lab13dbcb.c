// EE231002 Lab13. Text Decoding
// 108061112, 林靖
// Date: Dec. 21, 2019

#include <stdio.h>		// Standard input and output library.

int main(void)			// Called at program startup.
{
	char _in;			// Buffer: store a char read in.
	char x, y;			// Two 8-bit char: store info required to decode 1 char
	int i = 0;			// State, range: 0~3.
	char tab[0x3F + 1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" // Table: convert in to
						 "abcdefghijklmnopqrstuvwxyz" //   8-bit range 0x00~0x3F
						 "0123456789+/";			  //   and store into dat[].
	scanf("---begin---\n");					// Ignore the first line.
	_in = getchar();							// Read first char in second line.
	while (_in != '=' && _in != '-') {		// Stop if the char is '=' or '-'.
		x = y;								// Free y up to store the next char
		for (y = 0x00;						// Look up the table to convert the
			 tab[(int)y] != _in;				//   char stored in _in to 8-bit
			 y++) ;							//   range 0~0x3F and store in dat[]
		if (i > 0)							// When collected enough information
			putchar(x << (i * 2) |			// Print out the bits as char after
					y >> (6 - i * 2));		//   shifting and "ORing" them.
		if (i == 3) i = 0;					// Update index for dat[] and make
		else i++;							//   sure that i is in the range 0~3
		while ((in = getchar()) == '\n') ;	// Read in the next char (skip '\n')
	}
	return 0;								// Normal program termination
}
