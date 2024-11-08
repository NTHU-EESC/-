#include <stdio.h>
#include <string.h>
int main(void){
	int i,j,k,max=0,check,n,cur,len_a,len_b;
	char a[4],b[9];

	for(i=0;(a[i]=getchar())!='\n'; )i++;  //此for只讀這一行(只讀到這個分號
	len_a=i;
	scanf("%d",&n);
	getchar();
	for(i=0 ; i<n ; i++){

		cur = 0;

		for(j=0 ; (b[j]=getchar())!='\n' ; )j++;
		len_b = j;  //此在for的外面
		b[j]='\0';
		for(j=0 ; j<=len_b-len_a ; j++){
			check = 1;

			for(k=0 ; k<len_a ; k++){
				if(a[k]!=b[j+k])
					check = 0;
			}

			if(check==1)
				cur++;
		}

		if(cur>max)
			max = cur;
	}
	printf("%d",max);
	return 0;
}
