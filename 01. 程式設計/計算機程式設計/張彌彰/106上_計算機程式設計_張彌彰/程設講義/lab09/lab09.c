/* EE231002 Lab09. Word Processing
   106061145, ¶À«TÞ³
   Date: 12/2/2017 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LSTR 5000 // maximum number of character per paragraph

int N; // maximum number of char per line
int readLine(char para[LSTR]);	// readline
void leftAlign(char *para); 	// leftAlign
void center(char *para);		// center
void bothAlign(char *para);		// bothAlign

int main(int argc, char *argv[]) 
{
	char para[LSTR];	// paragraph array
	char mode;			// save mode

	if (argc < 3) {		// if too few argument
		printf("Too few arguments!\n");
		exit(1); 
	}

	N = atoi(argv[1]);	// convert argument 1 to integer
	mode = argv[2][0];	// check argument 2 mode
	while (readLine(para) == 0) {	// repeat if not the end of story
		switch(mode) {	// check mode type
			case 'l': leftAlign(para); 	printf("%s\n", para); break;
			case 'c': center(para); break;
			case 'b': bothAlign(para); break;
			default: printf("Wrong mode input!!\n"); exit(1);
		}
	}
	return 0;
}

int readLine(char para[LSTR])
{
	int ch, i; 	// ch = read char, i = loops
	for (i = 0; i < LSTR; i++)  // 
		para[i] = '\0';
	
	i = 0;

	while ((ch = getchar()) != '\n') 	// read paragraph until newline
		if (i < LSTR) para[i++] = ch; 	// save char to array
	para[i++] = '\0';		// add null to the end of array
	
	if (strcmp(para, "EOF") == 0) return 1; // the end of story return 1
	else return 0; 
}

void leftAlign(char *para) 
{
	while (*(para + N) != '\0') {
	
		para += N;
		while (*para != ' ') para--;
		*para = '\n';
		para++;
	
	} 

} 

void center(char *para)
{
	char line[N+1];
	int counter, i, lastline = 0;
	if (strcmp(para, "\0") == 0) printf("\n");
		
	while (*para != '\0') { // form new lines until end of paragraph
		
		counter = 0;
		
		for (i = 0; i <= N; i++) 	
			line[i] = '\0'; // clear line array
			
		// check if it's last line
		if (*(para + N) == '\0') lastline = 1; 
		
		// save a new line
		for (i = 0; i < N; i++) 
			line[i] = *para++; // save para's char to line
		
		// process the line 
		if (lastline) {
			while (line[--i] == '\0') counter++; 
		} // count how many space there are before reaching a char
		else if (*para == ' ') {
			line [i] = '\0'; // save the last (i = N) element to endline
			para++;
		}
		
		else { // para is now pointing to a char
			   // which means it is in the midst of a word
			while (*para != ' ') { // keep doing until para is pointing at ' '
			
				para--; // move para back one space
				i--; // move i back one space
				line[i] = '\0'; // change the char in line[i] to \0
				counter++; // keep track of spaces
			}
			para++; // move para ahead to the space with character
		}
	 	
 	
	 	for (i = 1; i <= counter/2; i++) 
	 		printf(" ");	// print front space
				
		printf("%s", line); // print line
		
		for (i = 1; i <= (counter+1)/2; i++) 
			printf(" "); // print back space
			
		printf("\n");
		
	}
} 

void bothAlign(char *para)
{
	char line[N+1];
	char line1[N+1];
	int counter, i, lastline = 0, word, k, j, remain;
	if (strcmp(para, "\0") == 0) printf("\n");
		
	while (*para != '\0') { // form new lines until end of paragraph
		
		counter = 0;
		word = 0;
		
		for (i = 0; i <= N; i++) {

			line[i] = '\0'; // clear line array
			line1[i] = '\0'; // clear line1 array
		}
			
		// check if it's last line
		if (*(para + N) == '\0') lastline = 1; 
		
		// save a new line
		for (i = 0; i < N; i++) 		
			line[i] = *para++; // save para's char to line

		// process the line 
		if (lastline) {
			while (line[--i] == '\0') counter++; 
		} // count how many space there are before reaching a char
		else if (*para == ' ') {
			line [i] = '\0'; // save the last (i = N) element to endline
			para++;
		}
		
		else { // para is now pointing to a char
			   // which means it is in the midst of a word
			while (*para != ' ') { // keep doing until para is pointing at ' '
			
				para--; // move para back one space
				i--; // move i back one space
				line[i] = '\0'; // change the char in line[i] to \0
				counter++; // keep track of spaces
			}
			para++; // move para ahead to the space with character
		}
		
		if (lastline) printf("%s\n", line);
	 	else {
			// count how many words there are in the line
			i = 0;
			while (line[i] != '\0') {
				if (line[i] == ' ') word++;
				i++;
			}
		
			//printf("%d", counter);	

			remain = counter % word; // calculate the spaces which we can't add evenly 
			counter /= word; // calculate how many space we can put between words
	 	
		 	// insert spaces between words
		 	i = 0; 
		 	j = 0;
		 	k = 0;
	 			
	 		while (i < N) { // read until the end of the line
	 		
	 			if (line[i] == ' ') { // if come across a space where we need to add spaces
	 			
	 				line1[j++] = ' ';
	 				while (k < counter) {
	 					line1[j++] = ' ';
	 					k++;
					} // add spaces to line1 
					k = 0;
				
					if (remain-- > 0) line1[j++] = ' '; // add uneven space
				} 
				else {
					line1[j] = line[i];
					j++; // add line char to line1
				}
				i++;
			}
			line1[i] = '\0';
	 	
	 	
			printf("%s", line1); // print line
		
		
			printf("\n");
		
		}
	
	} 
}

