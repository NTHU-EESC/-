// EE231002 Lab09. Word Processing
// 110061205, 吳竑逸
// Dec. 11, 2021

#include <stdio.h>
#include <stdlib.h>

char PARA[1500];	// an input paragraph
int LN = 0; 		// line number of printed text
int LW; 			// line width of output lines

void line(void);				// to print out line number
int line_width(int lp, int pp);	// to calculate line width


int main(int argc, char *argv[])
{
	int i, j;		// i, j are used by loop
	int count;		// the words in the first six lines
	int lp = 0;		// line position
	int pp = 0;		// paragraph position

	LW = atoi(argv[1]) - 4;		// line width except for line spaces
	for (i = 0; i < 6; i++) {	// run the title's loop
		line();		// print out line number
		count = 0;	// count is 0
		for (j = 0; (PARA[j] = getchar()) != '\n'; j++, count++);
			// store each line's word, and calculate the words
		PARA[j] = '\0';	// let change line become '\0'
		// set the words to center
		for (j = 0; j < (LW - count) / 2; j++) {
			printf(" ");		// print out space before the words
		}
		printf("%s\n", PARA);	// print out the title
	}
	
	while ((PARA[0] = getchar()) != EOF) {	// if article doesn't end
		line();					// print out line number
		if (PARA[0] == '\n') {	// if paragraph is change line
			printf("\n");		// change line
		} else {
			lp = 0;				// line position is 0
			pp = 0;				// paragraph is 0
			for (j = 1; (PARA[j] = getchar()) != '\n'; j++);
				// store each line's word 
			// run the loop from 0 to change line
			for (i = 0; PARA[i] != '\n'; i++) {
				printf("%c", PARA[i]);	// print out paragraoh
				lp++;	// calculate line position
				pp++;	// calculate paragraph position
				// if paragraph is space, judge line width 
				if (PARA[i] == ' ') {	
					lp = line_width(lp, pp);	
						// execute the line width's function 
				}	
			}
			printf("\n");	// the end of paragraph should change line
		}	
	}	
	return 0;	// function ends
}

// calculate line numbers and print out
void line(void)
{
	LN++;	// calculate line numbers
	if (LN % 5 == 0) 		// if line number is the multiple of five
		printf("%3d ", LN);	// print out the line numbers
	else 
		printf("    ");		// four spaces
}

// to judge the line width whether exceeds the regulation
int line_width(int lp, int pp)
{
	int i, j = lp;	// i is for loop, j is to judge if it exceeds
	
	// run the loop to space or change lines
	for (i = pp + 1 ; PARA[i] != ' ' && PARA[i] != '\n'; i++) {
		j++;	// calculate j
	}
	if (j < LW) 	// if j < line width, we can continue in the same line
		return lp;	// return the line position
	else 			// if j exceeds the regulation 
		printf("\n");	// let the words change line
		line();		// print out line numbers
		return 0;	// let line position to 0
}
