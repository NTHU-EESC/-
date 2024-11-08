// After a academic competition, the test results of 100 students are given
// in the file Q3.dat, where the first line summarized the following lines'
// contents and then followed by 100 lines of test results.
// Please write a program to generate a summary report, that is, 
// compare each student's subject score to the average of the subject and
// then print out 'above' if the score is greater than or equal to the
// subject average, otherwise print out 'below'.
//
// Program execution example:
// $ ./a.out < Q3.dat
// FirstName LastName Math Science Literature
// Isabella SMITH below below below
// Emma JOHNSON above above below
// Olivia WILLIAMS below above above
// ...
// ...
//

#include <stdio.h>
#include <stdlib.h>

struct STU {                // structure definition for each students
    char fName[15];         // first name
    char lName[15];         // last name
    double math, sci, lit;  // test scores 
};

struct STU list[100];       // all students' results as an array of struct

int main(void)
{
	char ch; // ch: store a character
	int i;   // i: counter for loops
	double avg_math = 0, avg_sci = 0, avg_lit = 0;
			 // first store the sum of each subject score
			 // then calculate the average of each subject

	while ((ch = getchar()) != '\n'); // skip the first line
	for (i = 0; i < 100; i++) {       // get all students' information 
		scanf("%s %s %lf %lf %lf", list[i].fName, list[i].lName,
			&list[i].math, &list[i].sci, &list[i].lit);
		avg_math += list[i].math;     // sum up math score
		avg_sci += list[i].sci;       // sum up sci score
		avg_lit += list[i].lit;       // sum up lit score
	}
	avg_math /= 100;                  // calculate average of math
	avg_sci /= 100;                   // calculate average of sci
	avg_lit /= 100;                   // calculate average of lit
	printf("FirstName LastName Math Science Literature\n"); // print title
	for (i = 0; i < 100; i++) { 						// check every student
		printf("%s %s", list[i].fName, list[i].lName);  // print name
		if (list[i].math >= avg_math) printf(" above"); // check math score
		else printf(" below");
		if (list[i].sci >= avg_sci) printf(" above");   // check sci score
		else printf(" below");
		if (list[i].lit >= avg_lit) printf(" above\n"); // check lit score
		else printf(" below\n");
	}



}
