// Q2 104061212 馮立俞
// Number of solutions.

/************************************************
  EE3980 Algorithms HW10 Finding Equal Partitions
  Li-Yu Feng 104061212
  Date:2018/5/15
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void InsertionSort(int *list,int n, int *indexlst);			
								//sort in decreasing order
void PrintResult(float *numbers,int N,float target, int *sol, int *indexlst);
								//as named
void SumOfSub(float *numbers, int N, float target,int *sol,
				 float currSum, int k, float res , int *indexlst);
								//find sum of subset = target

/*double GetTime(void)
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec+1e-6*tv.tv_usec;
}*/

void InsertionSort(int *list,int n, int *indexlst){
    int i,j,k,m;
    int temp;


    for(j = 1; j < n; j++){
        temp = list[j];
        for (k = 0; k < n && indexlst[k] != j ;k++);
        
        i = j-1;
        while((i>=0) && (temp > list[i] ) ){
            list[i+1] = list[i];
            for (m = 0; m < n && indexlst[m]!= i; m++);
            indexlst[m] = i+1;
            i--;
        }
        list[i+1] = temp;
        indexlst[k] = i+1;
    }
}


void PrintResult(float *numbers,int N,float target, int *sol, int *indexlst){
	static int solCount = 0;
	int i;

	++solCount;
	//if(solCount > 1) exit(1);
	printf("Solution %d\n",solCount );
	printf("Solution: SUM(S0)=%f SUM(S1)=%f\n",target,target/5.0 );
	for ( i = 0; i < N; ++i)
	{
		if(sol[i]==1)	printf("  A[%d]=%f -> %s\n",
					i+1,numbers[indexlst[i]], "S0" );
		else 			printf("  A[%d]=%f -> %s\n",
					i+1,numbers[indexlst[i]], "S1" );
	}

	
}

void SumOfSub(float *numbers, int N, float target,int *sol,
				 float currSum, int k, float res , int *indexlst){
		// sol: S0/S1 , numbers: A , N elements in A, target: target sum
		// res: residue, currSum : surrent sum, indexlst: new place after sorting
	int i;
	
	if(k==N-1){
		if( (currSum + numbers[k]) == target){
			sol[k] = 1;
			PrintResult(numbers,N,target,sol, indexlst);
		}
	}
	else{
		for(i = k; i < N; i++) sol[i] = 0;	//clear sol
		sol[k] = 1;
		if(currSum + numbers[k] == target){
			PrintResult(numbers,N,target,sol, indexlst);
		}
		else if(currSum + numbers[k] < target)
			SumOfSub(numbers, N, target,sol, currSum + numbers[k],
			k+1, res - numbers[k], indexlst);

		if ( currSum + res - numbers[k] >= target ){
			sol[k] = 0;
			SumOfSub(numbers, N, target,sol, currSum, k+1,
			res - numbers[k], indexlst);
		}
	}

}

int main(){
	int N;
	int i;//,j;
	float *numbers;
	int *sol, *indexlst;
	float target;
	//double t;


	scanf("%d", &N);
	numbers = malloc(N * sizeof(float));
	sol = malloc(N * sizeof(int));
	indexlst = malloc(N * sizeof(int));		
	for(i = 0; i < N; i++) sol[i] = 0;		//init
	
	for (i = 0, target = 0; i < N; i++){
		scanf("%f", &numbers[i]);
		indexlst[i] = i;
		target += numbers[i];
	}		
								//read input
	for (i = 0; i < N; i++)
		printf("%f\n", numbers[i]);
	printf("%f\n", target);
	target *= 5.0/6.0;
	printf("%f\n", target);
	
	//InsertionSort(numbers,N, indexlst);		//sorting

	sol[0] = 1;



	SumOfSub( numbers, N, target,sol,
				 0, 0, target *6.0/5.0, indexlst );//
	printf("No Solution found.\n");
	return 0;
}
