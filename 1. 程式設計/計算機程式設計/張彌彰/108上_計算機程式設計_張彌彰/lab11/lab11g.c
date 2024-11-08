// EE231002 Lab11. Academic Competition
// 108061112, 林靖
// Date: Dec. 7, 2019

#include <stdio.h>

typedef enum {FALSE, TRUE} Bool;

struct STU {						// structure definition for each students
	char fName[15];					// 		first name
	char lName[15];					// 		last name
	double math, sci, lit;			// 		test scores
	double min;						// 		minimum subject score
} ;
struct STU list[100];

Bool Find_Max_and_Print(int rank, double score[100]);

int main(void)
{
	int i;
	int rank;
	double score[100];

	scanf("FirstName LastName Math Science Literature\n");

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

	puts("Grand Prize:");
	for (i = 0; i < 100; i++) {
		if (80 <= list[i].min) {
			score[i] = list[i].math + list[i].sci + list[i].lit;
		} else {
			score[i] = 0;
		}
	}
	for (rank = 1; Find_Max_and_Print(rank, score); rank++);

	puts("Math Prize:");
	for (i = 0; i < 100; i++) {
		if (60 <= list[i].min && list[i].min < 80) {
			score[i] = list[i].math;
		} else {
			score[i] = 0;
		}
	}
	for (rank = 1; rank <= 10 && Find_Max_and_Print(rank, score); rank++);

	puts("Science Prize:");
	for (i = 0; i < 100; i++) {
		if (60 <= list[i].min && list[i].min < 80) {
			score[i] = list[i].sci;
		} else {
			score[i] = 0;
		}
	}
	for (rank = 1; rank <= 10 && Find_Max_and_Print(rank, score); rank++);

	puts("Literature Prize:");
	for (i = 0; i < 100; i++) {
		if (60 <= list[i].min && list[i].min < 80) {
			score[i] = list[i].lit;
		} else {
			score[i] = 0;
		}
	}
	for (rank = 1; rank <= 10 && Find_Max_and_Print(rank, score); rank++);

	return 0;
}

Bool Find_Max_and_Print(int rank, double score[100])
{
	double highest_score = 0;
	int highest_index;
	int i;

	for (i = 0; i < 100; i++) {
		if (highest_score < score[i]) {
			highest_score = score[i];
			highest_index = i;
		}
	}

	if (highest_score != 0) {
		printf("  %d: %s %s %.1f\n", rank,
									 list[highest_index].fName,
									 list[highest_index].lName,
									 highest_score);
		score[highest_index] = 0;
		return TRUE;
	}

	return FALSE;
}
