/*EE3980 HW01 Quadratic Sorts
 *Li-Yu Feng 104061212
 *Date: 2018/3/7
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

void SelectionSort(char **list,int n);
void InsertionSort(char **list,int n);
void BubbleSort(char **list,int n);
double GetTime(void);

void InsertionSort(char **list,int n){
    int i,j;
    char *temp;

    for(j = 1; j < n; j++){
        temp = list[j];
        i = j-1;
        while((i>=0) && (strcmp(temp,list[i]) < 0) ){
            list[i+1] = list[i];
            i--;
        }
        list[i+1] = temp;
    }
}

void BubbleSort(char **list,int n){
    int i,j;
    char *temp;

    for (i = 0; i < n-1; i++){
        for(j = n-1; j > i; j--){
            if( strcmp(list[j],list[j-1]) < 0 ){   
               temp = list[j];				// swapping
               list[j] = list[j-1];			//
               list[j-1] = temp;			//
            }
        }
    }
}


void SelectionSort(char **list,int n){
    int i,j,k;
    char *temp;

    for(i = 0; i < n; i++){
        j = i;
        for(k = i+1;k < n; k++){
            if( strcmp(list[k],list[j]) < 0 )
                j = k;
        }
        temp = list[i];			//
        list[i] = list[j];		//
        list[j] = temp;			//swapping the remaining smallest(j) with i
    }
}


double GetTime(void)
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec+1e-6*tv.tv_usec;
}

int main()
{
    int i,j;
    int Nwords;
    double t1,t2;
    char **words,**A;

	scanf("%d", &Nwords);
    words = (char**)malloc(Nwords * sizeof(char*));		//
    for(i = 0; i < Nwords; i++)							//
        words[i] = (char *)malloc(sizeof(char*));		//
    A = (char**)malloc(Nwords * sizeof(char*));			//
    for(i = 0; i < Nwords; i++)							//
        A[i] = (char *)malloc(sizeof(char*));			//
   
	for(i = 0; i < Nwords ; i++){						//
		scanf("%s", words[i]);							//scan words	
    }

//Perform insertion sort
    t1 = GetTime();
    for(i = 0; i<500; i++){
        memcpy(A,words,Nwords * sizeof(char*));
        InsertionSort(A, Nwords);
        if(i==0){
            for(j = 0; j < Nwords ; j++)
                printf("%d %s\n",j+1,A[j]);
        }
    }
    t2 = GetTime();
    printf("%s:\nN=%d\nCPU time = %.5g seconds\n", "insertion sort",Nwords, (t2-t1)/500.0);



	free(words);	//avoid memory leakage
	free(A);
    return 0;
}



