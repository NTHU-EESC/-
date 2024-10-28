// Q4 104061212 馮立俞
// The second shortest path.


/******************************************************
  EE3980 Algorithms HW11 Travelling Salesperson Problem
  Li-Yu Feng 104061212
  Date:2018/5/25
*******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 999		// fake positive infinity

float minCost;		//min travel cost
float secMinCost;
int *minRoute;		//shortest travel path
int *secMinRoute;
int N;				//number of cities

void copyList(int *dest, int *src);	//replace buggy memcpy()
void copyArray(float **dest,float **src );	//replace buggy memcpy()
void printResult(char ** city);			//print min path and cost
int Bound(int src, int dest, float **mat, float bound);		//calculate lower bound
void DFS(int level, int *visitlst, int *sollst, float **mat, float bound);
										//Try path using Depth First Search
void copyList(int *dest, int *src){		
	int i;

	for ( i = 0; i < N; ++i)	dest[i] = src[i];
}

void copyArray(float **dest,float **src ){	
	int i,j;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			dest[i][j] = src[i][j];
}

void printResult(char ** city){			//print min path and cost
	int i;

	for (i = 0; i < N ;i++){
		printf("%d : %s\n",i+1, city[ minRoute[i] ]);
	}
	printf("%d : %s\n",i+1, city[0]);
	printf("Total Cost = %f \n", minCost );
}

int Bound(int src, int dest, float **Mat, float bound){
	int i,j;		//src:source dest: destination, Mat: cost Matrix
	float tempMin;	//bound prev bound

	bound += Mat[src][dest];

	for (i = 0; i < N; i++)
		Mat[src][i] = INF;
	for (i = 0; i < N; i++)
		Mat[i][dest] = INF;
	Mat[dest][src] = INF;

	for (i = 0; i < N; i++){
		for (j = 0, tempMin = Mat[i][0]; j < N; j++)
			if(Mat[i][j] < tempMin) tempMin = Mat[i][j];
		if(tempMin != 0 && tempMin != INF){
			for (j = 0; j < N; j++)
				if(Mat[i][j] != INF) Mat[i][j] -= tempMin;
			bound += tempMin;
		}
	}

	for (j = 0; j < N; j++){
		for (i = 0, tempMin = Mat[0][j]; i < N; i++)
			if(Mat[i][j] < tempMin) tempMin = Mat[i][j];
		if(tempMin != 0 && tempMin != INF){
			for (i = 0; i < N; i++)
				if(Mat[i][j] != INF) Mat[i][j] -= tempMin;
			bound += tempMin;
		}
	}
	return bound;
}



void DFS(int level, int *visitlst, int *sollst, float **mat, float bound){
	int i;
	float **tmat;
	float tbound;

	tmat = malloc( N * sizeof(int *) );
	for (i = 0; i < N; i++)	tmat[i] = malloc( N * sizeof(int ) );

	//end of traversal
	if (level == N){
		printf("1:%f 2:%f\n", minCost, secMinCost);

		if(bound < minCost){
			copyList(secMinRoute, minRoute);
					//memcpy(minRoute, sollst, N * sizeof(int) );
			secMinCost = minCost;
			
			//Solution Found
			copyList(minRoute, sollst);
					//memcpy(minRoute, sollst, N * sizeof(int) );
			minCost = bound;
		}
		else if(bound < secMinCost){
			copyList(secMinRoute, sollst);
					//memcpy(minRoute, sollst, N * sizeof(int) );
			secMinCost = bound;
		}
	}
	else{
		visitlst[ sollst[ level-1 ]  ] = 1;
		for(i = 1; i < N; i++){

			if(visitlst[i] == 0 ){

				// generate bound and mat
				copyArray(tmat, mat);//memcpy( tmat, mat, N*N*sizeof(int) );
				tbound = Bound(sollst[ level-1 ], i,tmat, bound);
				if(tbound < secMinCost){
					//go to next city
					visitlst[i] = 1;
					sollst[level] = i;

					DFS(level+1, visitlst, sollst, tmat, tbound);
					visitlst[i] = 0;
					//revert variables to original;
				}
			}
		}
	}
}





int main(){
	int i,j; 

	float **mat;
	char **city;
	int *visitlst;
	int *sollst;
	float bound = 0;
	float tempMin;

	scanf(" %d", &N);

	minCost = N * INF;
	secMinCost = N * INF;
	minRoute = malloc(N * sizeof(int));
	secMinRoute = malloc(N * sizeof(int));


	city = malloc(N * sizeof(char *));
	mat = malloc(N * sizeof(float *));

	for(i = 0; i< N; i++){
		city[i] = malloc(sizeof(char*));
		mat[i] = malloc(N * sizeof(float) );
	}

	visitlst = calloc(N, sizeof(int));
	sollst = calloc(N, sizeof(int));


	for(i = 0; i <N; i++){
		scanf(" %[^\n]", city[i]);

		getchar();

		printf("%d %s\n",i+1, city[i]);
	}
	for(i = 0; i< N; i++)
		for(j = 0; j < N; j++)
		    scanf("%f", &mat[i][j]);
	
	for( i = 0; i < N; i++)	mat[i][i] = INF;

	for(i = 0; i< N; i++){
		for(j = 0; j < N; j++)
			printf("%5f ", mat[i][j]);
		printf("\n");
	}
	printf("1:%f 2:%f\n", minCost, secMinCost);


	/*printf("Validation Min: %d\n",pb(mat) );
	for (i = 0; i < N ;i++){
		printf("%d : %s\n",i+1, city[ minRoute[i] ]);
	}
	printf("%d : %s\n",i+1, city[0]);
	printf("--------------------------\n");
	*/
	minCost = INF;

	bound = 0;
	visitlst[0] = 1;
	sollst[0] = 0;
	
	for (i = 0; i < N; i++){
		for (j = 0, tempMin = mat[i][0]; j < N; j++)
			if(mat[i][j] < tempMin) tempMin = mat[i][j];
		if(tempMin != 0 && tempMin != INF){
			for (j = 0; j < N; j++)
				if(mat[i][j] != INF) mat[i][j] -= tempMin;
			bound += tempMin;
		}
	}

	for (j = 0; j < N; j++){
		for (i = 0, tempMin = mat[0][j]; i < N; i++)
			if(mat[i][j] < tempMin) tempMin = mat[i][j];
		if(tempMin != 0 && tempMin != INF){
			for (i = 0; i < N; i++)
				if(mat[i][j] != INF) mat[i][j] -= tempMin;
			bound += tempMin;
		}
	}
	printf("b:%f\n",bound);

	DFS(1, visitlst, sollst, mat, bound );
	printResult(city);
	printf("------Second:--------\n");

	
	minRoute = secMinRoute ;
	minCost = secMinCost;
	printResult(city);
	
	
	return 0;
}
