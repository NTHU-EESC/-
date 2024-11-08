// EE231002 Lab10. Grade Report
// 110060007, 黃俊穎
// 2022/01/01

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {math, phys, chem} DEPT;    // all departments

typedef struct student {      // structure for each student's data
	int ID;                   // student ID
	char FName[20];           // first name
	char LName[20];           // last name
	DEPT dept;                // department
	double mt1, mt2, final;   // scores for 2 midterms and final
	double total;             // total scores
	int selected;             // extra space for find top scores
} Student;

Student All[100];             // array of students' data

// read students' data
void read(Student All[], int n);
// find selected students' data
void find_stu(Student All[], int n);
// rank 3 highest students' scores and departments
void rank(double rank[], int n, double* f, double* s, double* t);

int main(void)
{
	// store every exam's score and average
	double mt1[100], mt2[100], final[100], avg[100];
	int i;                 // variable for loop
	double f, s, t;        // top 3 students' scores
	// f, s, t represent first, second and third
	double summt1 = 0, summt2 = 0, sumfinal = 0, sumavg = 0;
	                       // sum of 3 exams and average

	read(All, 100);        // read students' data
	// store and sum up every data (mt1, mt2, final, avg)
	for (i = 0; i < 100; i++) {
		mt1[i] = All[i].mt1;
		summt1 += mt1[i];
		mt2[i] = All[i].mt2;
		summt2 += mt2[i];
		final[i] = All[i].final;
		sumfinal += final[i];
		avg[i] = (0.25 * mt1[i] + 0.25 * mt2[i] + 0.5 * final[i]);
		sumavg += avg[i];
	}

	rank(avg, 100, &f, &s, &t); // rank 3 highest students
	printf("Term average: %.2lf\n", sumavg / 100);
	// print out term average score
	printf("  Top students:\n");
	// decide rank of 3 students and printf their data
	for (i = 0; i < 100; i++) {
		if (avg[i] == f) {
			printf("    %.2lf: ", f);
			find_stu(All, i);
		}
	}
	for (i = 0; i < 100; i++) {
		if (avg[i] == s) {
			printf("    %.2lf: ", s);
			find_stu(All, i);
		}
	}
	for (i = 0; i < 100; i++) {
		if (avg[i] == t) {
	        printf("    %.2lf: ", t);
	        find_stu(All, i);
		}
	}
	printf("\n");           // change line
	
	
	rank(mt1, 100, &f, &s, &t); // rank 3 highest students
	printf("Midterm 1 average: %.2lf\n", summt1 / 100);
	// print out Midterm 1 average score
	printf("  Top students:\n");
	// decide rank of 3 students and print out their data
	for (i = 0; i < 100; i++) {
		if (mt1[i] == f) {
		  	printf("    %.1lf: ", f);
		    find_stu(All, i);
	    }
	}
	for (i = 0; i < 100; i++) {
		if (mt1[i] == s) {
			printf("    %.1lf: ", s);
		    find_stu(All, i);
		 }
	}
	for (i = 0; i < 100; i++) {
		if (mt1[i] == t) {
			printf("    %.1lf: ", t);
			find_stu(All, i);
		}
	}
	printf("\n");           // change line

	rank(mt2, 100, &f, &s, &t); // rank 3 highest students
	printf("Midterm 2 average: %.2lf\n", summt2 / 100);
	// print out Midterm 2 average score
	printf("  Top students:\n");
	// decide rank of 3 students and printf their data
	for (i = 0; i < 100; i++) {
		if (mt2[i] == f) {
			printf("    %.1lf: ", f);
	        find_stu(All, i);
        }
	 }
	 for (i = 0; i < 100; i++) {
	    if (mt2[i] == s) {
        	printf("    %.1lf: ", s);
		    find_stu(All, i);
	    }
    }
    for (i = 0; i < 100; i++) {
	    if (mt2[i] == t) {
        	printf("    %.1lf: ", t);
		    find_stu(All, i);
	    }
	}
	printf("\n");

	rank(final, 100, &f, &s, &t); // rank 3 highest students
	printf("Final average: %.2lf\n", sumfinal / 100);
	// print out Final average score
	printf("  Top students:\n");
	for (i = 0; i < 100; i++) {
		if (final[i] == f) {
			printf("    %.1lf: ", f);
		    find_stu(All, i);
		}
	}
	for (i = 0; i < 100; i++) {
		if (final[i] == s) {
			printf("    %.1lf: ", s);
		    find_stu(All, i);
		}
	}
	for (i = 0; i < 100; i++) {
		 if (final[i] == t) {
		 	printf("    %.1lf: ", t);
		    find_stu(All, i);
		 }
	}
	return 0;
}

// find selected students' data
void find_stu(Student All[], int i)
{
	// print out student's ID, first name and last name
	printf("%d %s %s ", All[i].ID, All[i].FName, All[i].LName);
	// print out department
	switch (All[i].dept) {
		case 0: printf("(Math)\n");
				break;
		case 1: printf("(Phys)\n");
				break;
		case 2: printf("(Chem)\n");
				break;
	}
}

// read students' data
void read(Student All[], int n)
{
	int i;               // variables for loop
	char deptstr[5];     // 4 letters for department name and one for NULL

	while (getchar() != '\n'); // if not change line
	// read students' data
	for (i = 0; i < n; i++) {
		scanf("%d", &All[i].ID);
		scanf("%20s", All[i].FName);
		scanf("%20s", All[i].LName);
		scanf("%20s", deptstr);
		// set math is 0, physics 1, chemistry 2 in structure
		if (strcmp(deptstr, "Math") == 0) All[i].dept = 0;
		else if (strcmp(deptstr, "Phys") == 0) All[i].dept = 1;
		else if (strcmp(deptstr, "Chem") == 0) All[i].dept = 2;
		scanf("%lf%lf%lf", &All[i].mt1, &All[i].mt2, &All[i].final);
	}
	return;
}

// rank 3 highest students' scores and departments
void rank(double rank[], int n, double* f, double* s, double* t)
{
	int i;                // variable for loop

	*f = 0;             // initialize 1st value
	// find the highest score
	for (i = 0; i < n; i++) {
		if (*f < rank[i]) {
			*f = rank[i];
		}
	}
	*s = 0;             // initialize 2st value
	// find the second highest score
	for (i = 0; i < n; i++) {
		if (*f > rank[i] && rank[i] > *s) {
			*s = rank[i];
		}
	}
	*t = 0;             // initialize 3st value
	// find the third highest score
	for (i = 0; i < n; i++) {
		if (*f > rank[i] && *s > rank[i] && rank[i] > *t) {
			*t = rank[i];
		}
	}
	return;
}
