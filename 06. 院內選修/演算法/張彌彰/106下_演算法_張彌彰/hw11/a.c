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
void printResult(char ** city);			//print min path and cost
int Bound(int src, int dest, int **mat, int bound);		//calculate lower bound
void DFS(int level, int *visitlst, int *sollst, int **mat, int bound);
										//Try path using Depth First Search
void copyList(int *dest, int *src){		
	int i;

	for ( i = 0; i < N; ++i)	dest[i] = src[i];
}

void copyArray(int **dest,int **src ){	
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
	printf("Total Cost = %d \n", minCost );
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



void DFS(int level, int *visitlst, int *sollst, int **mat, int bound){
	int i;
	int **tmat;
	int tbound;

	tmat = malloc( N * sizeof(int *) );
	for (i = 0; i < N; i++)	tmat[i] = malloc( N * sizeof(int ) );

	//end of traversal
	if (level == N){

		if(bound <= minCost){
			//Solution Found
			copyList(minRoute, sollst);
					//memcpy(minRoute, sollst, N * sizeof(int) );
			minCost = bound;
		}
	}
	else{
		visitlst[ sollst[ level-1 ]  ] = 1;
		for(i = 1; i < N; i++){

			if(visitlst[i] == 0 ){

				// generate bound and mat
				copyArray(tmat, mat);//memcpy( tmat, mat, N*N*sizeof(int) );
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
		}
	}
}

void InsertionSort(int *list,int n){
    int i,j,k,m;
    int temp;


    for(j = 1; j < n; j++){
        temp = list[j];
        
        i = j-1;
        while((i>=0) && (temp > list[i] ) ){
            list[i+1] = list[i];
            i--;
        }
        list[i+1] = temp;

    }
    for ( i = 0; i < n; ++i)
    {
    	printf(" %d\n",list[i] );
    }
}

void rInsertionSort(int *list,int n){
    int i,j,k,m;
    int temp;


    for(j = 1; j < n; j++){
        temp = list[j];
        
        i = j-1;
        while((i>=0) && (temp < list[i] ) ){
            list[i+1] = list[i];
            i--;
        }
        list[i+1] = temp;

    }
    for ( i = 0; i < n; ++i)
    {
    	printf(" %d\n",list[i] );
    }
}

int pa(int **mat, int b)
{	
	int A[N];
	int Per=0,i,j=0,k=0,value;
	int a,cost;
	int **tmat;
	int temp;
	int bound;
	
	tmat = malloc(N* sizeof(int *));
	for (i = 0; i< N; i++)
		tmat[i] = malloc(N * sizeof(int));

	minCost = INF;

	for(i=0;i<N;i++)						//
		A[i]=i;							//initialize A to be 0,1,2,3...N-1
	for(;;){
		printf("permutation #%d:",++Per);	//
		for(i=0;i<N;i++)					//
			printf(" %d",A[i]);				//print permutation
		printf("\n");
		if(A[1]==N) return minCost;

		//calculate bound
		for (i = 0, copyArray(tmat, mat), bound = b; i < N-1; i++){
			bound = Bound( A[i], A[i+1] , tmat, bound);
			//for(i = 0; i< N; i++){
			//	for(j = 0; j < N; j++)
			//		printf("%5d ", mat[i][j]);
			//	printf("\n");
			//}
			printf("bound = %d, min = %d \n",bound, minCost );
			if (bound > minCost){
				printf("Exit at %d\n",i);
				if (i==0){

					for( a = 0; a< N && A[a] != A[1]+1;a++ );
					A[1]++ ; A[a]--;
					rInsertionSort(A+2, N-2);
				}
				else InsertionSort(A+i+1, N-i-1 );
				i = N; // break;
			}
		}
		bound += mat[ A[N-1] ][0];

		if(i == N-1 && bound <= minCost ){
			minCost = bound;
			copyList(minRoute,A);
		}

		/*
		for( a = 0, cost = 0; a < N-1; a++ )
			cost += mat[ A [a] ][ A[a+1] ];
		cost += mat[ A[N-1] -1 ][0];
		if(cost < minCost){
			minCost = cost;
			copyList(minRoute,A);
		}*/

		//if fail, revert to prev mat & skip

		for(i=N-2;i>=0 && A[i]>=A[i+1];i--){}
			j=i;							//find largest j, A[j]<A[j+1]
		if(i==-1 || A[1] ==0){							//if j is not found
			printf("  Total number of permutations is %d\n",Per);
			return minCost;						//that's the last permutation
		}
		for(i=N-1;i>=0 && A[i]<=A[j];i--){}	//
			k=i;							//find largest k A[k]>A[j]
		value=A[j];							//
		A[j]=A[k];							//
		A[k]=value;							//swap A[j] and A[k]
		for(i=1; j+1 < N-i ; j++,i++){		//
			value=A[j+1];					//
			A[j+1]=A[N-i];					//reverse the value
			A[N-i]=value;					//from A[j+1] to  A[N-1]
		}
	}
}



int pb(int **mat)
{	
	int A[N];
	int Per=0,i,j=0,k=0,value;
	int a,cost;
	int **tmat;
	int temp;

	tmat = malloc(N* sizeof(int *));
	for (i = 0; i< N; i++)
		tmat[i] = malloc(N * sizeof(int));

	minCost = INF;

	for(i=0;i<N;i++)						//
		A[i]=i;							//initialize A to be 0,1,2,3...N-1
	for(;;){
		printf("permutation #%d:",++Per);	//
		for(i=0;i<N;i++)					//
			printf(" %d",A[i]);				//print permutation
		printf("\n");
		if(A[0]==1) return minCost;
		
		for( a = 0, cost = 0; a < N-1; a++ )
			cost += mat[ A [a] ][ A[a+1] ];
		cost += mat[ A[N-1] ][0];
		if(cost < minCost){
			minCost = cost;
			copyList(minRoute,A);
		}

		for(i=N-2;i>=0 && A[i]>=A[i+1];i--){}
			j=i;							//find largest j, A[j]<A[j+1]
		if(i==-1 || A[1] ==0){							//if j is not found
			printf("  Total number of permutations is %d\n",Per);
			return minCost;						//that's the last permutation
		}
		for(i=N-1;i>=0 && A[i]<=A[j];i--){}	//
			k=i;							//find largest k A[k]>A[j]
		value=A[j];							//
		A[j]=A[k];							//
		A[k]=value;							//swap A[j] and A[k]
		for(i=1; j+1 < N-i ; j++,i++){		//
			value=A[j+1];					//
			A[j+1]=A[N-i];					//reverse the value
			A[N-i]=value;					//from A[j+1] to  A[N-1]
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

	scanf(" %d", &N);

	minCost = N * INF;
	minRoute = malloc(N * sizeof(int));


	city = malloc(N * sizeof(char *));
	mat = malloc(N * sizeof(int *));

	for(i = 0; i< N; i++){
		city[i] = malloc(sizeof(char*));
		mat[i] = malloc(N * sizeof(int) );
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
		    scanf("%d", &mat[i][j]);
	
	for( i = 0; i < N; i++)	mat[i][i] = INF;

	for(i = 0; i< N; i++){
		for(j = 0; j < N; j++)
			printf("%5d ", mat[i][j]);
		printf("\n");
	}


	printf("Validation Min: %d\n",pb(mat) );
	for (i = 0; i < N ;i++){
		printf("%d : %s\n",i+1, city[ minRoute[i] ]);
	}
	printf("%d : %s\n",i+1, city[0]);
	printf("--------------------------\n");

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

	DFS(1, visitlst, sollst, mat, bound );
	printResult(city);
	
	
	return 0;
}
