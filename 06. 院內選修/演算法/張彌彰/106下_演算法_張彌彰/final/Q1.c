// Q1 104061212 馮立俞
// The medium word.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char** list, int i, int j){
	char *temp;
	
	temp = list[i];
	list[i] = list[j];
	list[j] = temp;
}

int part(char **list, int high, int low){
	char *temp = list[low];
	int i,j;

	i = low+1;
	j = high;
	while(i < j){
		while( (strcmp(temp, list[i]) > 0 ) && i < j ) i++;
		while( (strcmp(temp, list[j]) < 0 ) && i <j ) j--;
		if(i < j)swap(list,i,j);
	}
	list[low] = list[j];
	list[j] = temp;

	return j;
}

int main()
{

    int i,j;
    int Nwords;
    double t1,t2;
    char **words,**A;
	char *temp;
	int mid;
	int high,low;
	int t;

	scanf("%d", &Nwords);
    words = (char**)malloc(Nwords * sizeof(char*));		//
    for(i = 0; i < Nwords; i++)							//
        words[i] = (char *)malloc(sizeof(char*));		//
    A = (char**)malloc(Nwords * sizeof(char*));			//

   
	for(i = 0; i < Nwords ; i++){						//
		scanf("%s", words[i]);							//scan words	
    }

	for(i = 0; i < Nwords ; i++){						//
		printf("%s\n", words[i]);							//scan words	
    }
	mid = (Nwords+1)/2;
	high = Nwords-1; low = 0;
	
	t = part(words,high, low);
	
	while(t != mid-1){
		printf("%d\n", t);
		printf("h: %d l: %d\n", high, low);
		if(t > mid-1)
			high = t-1	;
		else
			low = t+1;
		t = part(words, high, low);
	}
	printf("%s\n", words[mid-1]);
	printf("%d\n", mid);

	free(words);	//avoid memory leakage
	free(A);
    return 0;
}
