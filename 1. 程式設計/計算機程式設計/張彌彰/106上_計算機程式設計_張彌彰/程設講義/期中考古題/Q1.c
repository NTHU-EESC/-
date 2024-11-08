// Q1 u105061230 郭承賢
// The student ID for National Tsing Hua University consists of 9 digits.
// The first three are the admission year. The fourth and fifth digits
// represents the admission college, and for the College of Electrical
// Engineering and Computer Science these two digits must be 06 or 16.
// The 6th digit represents the department. And for EECS college, the following
// department codes are available.
//
// 1: Department of Electrical Engineering
// 2: Department of Computer Science
// 3: Institute of Electronics Engineering
// 4: Institute of Communications Engineering
// 5: Institute of Information Systems and Applications
// 6: Institute of Photonic Technologies
//
// Please write a C program to prompt for a student ID and then print out
// the department of that student. For non-EECS students, it should print
// "Non-EECS student."
//
// Example output of you program:
// $ ./a.out
// Enter student ID: 105061110
// Department of Electrical Engineering
//

#include <stdio.h>	//declare the header

int main(void)		//the start of the function
{
	int a,d,e,f;	//four variables to store number 	
	printf("Enter student ID:");	//print the ID
	scanf("%d",&a);	//store the ID
	d=(a-105000000)/100000;	//store the forth number
	if (d==0) {
		e=(a-105000000)/10000;	//store the fifth number
	} else if (d==1){
		e=(a-105100000)/10000; //store the fifth number
	}
	if (d==0) {
		f=(a-105060000)/1000;	//store the sixth number
	} else if (d==1){
		f=(a-105160000)/1000;
	}
	if ((d==0 || d==1)&& e==6) {	//confirm ID
		switch(f) {	//define the department or institute of the student
			case 1: printf("Department of Electrical Engineering\n");
			break;
			case 2: printf("Department of Computer Science\n");
			break;
			case 3: printf("Institute of Electronics Engineering\n");
			break;
			case 4: printf("Institute of Communications Engineering\n");
			break;
			case 5: printf("Institute of Information Systems and Applications\n");
			break;
			case 6: printf("Institute of Photonic Technologies\n");
			break;	
		}
	}else{	//if the ID is wrong,print this
		printf("\"Non-EECS student.\n\"");
	}
	return 0;	//if the function is correct return value 0
}

