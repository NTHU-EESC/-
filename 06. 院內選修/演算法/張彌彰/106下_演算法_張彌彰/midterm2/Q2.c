// Q2 104061212 馮立俞
// The line length with fewest padded spaces.
/*******************************************
  EE3980 Algorithms HW08 Printing Paragraphs
  Li-Yu Feng 104061212
  Date:2018/5/5
*******************************************/
int N = 50;

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int greedy(char **words, int Nwords);			//greedy method
void DP(char ** paragraph, int Nwords);			//call dynamic programming
int InitDP(char **words, int Nwords, int w1, int *SpaceMat, int *SolMat);
												// fill SpaceMat and SolMat
void PrintDP( char **words, int Nwords,  int *SolMat, int *SpaceMat);
												//print DP result

int greedy(char **words, int Nwords){
	int i,j,k,m,len,space,line_space; 

	if(Nwords == 0){
		printf("\n"); return 0;
	}

	for(i = 0, space = 0; i < Nwords ;i = j){
		len = strlen(words[i]);
		for (j = i+1; len + strlen(words[j])+1 <= N && j < Nwords ; j++ )
			len += strlen(words[j]) + 1 ;	//stuff as many words as we could 
		line_space = j <Nwords ? N-len : 0;

		space += line_space;		//count total spaces in paragraph
		for (k = i; k < j ; k++ )
		//	if(k!= j-1) printf("%s ",words[k] );
		//	else 		printf("%s",words[k] );
		for (m = 0; m < line_space; m++) putchar(' ');
		//printf("|%d\n", line_space);
	}

	printf("----Space in this paragraph: %d\n",space );

	return space;
}


int main(){
	char c, buff[10000], *paragraph[1000];
	bool done = false;
	int i, j,k;
	int min = 1000;
	int minN,temp;


	
	for(k =0; ;k++){
		
		for ( i = 0; i < 1000; i++) paragraph[i] = " "; //clear paragraph

		for( done = false, j = 0 ; done == false; j++){
			for ( i = 0; i < 40; ++i) buff[i] = '\0';	//clear buffer;

			for(c = getchar(), i = 0; c != ' ' && c!= '\n' && c != EOF;
				 c = getchar() )
				buff[i++] = c;

			if(c == EOF){
				return 0;
			}
			else if (c == '\n'){			// end of paragraph
				done = true;
				if(j==0) j--;
			}
		
			paragraph[j] = malloc( strlen(buff) +1 );	//load word from buffer
			strncpy( paragraph[j], buff, strlen(buff) );//
			paragraph[j][strlen(buff)] = '\0';			//
			


		}
		for (N = 40; N <=70; N++){
				temp = greedy(paragraph,j);
				if (temp < min) { min = temp; minN = N;}
			}
			printf("min: %d N:%d\n", min, minN);
			return 0;
	}
	return 0;
}
