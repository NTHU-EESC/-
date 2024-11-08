// Q1 
// To facilitate reading a large integer, please write a C program to read in
// an integer and then print it out with a comma inserted every third digits.
// Your program should contain LOOPs such that it can be more concise and
// easier to read. Example program executions are
//
// $ ./a.out
// Input an integer N, -214000000 <= N <= 214000000: 123456789
// 123,456,789
// $ ./a.out
// Input an integer N, -214000000 <= N <= 214000000: -98,765
// -98,765
//
// The first example above, user inputs 123456789.
// And the second example with input -98765.

#include <stdio.h>

int main(void)
{
	long int number; // input number
	int sign = 0, i, array[3], first, s; 
		// sign: check whether number is negative
		// i: counter for loops
		// array[3]: store number separated into three parts
		// first: find the greatest non-zero index
		// s: temporary number during calculating 

	printf("Input an integer N, -214000000 <= N <= 214000000: ");
	scanf("%ld", &number); // get number 
	if (number < 0) { // check the sign of number
		sign = 1;
		number *= -1; 
	}
	for (i = 0; i < 3; i++) { // separate number into three parts
		s = number % 1000; 
		array[i] = s;
		number = number / 1000;
	}
	for (i = 0; i < 3; i++) { // get the greatest non-zero index
		if (array[i] != 0) {
			first = i;
		}
	}
	if (sign == 1) { // if number is negative, add a minus sign 
		array[first] *= -1;
	}
	printf("%d", array[first]); // print the first part
	for (i = first - 1; i >=0; i--) { // print the remaining parts
		printf(",%.3d", array[i]);
	}
	printf("\n");
		
	return 0;
}

