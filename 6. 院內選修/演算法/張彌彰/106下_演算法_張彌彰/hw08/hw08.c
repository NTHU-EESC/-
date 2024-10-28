/*******************************************
  EE3980 Algorithms HW08 Printing Paragraphs
  Li-Yu Feng 104061212
  Date:2018/5/5
*******************************************/
const int N = 50;

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
			if(k!= j-1) printf("%s ",words[k] );
			else 		printf("%s",words[k] );
		for (m = 0; m < line_space; m++) putchar(' ');
		printf("|%d\n", line_space);
	}

	printf("----Space in this paragraph: %d\n",space );

	return space;
}

void DP(char ** paragraph, int Nwords){
	int sum;
	int *SolMat, *SpaceMat;		//Solution Matrix, Spaces required for the sol.
	int m,i;

	if(Nwords==0)	printf("\n");
		else{
			SpaceMat = malloc( Nwords * sizeof(int) );
			for (i = 0; i < Nwords; i++)	SpaceMat[i] = 1000;
			SolMat = malloc( Nwords * sizeof(int) );
			for (i = 0; i < Nwords; i++)	SolMat[i] = 0;		//init SpaceMat 
																//& Solmat

			for(sum = N+1, i = Nwords-1; i >= 0 && sum >= 0; i-- )
				sum -= strlen(paragraph[i]) + 1;
			if (i ==-1 ) i = 0;
			else i = i + 2;			

			for (m = i ; m < Nwords; m++){
				SolMat[m] = Nwords - 1;
				SpaceMat[m] = 0;
			}								// last line in paragraph handling
			
			InitDP(paragraph, Nwords, 0, SpaceMat, SolMat);
			PrintDP(paragraph, Nwords, SolMat, SpaceMat);
		}
}

int InitDP(char **words, int Nwords, int w1, int *SpaceMat, int *SolMat){
	int i;
	int space;
	int temp;


	if(SpaceMat[w1] != 1000) return SpaceMat[w1];

	for (i = w1 , space = N+1; space > 0 && i < Nwords; i++ ){
												// recursion in DP
		if( space  > strlen(words[i]) ){ 		// find minimum
			space -= strlen(words[i]) + 1;
			temp = space + InitDP(words, Nwords, i+1,SpaceMat,SolMat);
			if( temp <= SpaceMat[w1] )	{ SolMat[w1] = i; SpaceMat[w1] = temp;}
		}
		else space = -100;
	}
	return SpaceMat[w1];
}

void PrintDP( char **words, int Nwords,  int *SolMat, int *SpaceMat){
	int i,j,k,count;

	
	for (i = 0, j = SolMat[0]; i < Nwords; ){
		for (count = 0,k = i; k <= j; k++){
			count += strlen(words[k]) + 1;
			if (k != j) printf("%s ",words[k] );
			else printf("%s",words[k] );
		}
		count--;
		k = N-count;
		for ( ; k > 0; k--) putchar(' ');
		printf("|%d\n", j+1 != Nwords ?
			 SpaceMat[i] - SpaceMat[j+1] : SpaceMat[i] - SpaceMat[j] );
		i = j+1; j = SolMat[i];
	}
	printf("----Total spaces in this paragraph is %d\n",SpaceMat[0] );
}

int main(){
	char c, buff[10000], *paragraph[1000];
	bool done = false;
	int i, j,k;


	
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
		//////////////////GREEDY METHOD/////////////////////
		//greedy(paragraph,j);
		////////////////////////////////////////////////////

		//////////////DYNAMIC PROGRAMMING METHOD////////////
		DP(paragraph,j);
		////////////////////////////////////////////////////
	}


	return 0;
}
