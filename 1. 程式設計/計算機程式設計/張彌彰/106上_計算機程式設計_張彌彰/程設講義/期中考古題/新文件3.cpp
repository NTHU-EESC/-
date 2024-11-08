#include <stdio.h>	
#define N 6	
int A[N] = {1, 2, 3, 4, 5, 6};
int i, j, temp;


int main(void)
{
	for (i=0; i<N/2; i++){
		temp = A[2*i+1];
		A[2*i+1] = A[2*i] ;
		A[2*i] = temp;
	}
	
	for (i=0; i<N; i++){
		printf("%d", A[i]);
	}
	return 0;
}
