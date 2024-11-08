// EE231004 Lab04. Roman Numerals
// 110060007, 黃俊穎
// 2021/11/01

#include <stdio.h>             // I/O library

int main(void)                 // start the main function
{
    char RN = 0;               // variables of Roman_Numerals
	int sum = 0;               // the final output value
    int cur;  		           // record current value
	int last = 0;              // former value of current value

    printf("Input Roman Numeral: ");

	while (RN != '\n') {       // keep looping as char doesn't end line
        scanf("%c", &RN);

    // start giving value of each letter and adding them together
        switch (RN) {
            case 'I': sum += 1; cur = 1; break;
            case 'V': sum += 5; cur = 5; break;
        	case 'X': sum += 10; cur = 10; break;
            case 'L': sum += 50; cur = 50; break;
            case 'C': sum += 100; cur = 100; break;
            case 'D': sum += 500; cur = 500; break;
            case 'M': sum += 1000; cur = 1000;
        }

		if (last != 0) {       // check last letter
		    if (cur > last) {  // decide carry law of Roman_Numerals
            sum -= 2 * last;   // minus extra added value
			}
		}
		last = cur;            // change the next comparison condition
    }
    printf("Integer value: %d\n", sum);  // print out the result

    return 0;                  // finish the main function
}
