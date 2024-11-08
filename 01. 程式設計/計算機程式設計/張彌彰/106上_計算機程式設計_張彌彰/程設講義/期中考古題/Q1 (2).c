// Q1 u105061245 蕭郁澄
// The student ID for National Tsing Hua University consists of 9 digits.
// The first three are the admission year. The fourth and fifth digits
// represents the admission college, and for the College of Engineering
// these two digits must be 03. The 6th digit represents the department.
// And for the College of Engineering, the following department codes are
// available.
//
// 0: Interdisciplinary Program
// 1: Materials Science Engineering
// 2: Chemical Engineering
// 3: Power Mechanical Engineering
// 4: Industrial Engineering and Engineering Management
// 5: Nanoengineering and Microsystems
// 8: Biomedical Engineering 
//
// Please write a C program to prompt for a student ID and then print out
// the department of that student. For non-Engineering students, it should
// print "Non-ENGI student."
//
// Example output of you program:
// $ ./a.out
// Enter student ID: 105031110
// Materials Science Engineering
//

#include <stdio.h>
#define N 9
int main(void)
{
	char ID[N];
	int i;

	printf("Enter student ID:");
	for ( i=0 ; i<N ; i++)
	{
		scanf("%c",&ID[i]);
//		printf("%c\n" , ID[i]) ;
	}
	for ( i=0 ;i<N ;i++)
	{
//		scanf("%c", &ID[i]);
		printf("ID[%d]=%c,%d\n" ,i, ID[i],ID[i] ) ;
	}
	if ( ID[3] != '0' || ID[4] != '3' )
		printf("Non-ENGI student.");
	else if ( ID[5] == '0')
		printf("Interdisciplinary Program.");
	else if ( ID[5] == '1')
		printf("Materials Science Engineering.");
	else if ( ID[5] == '2')
		printf("Chemical Engineering.");
	else if ( ID[5] == 3)
		printf("Power Mechanical Engineering.");
	else if ( ID[5] == 4)
		printf("Industrial Engineering and Engineering Management.");
	else if ( ID[5] == '5')
		printf("Nanoengineering and Microsystems.");
	else if ( ID[5] == '8')
	printf("Biomedical Engineering.");
	return 0;
}

