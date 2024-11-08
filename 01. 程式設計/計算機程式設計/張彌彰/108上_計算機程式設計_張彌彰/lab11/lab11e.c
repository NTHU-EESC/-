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

void readData_findMin(void);
void printGrand(void);
void printSubject(double *subject);

int main(void)
{
	readData_findMin();
	puts("Grand Prize:");
	printGrand();
	puts("Math Prize:");
	printSubject(list->math);
	puts("Science Prize:");
	printSubject(list->sci);
	puts("Literature Prize:");
	printSubject(list->lit);

	return 0;
}

void readData_findMin(void)
{
	int i;
	
	scanf("FirstName LastName Math Science Literature/n");

	for (i = 0; i < 100; i++) {
		scanf("%s %s %lf %lf %lf\n", list[i].fName,
									 list[i].lName,
									&list[i].math,
									&list[i].sci,
									&list[i].lit);
		list[i].min = list[i].math;
		if (list[i].min > list[i].sci) {
			list[i].min = list[i].sci;
		}
		if (list[i].min > list[i].lit) {
			list[i].min = list[i].lit;
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
	
	for (i = 0; i < 100; i++) {
		if (80 <= list[i].min) {
			list[i].winTotal = TRUE;
			list[i].total = list[i].math + list[i].sci + list[i].lit;
		} else {
			list[i].winTotal = FALSE;
		}
	}

	do {
		maxScore = 0;
		for (i = 0; i < 100; i++) {
			if (list[i].winTotal &&
				maxScore < list[i].total) {
				maxScore = list[i].total;
				maxIndex = i;
				list[i].winTotal = FALSE;
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

void printSubject(double *subject)
{
	int i;
	double maxScore;
	int maxIndex;
	int serial = 1;

	for (i = 0; i < 100; i++) {
		if (60 <= list[i].min && list[i].min < 80) {
			list[i].winSubj = TRUE;
		} else {
			list[i].winSubj = FALSE;
		}
	}

	do {
		maxScore = 0;
		for (i = 0; i < 100; i++) {
			if (list[i].winSubj &&
				maxScore < subject[i]) {
				maxScore = subject[i];
				maxIndex = i;
				list[i].winSubj = FALSE;
			}
		}
		if (maxScore) {
			printf("  %d: %s %s %.1f\n", serial++,
										 list[maxIndex].fName,
										 list[maxIndex].lName,
										 subject[i]);
		}
	} while (maxScore && serial <= 10);

	return;
}
