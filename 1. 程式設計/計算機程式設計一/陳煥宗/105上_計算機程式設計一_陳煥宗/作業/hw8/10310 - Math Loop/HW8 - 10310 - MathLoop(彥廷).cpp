#include <stdio.h>
int happened[100];
void Loop(int , int , int);

int main(void){
	int num,i,x;
	
	scanf("%d",&num);
	for(x=num,i=0;x>0;i++)
		x/=10;
	Loop(num,0,i);
	return 0;
}

void Loop(int pre , int tm , int n){
	int a[10],i,j,cur,tmp,cal=pre;
	happened[tm]=pre;
	for(i=n-1;i>=0;i--){
		a[i]=cal%10;
		cal/=10;
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++)
			if(a[j]<a[j+1]){
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
	}
	cur = a[0]-a[n-1];
	for(i=1;i<n;i++){
		cur *= 10;
		cur += a[i]-a[n-1-i];
	}
	tm ++;
	short int check=0 ;
	for(i=0;i<tm;i++)
		if(cur==happened[i]){
			check = 1;
			break;
		}
	if(check){
		printf("%d\n",tm);
		return;
	}else
	Loop(cur,tm,n);
}

