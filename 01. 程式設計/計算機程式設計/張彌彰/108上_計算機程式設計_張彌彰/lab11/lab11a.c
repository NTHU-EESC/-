// EE231002 Lab11. Academic Competition
// 108061112, 林靖
// Date: Dec. 7, 2019

#include <stdio.h>

struct STU {						// structure definition for each students
	char fName[15];					// 		first name
	char lName[15];					// 		last name
	double math, sci, lit;			// 		test scores
	double total;					// 		total score
	double min;						// 		minimum subject score
	int winTotal;					// 		for winning Grand Prize
	int winSubj;					// 		for winning a Subject Prize
} ;
struct STU list[100];

void readData(void);

int main(void)
{
	int i;
	
	readData();
	
	
	return 0;
}

void readData(void)
{
	int i;

	scanf("FirstName LastName Math Science Literature/n");
	for (i = 0; i < 100; i++) {
		scanf("%s %s %lf %lf %lf\n",
			  list[i].fName, list[i].lName,
			  &list[i].math, &list[i].sci, &list[i].lit);
// printf("%s %s %f %f %f\n", list[i].fName, list[i].lName, list[i].math, list[i].sci, list[i].lit);
	}
	return;	
}
