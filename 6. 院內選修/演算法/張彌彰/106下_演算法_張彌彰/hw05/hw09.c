/*******************************************
  EE3980 Algorithms HW09 Comparing Files
  Li-Yu Feng 104061212
  Date:2018/5/11
*******************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>




int main(int argc, char const *argv[]){
	char c, buff[1000], *paragraph[1000];
	bool done = false;
	int i, j,k;
	char *str;
	FILE *f1,*f2;

	fopen(argv[1], "r");
	fopen(argv[2], "r");


	while( fscanf( f1," %[^\n]", buff) != EOF ){
		printf("%s\n",buff );
	}

	while( fscanf( f2," %[^\n]", buff) != EOF ){
		printf("%s\n",buff );
	}

	/*for( done = false, j = 0 ; done == false; j++){
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
		
	}*/



	return 0;
}
