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
void printMath(void);
void printSci(void);
void printLit(void);

int main(void)
{
	readData_findMin();
	printGrand();
	printMath();
	printSci();
	printLit();

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

	puts("Grand Prize:");
	
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
			}
		}
		if (maxScore) {
			printf("  %d: %s %s %.1f\n", serial++,
										 list[maxIndex].fName,
										 list[maxIndex].lName,
										 list[maxIndex].total);
			list[maxIndex].winTotal = FALSE;
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

	puts("Math Prize:");
	
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
				maxScore < list[i].math) {
				maxScore = list[i].math;
				maxIndex = i;
			}
		}
		if (maxScore) {
			printf("  %d: %s %s %.1f\n", serial++,
										 list[maxIndex].fName,
										 list[maxIndex].lName,
										 list[maxIndex].math);
			list[maxIndex].winSubj = FALSE;
		}
	} while (maxScore && serial <= 10);

	return;
}

void printSci(void)
{
	int i;
	double maxScore;
	int maxIndex;
	int serial = 1;

	puts("Science Prize:");
	
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
				maxScore < list[i].sci) {
				maxScore = list[i].sci;
				maxIndex = i;
			}
		}
		if (maxScore) {
			printf("  %d: %s %s %.1f\n", serial++,
										 list[maxIndex].fName,
										 list[maxIndex].lName,
										 list[maxIndex].sci);
			list[maxIndex].winSubj = FALSE;
		}
	} while (maxScore && serial <= 10);

	return;
}

void printLit(void)
{
	int i;
	double maxScore;
	int maxIndex;
	int serial = 1;

	puts("Literature Prize:");
	
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
				maxScore < list[i].lit) {
				maxScore = list[i].lit;
				maxIndex = i;
			}
		}
		if (maxScore) {
			printf("  %d: %s %s %.1f\n", serial++,
										 list[maxIndex].fName,
										 list[maxIndex].lName,
										 list[maxIndex].lit);
			list[maxIndex].winSubj = FALSE;
		}
	} while (maxScore && serial <= 10);

	return;
}

