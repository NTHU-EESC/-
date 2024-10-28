/*******************************************
  EE3980 Algorithms HW09 Comparing Files
  Li-Yu Feng 104061212
  Date:2018/5/11
*******************************************/
#define MAX_LINE 12000		// max number of lines
#define LINE_LENGTH 100		// max char before a '\n' (reading buffer length) 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct result  		//to store editing result
{
	char c;
	int index1, index2;
}Result;

void Trace(int **M, char lines1[MAX_LINE][LINE_LENGTH],
		 char lines2[MAX_LINE][LINE_LENGTH], int len1, int len2);	
												// trace back editing result
void Trace(int **M, char lines1[MAX_LINE][LINE_LENGTH],
		 char lines2[MAX_LINE][LINE_LENGTH], int len1, int len2){
	int i = len1;
	int j = len2; 
	int k= 0 ;
	Result *stack;


	stack = malloc( M[len1][len2] * sizeof(Result) );
	while( i > 0 || j >0){

		if(i > 0 && j > 0 && M[i-1][j-1] <= M[i-1][j] && M[i-1][j-1] <= M[i][j-1] ){
			if( (M[i][j]) == (M[i-1][j-1]) ){	// no edit
				i--; j--;
			}
			else if(M[i][j] == M[i-1][j-1] +1){	//change f1[i] with f2[j]
				stack[k].c = 'C';
				stack[k].index1 = i; stack[k].index2 = j; 
				i--; j--; k++;
			}
		}
		else if(i == 0 || M[i][j-1] <= M[i-1][j] && M[i][j-1] <= M[i-1][j-1]){

			stack[k].c = 'I';			//insert 
			stack[k].index1 = i + 1;
			stack[k].index2 = j;
			j--; k++;
		}
		else {
			stack[k].c = 'D';		//delete
			stack[k].index1 = i;
			i--; k++;
		}
	}

	for(k = M[len1][len2]-1; k >= 0; k--){		// print result backwards
												// (FILO)
		if(stack[k].c == 'C'){

			printf("line %d change \"%s\" to \"%s\"\n",stack[k].index1,
							lines1[stack[k].index1],
							 lines2[stack[k].index2] );
		}
		else if(stack[k].c == 'I'){

			printf("line %d add \"%s\"\n",stack[k].index1,
								lines2[stack[k].index2] );
		}
		else{

			printf("line %d delete \"%s\"\n", stack[k].index1,
			 lines1[stack[k].index1] );
		}
	}

}

int main(int argc, char const *argv[]){
	char c, buff[LINE_LENGTH];
	char lines1[MAX_LINE][LINE_LENGTH], lines2[MAX_LINE][LINE_LENGTH];
												//file1, file2
	int i, j,k;
	FILE *f1,*f2;
	int len1, len2;
	int **M;	// DP matrix;
	bool done;


	f1 = fopen(argv[1], "r");
	f2 = fopen(argv[2], "r");

	//reading file1
	for( done = false, j = 1; done == false; j++ ){
			for ( i = 0; i < LINE_LENGTH; ++i) buff[i] = '\0';	//clear buffer;

			for(c = fgetc(f1), i = 0; c!= '\n' && c != EOF;
				 c = fgetc(f1) )
				buff[i++] = c;

			if(c == EOF){
				done = true;
			}
			if(i==0){
				strcpy(lines1[j],"");	//empty paragraph

			}
			else if (c == '\n'){			// end of paragraph
				strcpy(lines1[j], buff);
			}
	}
	len1 = j-2;
	// reading file2
	for( done = false, j = 1; done == false; j++ ){
			for ( i = 0; i < LINE_LENGTH; ++i) buff[i] = '\0';	//clear buffer;

			for(c = fgetc(f2), i = 0; c!= '\n' && c != EOF;
				 c = fgetc(f2) )
				buff[i++] = c;
 
			if(c == EOF){
				done = true;
			}
			if(i==0){
				strcpy(lines2[j],"");

			}
			else if (c == '\n'){			// end of paragraph
				strcpy(lines2[j], buff);
			}
	}
	len2 = j-2;


	fclose(f1);
	fclose(f2);


	M = malloc( (len1 +1) * sizeof(int *) );		//
	for (i = 0; i <= len1; i++){					//	
		M[i] = malloc( (len2 +1) * sizeof(int) );	//
	}												//
	for (i = 0; i < len1+1 ; i++){					//
		for (j = 0; j < len2 +1; j++)				//
			M[i][j] = 0;							// init M
	}

	//DP
	for (i = 0; i < len1 +1; i++)	M[i][0] = i;	
	for (i = 0; i < len2 +1; i++)	M[0][i] = i;

	for (j = 1; j < len2 +1; j++){
		for( i = 1; i < len1 +1; i++){
			if( strcmp(lines1[i], lines2[j]) == 0 ){
				M[i][j] = M[i-1][j-1];						//identical line
			}
			else{
				if(M[i-1][j-1] <= M[i-1][j] && M[i-1][j-1] <= M[i][j-1]) 
					M[i][j] = M[i-1][j-1] + 1;				// no edit
				else if(M[i][j-1] <= M[i-1][j] && M[i][j-1] <= M[i-1][j-1])
					M[i][j] = M[i][j-1] +1;					//insert
				else //(M[i-1][j] <= M[i][j-1] && M[i-1][j] <= M[i-1][j-1])
					M[i][j] = M[i-1][j] +1;					//delete
			}
		}
	}

	Trace(M, lines1, lines2, len1, len2);

	return 0;
}
