#include <stdio.h>

typedef struct STU {
	char fName[15];
	char lName[15];
	double math, sci, lit;
	double total;
	double min;
	int winTotal;
	int winSubj;
} student;
student list[100];

void printGrand(void);
void printMath(void);

int main(void) {
	int i;

	scanf("FirstName LastName Math Science Literature");
	for (i = 0; i < 100; i++) {
		scanf("%s %s %lf %lf %lf", list[i].fName, list[i].lName,
			&list[i].math, &list[i].sci, &list[i].lit);
	}
	for (i = 0; i < 100; i++) {
		if (list[i].math >= 80 && list[i].sci >= 80 && list[i].lit >= 80) {
			list[i].winTotal = 1;
			list[i].winSubj = 0;
			list[i].total = list[i].math + list[i].sci + list[i].lit;
		} 
		else if (list[i].math >= 60 && list[i].sci >= 60 && list[i].lit >= 60) {
			list[i].winTotal = 0;
			list[i].winSubj = 1;
		}
		else {
			list[i].winTotal = 0;
			list[i].winSubj = 0;
		}
	}
	printGrand();
	printf("\n");
	printMath();

	return 0;
}

void printGrand(void) {
	int i;
	int count = 0;
	double max = 0;
	int inmax;
	
/*	for(i = 0; i  < 100; i++) {
		if (list[i].winTotal) {
		printf("  %d: %s %s %lg\n", count, list[i].fName, 
									   list[i].lName,
									   list[i].total);
		}
	}*/
	do {
		max = 0;
		for (i = 0; i < 100; i++) {
			if (list[i].winTotal && list[i].total > max) {
				max = list[i].total;
				inmax = i;
			}
		}
		if (max) {
			printf("  %d: %s %s %lg\n", ++count, list[inmax].fName, 
									   list[inmax].lName,
									   list[inmax].total);
			list[inmax].winTotal = 0; 
		}
	} while (max);
}

void printMath(void) {
	int i;
	int count = 0;
	double max = 0;
	int inmax;

	while (count < 10) {
		max = 0;
		for (i = 0; i < 100; i++) {
			if (list[i].winSubj && list[i].math > max) {
				max = list[i].math;
				inmax = i;
			}
		}
		count++;
		printf("  %d: %s %s %lg\n", count, list[inmax].fName, 
									   list[inmax].lName,
									   list[inmax].math);
		list[inmax].winSubj = 0;
	}
}
