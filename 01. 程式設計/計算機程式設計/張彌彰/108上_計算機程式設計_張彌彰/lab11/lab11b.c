// EE231002 Lab11. Academic Competition
// 108061112, 林靖
// Date: Dec. 7, 2019

#include <stdio.h>

typedef enum {FALSE, TRUE} Bool;

struct STU {						// structure definition for each students
	char fName[15];					// 		first name
	char lName[15];					// 		last name
	double math, sci, lit;			// 		test scores
	double total;					// 		total score
	double min;						// 		minimum subject score
	Bool winTotal;					// 		for winning Grand Prize
	Bool winSubj;					// 		for winning a Subject Prize
} ;
struct STU list[100];

void readData(void)
{
	int i;
	
	scanf("FirstName LastName Math Science Literature/n");
	for (i = 0; i < 100; i++) {
		scanf("%s %s %lf %lf %lf\n", list[i].fName,
									 list[i].lName,
									&list[i].math,
									&list[i].sci,
									&list[i].lit);
// printf("%s %s %f %f %f\n", list[i].fName, list[i].lName, list[i].math, list[i].sci, list[i].lit);	
		if (list[i].math >= 80 &&
			list[i].sci >= 80 &&
			list[i].lit >= 80) {
			list[i].winTotal = TRUE;
			list[i].winSubj = FALSE;
			list[i].total = list[i].math + list[i].sci + list[i].lit;
		} else if (list[i].math >= 60 &&
				   list[i].sci >= 60 &&
				   list[i].lit >= 60) {
			list[i].winTotal = FALSE;
			list[i].winSubj = TRUE;
		} else {
			list[i].winTotal = FALSE;
			list[i].winSubj = FALSE;
		}
	}

	return;
}

void printGrand(void)
{
	int i;
	double maxScore;
	int maxIndex;
	int serial = 1;

	puts("Grand Prize:");

	do {
		maxScore = 0;
		for (i = 0; i < 100; i++) {
			if (list[i].winTotal &&
				maxScore < list[i].total) {
				list[i].winTotal = False;
				maxScore = list[i].total;
				maxIndex = i;
			}
		}
		if (maxScore) {
			printf("  %d: %s %s %.1f\n", serial++,
										 list[maxIndex].fName,
										 list[maxIndex].lName,
										 list[maxIndex].total);
		}
	} while (maxScore);

	return;
}

void printMath(void)
{
	int i;
	double maxScore;
	int maxIndex;
	int serial = 1;

	puts("Grand Prize:");

	do {
		maxScore = 0;
		for (i = 0; i < 100; i++) {
			if (list[i].winSubj &&
				maxScore < list[i].total) {
				list[i].winSubj = FALSE;
				maxScore = list[i].total;
				maxIndex = i;
			}
		}
		if (maxScore) {
			printf("  %d: %s %s %.1f\n", serial++,
										 list[maxIndex].fName,
										 list[maxIndex].lName,
										 list[maxIndex].total);
		}
	} while (maxScore);

	return;
}
