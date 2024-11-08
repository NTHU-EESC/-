// EE231002 Lab13. Text Decoding
// 110060007, ¶À«T¿o
// 2022/01/03

#include <stdio.h>

int main(void)
{
	int i, j;                     // variables for loops
	int cnt;                      // counter for row number in txt file
	char en[4];                   // four encoded text
	char en1_1, en1_2, en2_1, en2_2, en3_1, en3_2;
	// six parts' code consisting of original text
	char ori1, ori2, ori3;        // three original text
	int lead;                     // value of initial character

	scanf("begin");
	while ((lead = getchar()) != 'e') {
		cnt = (lead - '0') / 3;    // categorize 4 characters to a group
		if (lead % 3 != 0)	cnt++; // counter increment if have rest char
		// decode encoded text to original text
		for (; cnt > 0; cnt--) {
			for (j = 0; j < 4; j++) en[j] = getchar() - ' ';

			// reverse splitting from encoded text after subtracting ' '
			en1_1 = en[0] << 2;
			en1_2 = en[1] >> 4;
			en2_1 = en[1] << 4;
			en2_2 = en[2] >> 2;
			en3_1 = en[2] << 6;
			en3_2 = en[3];

			ori1 = en1_1 | en1_2;	// ascii code of first original text
			ori2 = en2_1 | en2_2;	// ascii code of second original text
			ori3 = en3_1 | en3_2;	// ascii code of third original text

			printf("%c%c%c", ori1, ori2, ori3); // print out result
		}
	}
	return 0;
}
