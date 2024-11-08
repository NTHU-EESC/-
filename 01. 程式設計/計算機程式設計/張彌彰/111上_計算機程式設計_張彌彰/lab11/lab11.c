// EE231002 Lab11. Academic Competition
// 111060023, Berlin
// Date: 2022/12/5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct STU {
	char fName[15];			// structure definition
	char lName[15];			// last name
	double math, sci, lit;	// test scores
	double min;				// minimum subject score
};
struct STU list[100];		// student list

void GrandPrize(struct STU list[100]);				// print grand prize winner
void printScore(double score[100], int subPrize);	// print score by case

int main(void)
{
	int i, j;										// loop control
	double score[100];								// array to store score
	
	scanf("FirstName LastName Math Science Literature\n");	// read in title
	for (i = 0; i < 100; i++) {								// read 100 student
		scanf("%s %s %lf %lf %lf\n",
			list[i].fName, list[i].lName, 					// students' names
			&list[i].math, &list[i].sci, &list[i].lit);		// students' scores
		list[i].min = list[i].math;					// assume math is the min
		if (list[i].min > list[i].sci) {			// if sci. is lower
			list[i].min = list[i].sci;				// update the min
		}
		if (list[i].min > list[i].lit) {			// if lit. is lower
			list[i].min = list[i].lit;				// update the min
		}
	}
	GrandPrize(list);									// get grand prize
	// get math prize
	for (j = 0; j < 100; j++) {							// get math score
		if (list[j].min < 80 && list[j].min >= 60) {
			score[j] = list[j].math;
		}
		else score[i] = 0;
	}
	printf("Math Prize:\n");							// print title
	printScore(score, 1);								// print math score
	// get science prize
	for (j = 0; j < 100; j++) {							// get sci. score
		if (list[j].min < 80 && list[j].min >= 60) {
			score[j] = list[j].sci;
		}
		else score[i] = 0;
	}
	printf("Science Prize:\n");							// print title
	printScore(score, 1);								// print sci score
	// get literature prize
	for (j = 0; j < 100; j++) {							// get lit. score
		if (list[j].min < 80 && list[j].min >= 60) {
			score[j] = list[j].lit;
		}
		else score[i] = 0;
	}
	printf("Literature Prize:\n");						// print title
	printScore(score, 1);								// print lit. score
}

// to print the grand prize winner
// input: struct STU list, a list of students
// return: no return
// output: print the grand prize winner
void GrandPrize(struct STU list[100])
{
	int i;											// loop control
	double score[100];								// array to store score
	
	// get score as the sum of three subjects
	for (i = 0; i < 100; i++) {
		if (list[i].min >= 80) {
			score[i] = list[i].math + list[i].sci + list[i].lit;
		}
		else score[i] = 0;
	}
	printf("Grand Prize:\n");						// print title
	printScore(score, 0);							// print grand prize 
}

// to print the winners of each prize and their score
// input: double score, a array of score
//        int subPrize, whether it's printing a subPrize
// return: no return
// output: print all score if it's not printing subject prize (subPrize == 0)
// 		   print top ten if it's printing subject prize (subPrize == 1)
void printScore(double score[100], int subPrize)
{
	int i;					// loop control
	int count = 1;			// to count how many winner
	int i_max;				// store index of maximum score
	double score_max;		// store the maximum score

	do {
		score_max = 0;						// initialize the maximum score
		for (i = 0; i < 100; i++) {
			if (score_max < score[i]) {		// if current score > maximum score
				score_max = score[i];		// update maximum score
				i_max = i;					// store the index of maximum score
			}	
		}
		if (score_max > 0) {							// if maximum score > 0
			printf("%3d: %s %s %lg\n", 					// print the winner's
				count, 									// sequence
				list[i_max].fName,list[i_max].lName,	// name
				score[i_max]);							// score
			score[i_max] = 0;							// this winner if found
			count++;									// find next winner
		}
	} while (score_max != 0 && !(subPrize && count > 10));
		// keep searching until all score if found
		// if printing the subject prize (subPrize == 1), print at most ten
}
