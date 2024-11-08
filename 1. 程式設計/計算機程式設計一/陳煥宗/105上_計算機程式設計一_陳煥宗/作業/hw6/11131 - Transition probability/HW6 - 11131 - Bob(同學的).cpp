#include <stdio.h>
int main (void){
	int N,i,j,ans;
	float p[4],curp[4],prep[4],T;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		ans = 1;
		
		for(j=0;j<4;j++){
			scanf("%f",&p[j]);
			curp[j]=p[j];
			prep[j]=p[j];
		}
		
		scanf("%f",&T);
		while(curp[0]>T){
			curp[0]=prep[0]*p[0]+prep[2]*p[1];
			curp[2]=prep[0]*p[2]+prep[2]*p[3];
			curp[1]=prep[1]*p[0]+prep[3]*p[1];
			curp[3]=prep[1]*p[2]+prep[3]*p[2];
			for(j=0;j<4;j++)
				prep[j]=curp[j];
			ans ++ ;
		}
		
		printf("%d\n",ans);
	}	
	return 0;
}
