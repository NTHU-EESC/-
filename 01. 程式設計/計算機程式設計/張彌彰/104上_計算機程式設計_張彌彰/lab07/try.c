#if !defined (N)
#define N 3
#endif

#include<stdio.h>

int main(void)
{
	int i,j,A[N][N];
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d",&A[i][j]);
		}
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%d",A[i][j]);
		}
		printf("\n");
	}
}
