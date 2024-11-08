#include <stdio.h>	//declare header
#define N 10	//define N
int A[N]={7, 10, 4, 8, 5, 6, 1, 4, 3, 2};
int lar=0, larspace=0, i;
int main(void)	
{
	for (i=0; i<N; i++){
		if (A[i]>lar && i%2==0){
			lar = A[i];
			larspace = i;
		}
	}
	printf("A[%d]=%d", larspace, lar);
	return 0;
} 
