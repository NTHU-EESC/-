/* EE231002 Lab13. String Encoding
   106061145, 黃俊瑋
   Date: 12/30/2017
*/

#include <stdio.h>
int main(void)
{
	int ch1, ch2, ch3, ch4;	// store four inputs from teacher's file
	int ch21, ch22, ch31, ch32;	// save the modified the inputs 
								// ch2 break into ch21 and ch22
								// ch3 break into ch31 and ch32 
	int first, second, third;	// save the correct words
	int i, end = 0,suspectEnd = 0; 	// i = save line length
									// end and suspectEnd are booleans

	while (!end) { // repeat when end is not activated
	
		while (getchar() != '\n');	// skip first line or new line char
		
		i = getchar();	// read in line length char
		if (i == 'e') suspectEnd = 1; // if it's "e", suspect it's the end
		if ((~i & 1 << 5) && (i & 1 << 6)) i &= ~(1 << 6);	
		// check line length char
		// if bit 5 is 0 and if bit 6 is 1, set bit 6 to 0
		i = i / 3;	// divide line length char by 3
			
		for (; i > 0 && !end; i--) {	// we have i groups need to decode
			// read in two chars
			ch1 = getchar();
			ch2 = getchar();
			
			// if input "end", terminate the program
			if (suspectEnd && ch1 == 'n' && ch2 == 'd') end = 1;
			
			// keep doing if it's not the end
			if (!end) {
				// read in the next two chars
				ch3 = getchar();
				ch4 = getchar(); 
				
				// check all four chars
				if ((~ch1 & 1 << 5) && (ch1 & 1 << 6)) ch1 &= ~(1 << 6);
				if ((~ch2 & 1 << 5) && (ch2 & 1 << 6)) ch2 &= ~(1 << 6);
				if ((~ch3 & 1 << 5) && (ch3 & 1 << 6)) ch3 &= ~(1 << 6);
				if ((~ch4 & 1 << 5) && (ch4 & 1 << 6)) ch4 &= ~(1 << 6);
				
				// shift bits 
				ch1 <<= 2;
				ch21 = ch2 >> 4;
				ch22 = ch2 << 4;
				ch31 = ch3 >> 2;
				ch32 = ch3 << 6;
				
				// OR the modified bits together to form a new sequence of bits
				first = ch1 | ch21;
				second = ch22 | ch31;
				third = ch32 | ch4;
				
				// print result
				printf("%c%c%c", first, second, third);
			}
		}
	}
	printf("\n");
	return 0;
}
