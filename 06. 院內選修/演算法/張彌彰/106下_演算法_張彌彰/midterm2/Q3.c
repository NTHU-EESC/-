// Q3 104061212 馮立俞
// Min cost to travel from Boston to Washington.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){
	int i,j,k,m; 
	char *buff;
	int p[15][15];
	char **station;
	bool S[15];
	int d[15];
	int pred[15];
	int MaxP = 8100;

	buff = malloc(sizeof(char *));
	station = malloc(15 * sizeof(char *));
	for(i = 0; i< 15; i++)
		station[i] = malloc(sizeof(char*));

	for(i = 0; i <15; i++){
		scanf("%[^\n]", buff);
		getchar();
		strcpy(station[i], buff);
		printf("%s\n", station[i]);
	}
	for(i = 0; i< 15; i++){
		for(j = 0; j < 15; j++){
			scanf("%d", &p[i][j]);
		}
	}

	for(i = 0; i< 15; i++){
		for(j = 0; j < 15; j++){
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	////////////////
	for( i = 0; i < 15; i++){
		S[i] = false;
		d[i] = p[0][i];
		pred[i] = 0;
	}
	S[0] = true; d[0] = 0;
	
	for(k = 1; k < 15; k++){
		for(m = 0, MaxP = 8100; m < 15; m++){
			if(S[m]== false && d[m] < MaxP)
				{ i = m; MaxP = d[m];}
		}
		S[i] = true;
		for(j = 0; j < 15; j++){
			if(S[j] == false){
				if(d[j] > d[i] + p[i][j]){
					d[j] = d[i] + p[i][j];
					pred[j] = i;
				}
			}
		}	
	}
	for (i = 0; i< 15; i++)
		printf("pred[%d] = %d\n",i,pred[i]);

	printf("minimum cost = %d\n", d[14]);
	i = 14;
	do{
		printf("%d", i);
		printf("%s<-%s $ %d\n",
				station[i], station[ pred[i] ],p[i][ pred[i] ] );
		i = pred[i];
	
	}while(i != 0);
	
	


	return 0;
}
