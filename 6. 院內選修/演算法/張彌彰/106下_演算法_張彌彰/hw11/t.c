/******************************************************
  EE3980 Algorithms HW11 Travelling Salesperson Problem
  Li-Yu Feng 104061212
  Date:2018/5/25
*******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 999		// fake positive infinity

int minCost;		//min travel cost
int *minRoute;		//shortest travel path
int N;				//number of cities

void copyList(int *dest, int *src);	//replace buggy memcpy()
void copyArray(int **dest,int **src );	//replace buggy memcpy()
void printResult(char ** city, int **mat);			//print min path and cost
int Bound(int src, int dest, int **mat, int bound);		//calculate lower bound
void DFS(int level, int *visitlst, int *sollst, int **mat, int bound);
										//Try path using Depth First Search
int pb(int **mat); // validation

void copyList(int *dest, int *src){		
	int i;

	for ( i = 0; i < N; ++i)	dest[i] = src[i];
}

void copyArray(int **dest,int **src ){	
	int j;

	for(j = 0; j < N ; j++)
		memcpy( dest[j], src[j], N*sizeof(int) );
}

void printResult(char **city, int **mat){			//print min path and cost
	int i,k;
	int sum;
	int temp1, temp2;
	int split;
	int sum1,sum2;


	printf("Two-day travelling plan:\n");
	for (i = 0, sum = 0; sum < minCost/2.0 ;i++){
		sum += mat[ minRoute[i] ][ minRoute[i+1] ];	
	}
	sum2 = sum;
	split = i--;
	sum1 = sum2 - mat[ minRoute[i] ][ minRoute[i+1] ];
	if ( (sum2 - minCost/2.0) < (minCost/2.0 - sum1) ) sum1 = sum2;
	else { split--; }


	printf(" Day 1:\n");
	for (i = 0, sum = 0; i < split  ;i++){
		printf("  %s -> %s \n",city[ minRoute[i] ], city[ minRoute[i+1] ]);
		sum += mat[ minRoute[i] ][ minRoute[i+1] ];
	}
	printf("    Distance: %d\n",sum );

	printf(" Day 2:\n");
	for (sum = 0; i < N-1 ;i++){
		printf("  %s -> %s \n",city[ minRoute[i] ], city[ minRoute[i+1] ]);
		sum += mat[ minRoute[i] ][ minRoute[i+1] ];
	}
	printf("  %s -> %s\n",city[ minRoute[N-1] ], city[ minRoute[0] ]);
	sum += mat[ minRoute[N-1] ][ minRoute[0] ];
	printf("    Distance: %d\n",sum );
	k = sum1 - sum;
	printf(" Total distance: %d\n",minCost );
	printf("Day 1 and day 2 difference: %d\n", k > 0 ? k : -k );
}

int Bound(int src, int dest, int **Mat, int bound){
	int i,j;		//src:source dest: destination, Mat: cost Matrix
	int tempMin;	//bound prev bound

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

void InsertionSort(int list[N], int out[N]){
    int i,j,k,m;
    int temp;
	int t;

    for(j = 1; j < N; j++){
        temp = list[j];
        t = out[j];
        i = j-1;
        while((i>=0) && (temp < list[i] ) ){
            list[i+1] = list[i];
			out[i+1] = out[i];
            i--;
        }
        list[i+1] = temp;
		out[i+1] = t;
    }
}


void DFS(int level, int *visitlst, int *sollst, int **mat, int bound){
	int i,j,k;
	int **tmat;
	int tbound;
	int boundlst[N];
	int boundindex[N];
	int count;

	
	tmat = malloc( N * sizeof(int *) );
	for (i = 0; i < N; i++)	tmat[i] = malloc( N * sizeof(int ) );
	for(i = 0; i < N; i++)
		boundindex[i] = i;

	//end of traversal
	if (level == N){
		printf("end bound  :%d\n ", bound);
		if(bound < minCost){
			//Solution Found
			//copyList(minRoute, sollst);
			memcpy(minRoute, sollst, N * sizeof(int) );
			minCost = bound;
		}
	}
	else{
		visitlst[ sollst[ level-1 ]  ] = 1;
		
		for(i = 0, count = 1; i < N; i++){
			if(visitlst[i] == 0 ){
				for(j = 0; j < N ; j++)
					memcpy( tmat[j], mat[j], N*sizeof(int) );
				boundlst[i] = Bound(sollst[ level-1 ], i,tmat, bound);
				count++;
			}
			else boundlst[i] = INF;
		}
		for (i = 0; i < N; i++)
			printf( " %d", boundlst[i]);
		printf("\n");

		InsertionSort(boundlst, boundindex);
		
		for(i = 0; i < count; i++){
			j = boundindex[i];
			if(boundlst[j] < minCost && visitlst[j] == 0 ){
					//go to next city
					visitlst[j] = 1;
					sollst[level] = j;
					for(k = 0; k < N ; k++)
						memcpy( tmat[k], mat[k], N*sizeof(int) );

					tbound = Bound(sollst[ level-1 ], j,tmat, bound);
					DFS(level+1, visitlst, sollst, tmat, tbound);
					visitlst[j] = 0;
					//revert variables to original;
			}
		}
		/*for(i = 1; i < N; i++){

			if(visitlst[i] == 0 ){

				// generate bound and mat
				//copyArray from mat to tmat
				for(j = 0; j < N ; j++)
					memcpy( tmat[j], mat[j], N*sizeof(int) );


				tbound = Bound(sollst[ level-1 ], i,tmat, bound);
				if(tbound <= minCost){
					//go to next city
					visitlst[i] = 1;
					sollst[level] = i;

					DFS(level+1, visitlst, sollst, tmat, tbound);
					visitlst[i] = 0;
					//revert variables to original;
				}
			}
		}// */
	}
}




