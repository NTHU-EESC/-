/*EE231002 Lab06. Latin Squares
*104061212,Li-Yu Feng
*Date:2015/11/2
*/

#include<stdio.h>

#if !defined(N)
#define N 3
#endif

int A[N][N];
int B[N+1]={0};
int Nsquare=0;

void print(void);										//print Latin square
void clearB(void);										//for checking recurring elements

int main(void)
{
	int i,j,k;

	for(i=0;i<N;i++){									//
		for(j=0;j<N;j++)								//initialize all
		A[i][j]=1;										//element to be 1
	}
	for( ; A[N-1][N-1] < N+1 ; ){						//search from 11...1
		A[0][0] += 1;									//   to       NN...N
		for(i=0;i<N;i++){								//
			for(j=0; j<N ;j++){							//
	
				if(A[i][j]==N+1 && j<N-1){				//carry from left
					A[i][j]=1;							//to right
					A[i][j+1] += 1;						//
				}
				if(A[i][j]==N+1 && j==N-1 && i<N-1){	//carry to next row
					A[i][N-1]=1;						//
					A[i+1][0] += 1;						//
				}										//
			}
		}
		/*find the square without recurring*/
		for( i=0,j=N ;i<N  && j==N;i++){				//
			clearB();									//Array B for
			for(j=0 ; j<N && B[ A[i][j] ] != 1; j++ )	//documenting letter
				B[A[i][j]]=1;							//occurrence
		}
		if(i==N && j==N){								// all row legible?
			for( j=0, i=N ;j<N && i==N;j++){			//
				clearB();								//
				for(i=0;i<N && B[A[i][j]] != 1 ;i++)	//
					B[ A[i][j] ]=1;						//
			}
		}
		if(j==N && i==N)								//all column legible?
		print();
	}
	printf("Total number of Latin Squares found is %d\n",Nsquare);
	return 0;
}

void clearB(void)
{
	int k;
	for(k=0;k<N+1;k++)									//assign all B elements
		B[k]=0;											//to be 0
}														//for next row/column
														//testing
void print(void)										
{														//print Latin square
	int i,j;

	printf("Latin Square %d:\n",++Nsquare);
	for(i=0;i<N;i++){
		printf(" ");
		for(j=0;j<N;j++)
			printf(" %c",A[i][j]+64);					//convert numbers to
			printf("\n");								//alphabets using ASCII
	}
}

