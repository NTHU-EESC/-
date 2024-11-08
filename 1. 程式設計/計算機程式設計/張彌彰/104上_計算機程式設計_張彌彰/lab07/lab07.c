/*EE231002 Lab07. Matrix Determinants
  104061212 , Li-yu Feng
  Date:2015/11/14
*/

#if !defined(N)
#define N 3
#endif

#include <stdio.h>
#include <stdlib.h>

int A[N][N],B[N],det;						

int permutation(void);					
int product(void);
int sgn(int t);
void PrintResult(void);

int main(void)
{
	int i,j,t=1;

	for(i=0;i<N;i++){						//scan input matrix A
		for(j=0;j<N;j++){					//
			scanf("%d",&A[i][j]);			//
		}
	}
	for(i=0;i<N;i++)						//B=sigma ,belongs to Sn
		B[i]=i;								//initialize B to be 0,1,2...N-1
	det += product();
	do{
		t=permutation();
		det += sgn(t) * product();			//Equation (7.1)
	}while( t != 0 );
	exit(EXIT_FAILURE);
}

/******recycle lab05 (Pandita algorithm)******/
int permutation(void)
{
	int i,j=0,k=0,value,Nswap=0;		//value for swapping Nswap as counter
	
	for(i=N-2;i>=0 && B[i]>=B[i+1];i--){}
		j=i;							//find largest j, B[j]<B[j+1]
	if(i==-1){							//if j is not found
		PrintResult();					//we got the last permutation
		exit(EXIT_SUCCESS);				//print and terminate!
	}
	for(i=N-1;i>=0 && B[i]<=B[j];i--){}	//
		k=i;							//find largest k B[k]>B[j]
	value=B[j];							//
	B[j]=B[k];							//
	B[k]=value;							//swap B[j] and B[k]
	Nswap++;
	for(i=1; j+1 < N-i ; j++,i++){		//
		value=B[j+1];					//
		B[j+1]=B[N-i];					//reverse the value
		B[N-i]=value;					//from B[j+1] to  B[N-1]
		Nswap++;
	}
	return Nswap;						//Nswap for sgn judgement
}

int sgn(int t)
{
	int i;
	static int sgn=1;					//sgn=1 according to Equation (7.2)
	for(i=0;i<t;i++)
		sgn *= -1;						//determine sgn by swap count
	return sgn;
}

int product(void)
{
	int product=1,i;					
	for(i=0;i<N;i++)					//
		product *= A[i][B[i]];			//multiply from row 0 to row N-1
	return product;						//using B(sigma) to pick out 
}										//which element to choose

void PrintResult(void)					//Just print it	
{
	int i,j;
	printf("Input matrix is\n");
	for(i=0;i<N;i++){
		printf(" ");
		for(j=0;j<N;j++)
			printf(" %d",A[i][j]);
		printf("\n");
	}
	printf("Det = %d\n",det);
			
}

