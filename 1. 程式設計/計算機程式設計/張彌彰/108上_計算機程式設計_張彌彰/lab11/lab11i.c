// EE231002 Lab11. Academic Competition
// 108061112, 林靖
// Date: Dec. 7, 2019

#include <stdio.h>					// Standard input and output library

typedef enum {FALSE, TRUE} Bool;	// Boolean type

struct STU {						// structure definition for each students
	char fName[15];					// 		first name
	char lName[15];					// 		last name
	double math, sci, lit;			// 		test scores
	double min;						// 		minimum subject score
	int winTotal_winSubj;			//		for winning Grand Prize
} ;
struct STU list[100];				// Subjects were tested among 100 students

Bool Find_Max_and_Print(int rank, double score[100]);
									// Find and print out the award winner with
									// highest score. Return FALSE if have
									// printed out all the winners.
int main(void)
{									// Called at program startup
	int i;							// Index for looping
	double score[100];				// Scores of candidate winners
	int rank;						// Ranking of the winner

	scanf("FirstName LastName Math Science Literature\n");
									// To skip the first line of the data file

	for (i = 0; i < 100; i++) {		// For each student
		scanf("%s %s %lf %lf %lf\n", list[i].fName,		// Read data in
									 list[i].lName,
									&list[i].math,
									&list[i].sci,
									&list[i].lit);
		list[i].min = list[i].math;						// 
		if (list[i].min > list[i].sci) {
			list[i].min = list[i].sci;
		}
		if (list[i].min > list[i].lit) {
			list[i].min = list[i].lit;
		}
	}

	for (i = 0; i < 100; i++) {
		list[i].winTotal_winSubj = TRUE;
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

	for (i = 0; i < 100; i++) {
		list[i].winTotal_winSubj = TRUE;
	}

	puts("Math Prize:");
	for (i = 0; i < 100; i++) {
		if (60 <= list[i].min && list[i].min < 80) {
			score[i] = list[i].math;
		} else {
			score[i] = 0;
		}
	}
	for (rank = 1; rank <= 10 && Find_Max_and_Print(rank, score); rank++);
	
	for (i = 0; i < 100; i++) {
		list[i].winTotal_winSubj = TRUE;
	}

	puts("Science Prize:");
	for (rank = 1; rank <= 10 && Find_Max_and_Print(rank, score); rank++);

	for (i = 0; i < 100; i++) {
		list[i].winTotal_winSubj = TRUE;
	}

	puts("Literature Prize:");
	for (rank = 1; rank <= 10 && Find_Max_and_Print(rank, score); rank++);

	return 0;
}

Bool Find_Max_and_Print(int rank, double score[100])
{
	int i;
	double highest_score = 0;
	int highest_index;

	for (i = 0; i < 100; i++) {
		if (highest_score < score[i] && list[i].winTotal_winSubj) {
			highest_score = score[i];
			highest_index = i;
		}
	}

	if (highest_score == 0) {
		return FALSE;
	}

	printf("  %d: %s %s %.1f\n", rank,
								 list[highest_index].fName,
								 list[highest_index].lName,
								 highest_score);
	list[highest_index].winTotal_winSubj = FALSE;

	return TRUE;
}
