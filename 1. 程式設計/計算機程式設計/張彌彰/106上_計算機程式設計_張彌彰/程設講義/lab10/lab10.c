/* EE231002 Lab10. College Admission
   106061145, 黃俊瑋
   Date: 2017/12/8
*/

#include <stdio.h>

#define MAXSCORE 300	// the best score one can get
#define MAXACCEPT 80  	// the most students who can get accepted

typedef enum sDEPT{		// define 4 departments
	mathD, physD, chemD, geosD, none,
} DEPT;

typedef struct sStu {
	int appNum;				// application number
	char fName[20];			// first name
	char lName[20];			// last name
	int math, phys, chem;	// test scores
	int total;				// total score
	DEPT pris[4];			// student's priority
	DEPT dept;				// admitted dept
} Stu;

void readStu(Stu data[100]);			// read student function
int findBest(Stu data[100]);			// find the best student function
void chooseDept(int a, Stu data[100]);	// a = student num
void printResult(int k, Stu data[100]); // k = department num
int findMinScore(int k, Stu data[100]);	// k = department num

int mathP = 0, physP = 0, chemP = 0, geosP = 0;
// number of students accepted in each department
int main(void) 
{
	int i;			// for loop
	Stu data[100];	// make an array of structures
	readStu(data);	// read student data
	for (i = 0; i < MAXACCEPT; i++) {		// choose departments
		chooseDept(findBest(data), data);	
		// first find the best student, then chose dept for him or her
	}
		
	printf("\nMath Department: Minumum score %d\n", findMinScore(mathD, data));
	// print first line with minimum score information
	printResult(mathD, data); // print selected students
	printf("\nPhys Department: Minumum score %d\n", findMinScore(physD, data));
	printResult(physD, data);
	printf("\nChem Department: Minumum score %d\n", findMinScore(chemD, data));
	printResult(chemD, data);
	printf("\nGeos Department: Minumum score %d\n", findMinScore(geosD, data));
	printResult(geosD, data);
	printf("\n");
	return 0;
}

void readStu(Stu data[100])
{
	int i, j;  		// for loops
	char dep[5];	// save desired departments

	for (i = 0; i < 100; i++) {	// repeat 100 times
		
		while (getchar() != '\n');	// omit first line
		
		scanf("%d %s %s", &data[i].appNum, data[i].fName, data[i].lName);
		scanf("%d %d %d", &data[i].math, &data[i].phys, &data[i].chem);
		data[i].total = data[i].math + data[i].phys + data[i].chem;
		// input information

		for (j = 0; j < 4; j++) { // input desired 4 dept
			
			scanf("%s", dep); // scan one dept
			
			switch (dep[0]) { // check first letter
				case 'M': data[i].pris[j] = mathD; break;
				case 'P': data[i].pris[j] = physD; break;
				case 'C': data[i].pris[j] = chemD; break;
				case 'G': data[i].pris[j] = geosD; break;
				default: data[i].pris[j] = none;
			} 
		}	
		data[i].dept = (-1); // set selected dept to -1
	}
}

int findBest(Stu data[100])
{
	int i, maxnum = 0, maxapp = -1;
	// i = loop, maxnum = best score, maxapp = the appNum with best score

	for (i = 0; i < 100 ; i++) { // check all 100 students
		if (data[i].total > maxnum && data[i].dept == (-1)) {
		// if the score is bigger than current best score and hasn't 
		// been assigned a dept
			maxapp = i; // save appNum
			maxnum = data[i].total; // save best score
		}
	}
	return maxapp; // return best appNum
}

void chooseDept(int a, Stu data[100])
{
	int j, found = 0; // j = loop, found = boolean of whether been assigned
	for (j = 0; j < 4 && found != 1; j++) { // check four desired depts

		switch (data[a].pris[j]) {
		// check one desired dept	
			case mathD: // case math
				if (mathP < 20) { 
					data[a].dept = mathD; // person accepted in math
					found = 1; // set found to 1
					mathP++; // one more person accepted in math
				}
				break;
				
			case physD:
				if (physP < 20) {
					data[a].dept = physD;
					found = 1;
					physP++;
				}
				break;
				
			case chemD:
				if (chemP < 20) {
					data[a].dept = chemD;
					found = 1;
					chemP++;
				}
				break;
				
			case geosD:
				if (geosP < 20) {
					data[a].dept = geosD;
					found = 1;
					geosP++;
				}
				break;

			default: data[a].dept = none; 
		} 
	} 
	if (found == 0) data[a].dept = none; 
	// if can't accepted to any dept, set to none accepted
}

int findMinScore(int k, Stu data[100])
{
	int i, minScore = MAXSCORE; 
	// i = for loop, minscore = current smallest score
	for (i = 0; i < 100; i++) { // repeat 100 times 
		if (data[i].dept == k && data[i].total < minScore) {
		// if selected dept is the same one and 
		// the score is smaller than minscore
			minScore = data[i].total; // set minscore to current score
		}
	}
	return minScore; // return smallest score
}

void printResult(int k, Stu data[100])
{
	int i, counter = 1; 			// i = for loop, counter = # of student
	for (i = 0; i < 100; i++) {		// repeat 100 times 
		if (data[i].dept == k) {	// if is the same dept
			printf("%3d %d ", counter, data[i].appNum); 			
			printf("%s %s\n", data[i].fName, data[i].lName);
			// print result
			counter++; // add one to counter
		}
	}
}