void LC(int level, int *visitlst, int *sollst, int **mat, int bound){
	int i,j,k;
	int **tmat;
	int tbound;
	int boundlst[N];
	int boundindex[N];
	int count;
	int M = N-1;

	

	if (level == N){

		if(bound < minCost){
			//Solution Found
			//copyList(minRoute, sollst);
			memcpy(minRoute, sollst, N * sizeof(int) );
			minCost = bound;
		}
	}
	else {
		tmat = malloc( N * sizeof(int *) );
		for (i = 0; i < N; i++)	tmat[i] = malloc( N * sizeof(int ) );
		for(i = 0; i < N; i++){
			boundindex[i] = i;
			boundlst[i] = INF;
		}

		for (i = 1, boundlst[0] = INF; i < N; i++){
			if(visitlst[i] == 0){
				copyArray(tmat, mat);
				boundlst[i] = Bound(sollst[ level-1 ], i,tmat, bound);
			}
			else boundlst[i] = INF;
		}
		InsertionSort(boundlst, boundindex);
		

		for (i = 0; i < N; i++){
			j = boundindex[i];

			if(boundlst[i] < minCost &&  (visitlst[j] == 0) ){
				//go to next city
				visitlst[j] = 1;
				sollst[level] = j;
				copyArray(tmat, mat);
				tbound = Bound(sollst[ level-1 ], j,tmat, bound);
				LC(level+1, visitlst, sollst, tmat, tbound);
				visitlst[j] = 0;
				//revert variables to original;
			}
			else i = N;
		}
	}

}




int main(){
	int i,j; 

	int **mat;
	char **city;
	int *visitlst;
	int *sollst;
	int bound = 0;
	int tempMin;
	int **gmat;

	scanf(" %d", &N);

	minCost = N * INF;
	minRoute = malloc(N * sizeof(int));


	city = malloc(N * sizeof(char *));
	mat = malloc(N * sizeof(int *));
	gmat = malloc(N * sizeof(int *));

	for(i = 0; i< N; i++){
		city[i] = malloc(sizeof(char*));
		mat[i] = malloc(N * sizeof(int) );
		gmat[i] = malloc(N * sizeof(int) );
	}


	visitlst = calloc(N, sizeof(int));
	sollst = calloc(N, sizeof(int));


	for(i = 0; i <N; i++){
		scanf(" %[^\n]", city[i]);

		getchar();

	}
	for(i = 0; i< N; i++)
		for(j = 0; j < N; j++)
		    scanf("%d", &mat[i][j]);
	
	for( i = 0; i < N; i++)	mat[i][i] = INF;

	copyArray(gmat, mat);


	//printf("Validation Min: %d\n",pb(mat) );
	//for (i = 0; i < N ;i++){
	//	printf("%d : %s\n",i+1, city[ minRoute[i] ]);
	//}
	//printf("%d : %s\n",i+1, city[0]);



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

	LC(1, visitlst, sollst, mat, bound );
	printResult(city, gmat);
	
	
	return 0;
}
