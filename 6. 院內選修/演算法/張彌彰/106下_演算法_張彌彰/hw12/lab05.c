/*EE231002 Lab05. Permutations
 104061212 , Li-Yu Feng
 Date 2015/10/26
*/

#include <stdio.h>
#define N 5

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
    //for ( i = 0; i < n; ++i)
    //{
    //	printf(" %d\n",list[i] );
    //}
}

int main(void)
{
	int A[N]={};
	int Per=0,i,j=0,k=0,value;
	
	for(i=1;i<=N;i++)						//
		A[i-1]=i;							//initialize A to be 1,2,3...N
	for(;;){
		printf("permutation #%d:",++Per);	//
		for(i=0;i<N;i++)					//
			printf(" %d",A[i]);				//print permutation
		printf("\n");
/////////////////////////////////////
		if(A[1] == 4) {InsertionSort(A+2,3); printf("-------skip\n");
		}
////////////////////////////////////
		for(i=N-2;i>=0 && A[i]>=A[i+1];i--){}
			j=i;							//find largest j, A[j]<A[j+1]
		if(i==-1){							//if j is not found
			printf("  Total number of permutations is %d\n",Per);
			return 0;						//that's the last permutation
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
