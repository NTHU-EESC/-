#include <stdio.h>

int main (void){
	int a[5],i,D_R;
	for(i=0;i<4;i++)
		scanf("%d",&a[i]);
	if(a[0]+a[2]==a[1]*2){
		D_R = a[1]-a[0];
		a[4]= a[0]+4*D_R;
	}else{
		D_R = a[1]/a[0];
		a[4]= a[3]*D_R;
	}
	printf("%d %d",a[4],D_R);
	
	return 0 ;
} 
