// EE231002 Lab01 Unit Conversion
// 110060007, 黃俊穎
// 2022/01/01

#include <stdio.h>

int main(void)
{
    int us, feet, inch, final_inch; // needed units' declaration

    printf("Input length in centimeter:  ");   // request input centimeter
    scanf("%d", &us);               // scan the centimeter
	feet = us / (12 * 2.54);        // calculate total feet
	inch = us / 2.54;               // calculate total inches
	final_inch = inch - feet * 12;  // calculate actual inches
	printf("Length in US Costomary units: %d feet %d inches\n",
	feet, final_inch);              // present the answer
	return 0;                       // finish the program
}
