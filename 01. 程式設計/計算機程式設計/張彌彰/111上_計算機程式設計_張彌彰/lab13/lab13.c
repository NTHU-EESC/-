// EE231002 Lab13. String Encoding
// 111060023, 黃柏霖
// Date: 2022/12/22

#include <stdio.h>						// i/o header

int main(void)
{
	char buff[4];						// buffer for 4 encoded chars
	char linelength;					// length of a line
	char org1, org2, org3;				// the original texts
	int i;								// loop index
	int group;							// group in a line of original text
	int end = 0;						// end condition

	scanf("begin\n");						// read in "start"
	while (end != 3) {						// stop when end condition is 3
		end = 0;							// initialize end condition
		linelength = getchar();				// get the first char as linelength
		if (linelength == 'e') {			// if the first char is 'e'
			end++;							// make end condition as 1
		}
		if (!(linelength & 0x20)) {			// if bit 5 of linelength is 0
			linelength = linelength - 64;	// make bit 6 of linelength to 0
		}
		group = linelength / 3;				// count how many group
		if (linelength % 3 != 0) group++;	// +1 group for left chars
		while (group-- > 0) {				// when can fill in or not ended
			for (i = 0; i < 4; i++) {		
				buff[i] = getchar();		// get four char for buffer
				if (end == 1) {				// if first char is e
					if (buff[i] == 'n') {	// and the second char is n
						end++;				// make end condition as 2
					}
				}
				else if (end == 2) {		// if "en" has appeared
					if (buff[i] == 'd') {	// and the third char is 'd'
						end++;				// make end condition as 3
					}
				}
				if (!(buff[i] & 0x20)) {	// if bit 5 of char is 0
					buff[i] &= ~(1 << 6);	// make its bit 6 to 0
				}
			}
			if (end != 3) {				// don't print if end condition is 3
				org1 = buff[0] << 2 | buff[1] >> 4;	// compute origin char 1
				org2 = buff[1] << 4 | buff[2] >> 2;	// compute origin char 2
				org3 = buff[2] << 6 | buff[3];		// compute origin char 3
				printf("%c%c%c", org1, org2, org3);	// print original text
			}
		}
	}
	return 0;							// end main function
}
