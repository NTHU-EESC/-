// EE231002 Lab03. Roman Numerals
// 111060023 黃柏霖
// Date: 2022/10/3

#include <stdio.h>								// I/O header

int main(void)
{
	int num; 									// the int that key in
	int digit;									// digits of num

	printf("Input an integer between 1 and 3000: ");
												// prompt for the num 
	scanf("%d", &num);							// get num
	digit = num / 1000;							// thousands digit
	switch (digit) {							// switch by the digit
		case 3: printf("M");					// print M if it's 3
		case 2: printf("M");					// print M if it's >=  2
		case 1: printf("M");					// print M if it's >= 1
	}
	num %= 1000;								// remove the thousands digit
	digit = num / 100;							// hundreds digit
	switch (digit) {							// switch by the digit
		case 9: printf("CM");					// print CM if it's 9
				break;							// leave switch
		case 8: printf("DCCC");					// print DCCC if it's 8
				break;							// leave switch
		case 7: printf("DCC");					// print DCC if it's 7
				break;							// leave switch
		case 6: printf("DC");					// print DC if it's 6
				break;							// leave switch
		case 5: printf("D");					// print D if it's 5
				break;							// leave switch		
		case 4: printf("CD");					// print CD if it's 4
				break;							// leave switch
		case 3: printf("C");					// print C if it's 3
		case 2: printf("C");					// print C if it's >= 2
		case 1: printf("C");					// print C if it's >= 1
	}
	num %= 100;									// remove the hundreds digit
	digit = num / 10;							// tens digit
	switch (digit) {							// switch by digit
		case 9: printf("XC");					// print XC if it's 9
				break;							// leave switch
		case 8: printf("LXXX");					// print LXXX if it's 8
				break;							// leave switch
		case 7: printf("LXX");					// print LXX if it's 7
				break;							// leave switch
		case 6: printf("LX");					// print LX if it's 6
				break;							// leave switch 
		case 5: printf("L");					// print L if it's 5 
				break;							// leave switch
		case 4: printf("XL");					// print XL if it's 4
				break;							// leave switch
		case 3: printf("X");					// print X if it's 3
		case 2: printf("X");					// print X if it's >= 2
		case 1: printf("X");					// print X if it's >= 1
	}	
	num %= 10;									// remove the tens digit	
	switch (num) {								// switch by digit
		case 9: printf("IX");					// print IX if it's 9
				break;							// leave switch
		case 8: printf("VIII");					// print VIII if it's 8
				break;							// leave switch
		case 7: printf("VII");					// print VII if it's 7
				break;							// leave switch
		case 6: printf("VI");					// print VI if its' 6
				break;							// leave switch
		case 5: printf("V");					// print V if it's 5
				break;							// leave switch
		case 4: printf("IV");					// print IV if it's 4
				break;							// leave switch
		case 3: printf("I");					// print I if it's 3
		case 2: printf("I");					// print I if it's >= 2
		case 1: printf("I");					// print I if it's >= 1
	}
	printf("\n");								// print enter after all chars 
	return 0;
}
