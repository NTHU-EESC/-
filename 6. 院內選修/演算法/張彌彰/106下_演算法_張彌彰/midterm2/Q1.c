// Q1 104061212 馮立俞
// The number with the highest frequency.



#include <stdio.h>
#include <stdlib.h>



int main(){
	int count[1101];
	int i;
	int temp;
	int maxfreq = 0;
	int N = -1;
	
	for (i = 0; i < 1101; i++){
		count[i] = 0;
	}

	for(i = 0; i <10000; i++){
		scanf("%d", &temp);
		count [temp]++;
		
	}

	for( i = 0; i < 1101; i++){
		if(count[i] > maxfreq){
			maxfreq = count[i];
			N = i;
		}
	
	}

	printf("N = %d, MaxFreq= %d", N, maxfreq);


}
