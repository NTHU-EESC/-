// EE231002 Lab13. Text Decoding
// 108061112, 林靖
// Date: Dec. 21, 2019

#include <stdio.h>	// Standard input and output library.

int main(void)		// Called at program startup.
{
	int state = 0;	// Range 0~3 (every 4 char read in as a whole cycle).
	char new;		// Buffer, store a char newly read in.
	char x, y;		// 8-bit data (0x00~0x3F). Store latest two char converted.
	char tab[0x3F + 1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" // Table: convert "new" to
						 "abcdefghijklmnopqrstuvwxyz" //  8-bit data (0x00~0x3F)
						 "0123456789+/";			  //  and store it into "x".
	scanf("---begin---\n");					// Ignore the first line.
	new = getchar();						// Read first char in second line.
	while (new != '=' && new != '-') {		// Stop if the char is '=' or '-'.
		y = x;								// Free "x" to store the next 8-bit.
		for (x = 0x00;						// Look up the table and convert
			 tab[(int)x] != new;			//  "new" to 8-bit data (0x00~0x3F)
			 x++) ;							//  and store the data into "x".
		if (state > 0)						// When collected two 8-bit data.
			putchar(y << (state * 2) |		// Print the bits out as char after
					x >> (6 - state * 2)); 	//  shifting and "ORing" them.
		if (state == 3) state = 0;			// Update to next state and make
		else state++;						//  sure that it's in the range 0~3.
		while ((new = getchar()) == '\n') ;	// Read in the next char, skip '\n'.
	}
	return 0;								// Normal program termination.
}
