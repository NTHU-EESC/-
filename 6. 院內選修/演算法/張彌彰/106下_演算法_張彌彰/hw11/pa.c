

#include <stdio.h>


int pa(int N, int **mat)
{	
	int *A,*minRoute;
	int Per=0,i,j=0,k=0,value;
	int a,b,cost, minCost;

	A = malloc( N *sizeof(int) );
	minRoute = malloc( N *sizeof(int) );
	
	minCost = 999;
	for(i=1;i<=N;i++)						//
		A[i-1]=i;							//initialize A to be 1,2,3...N
	for(;;){
		printf("permutation #%d:",++Per);	//
		for(i=0;i<N;i++)					//
			printf(" %d",A[i]);				//print permutation
		printf("\n");
		for( a = 0, cost = 0; a < N-1; a++ )
			cost += mat[ A [a] ][ A[a+1] ];
		cost += mat[ A[N-1] ][0];
		if(cost < minCost){
			minCost = cost
		}

		for(i=N-2;i>=0 && A[i]>=A[i+1];i--){}
			j=i;							//find largest j, A[j]<A[j+1]
		if(i==-1){							//if j is not found
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
