/*EE3980 HW02 Heap Sort
 *Li-Yu Feng 104061212
 *Date: 2018/3/18
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include<stdbool.h>

void SelectionSort(char **list,int n);
void InsertionSort(char **list,int n);
void BubbleSort(char **list,int n);

void Heapify(char **list, int i, int n);
void HeapSort(char **list,int n);			//sorting algorithms

void MaxHeapGen(char **list, int n);		//generate max heap
void MinHeapGen(char **list, int n);		//generate min heap
void MinHeapify(char **list,int i, int n);	
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

void Heapify(char **list, int i, int n){
	int j = i*2;
	char *temp = list[i-1];
	bool done = false;

	while(j<=n && !done){
		if(j<n && strcmp(list[j-1],list[j+1-1]) < 0) j++;
		if(strcmp(temp,list[j-1] ) > 0 ) done = true;
		else{
			list[j/2-1] = list[j-1];
			j *= 2;
		}
	}
	list[j/2-1] = temp;
}

void HeapSort(char **list,int n){
	char *temp;
	int i;

	for( i = n/2 ; i>0 ; i--)
		{Heapify(list,i,n);}
	for(i = n; i > 1; i-- ){
		temp = list[i-1];
		list[i-1] = list[0];
		list[0] = temp;
		Heapify(list,1,i-1);
	}
}

void MaxHeapGen(char **list, int n){
	int i;
	for( i = n/2 ; i>0 ; i--)
		{Heapify(list,i,n);}

}

void MinHeapGen(char **list, int n){
	int i;
	for( i = n/2 ; i>0 ; i--)
		{MinHeapify(list,i,n);}

}

void MinHeapify(char **list,int i, int n){
	int j = i*2;
	char *temp = list[i-1];
	bool done = false;

	while(j<=n && !done){
		if(j<n && strcmp(list[j-1],list[j+1-1]) > 0) j++;
		if(strcmp(temp,list[j-1] ) < 0 ) done = true;
		else{
			list[j/2-1] = list[j-1];
			j *= 2;
		}
	}
	list[j/2-1] = temp;

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
    char **words,**A,**OrderedCase,**ReversedCase,**MaxHeap,**MinHeap;
	
	int flag = 1;	//(1) insertion sort (2) selection sort 
					//(3) bubble sort (4) heap sort.
	
	int order = 1;  //(0) original (1) Ordered 
					//(2) Reversed  (3) MaxHeap (4) MinHeap
	
	

	scanf("%d", &Nwords);
    words = (char**)malloc(Nwords * sizeof(char*));		//
    for(i = 0; i < Nwords; i++)							//
        words[i] = (char *)malloc(sizeof(char*));		//
    A = (char**)malloc(Nwords * sizeof(char*));			//

	OrderedCase = (char**)malloc(Nwords * sizeof(char*));	//
	ReversedCase = (char**)malloc(Nwords * sizeof(char*));	//
	MaxHeap = (char**)malloc(Nwords * sizeof(char*));		//
	MinHeap= (char**)malloc(Nwords * sizeof(char*));		//

	for(i = 0; i < Nwords ; i++){						//
		scanf("%s", words[i]);							//scan words
	}

	memcpy( OrderedCase,words, Nwords * sizeof(char *) );
	HeapSort(OrderedCase,Nwords);
	for(i = 0;i < Nwords; i++)
		ReversedCase[i] = OrderedCase[Nwords-1-i];

	memcpy(MaxHeap, words, Nwords * sizeof (char *) );	//
	MaxHeapGen(MaxHeap,Nwords);							//
	memcpy(MinHeap, words, Nwords * sizeof (char *) );	//
	MinHeapGen(MinHeap,Nwords);							// Generrate best/worst 
														// case for Heapsort

	
	//Perform sorting
    t1 = GetTime();
    for(i = 0; i<500; i++){
    	
    	switch(order){
    		case 0:
				memcpy(A, words, Nwords * sizeof (char *) ); break;
			case 1:
				memcpy(A, OrderedCase, Nwords * sizeof (char *) ); break;
			case 2:
				memcpy(A, ReversedCase, Nwords * sizeof (char *) ); break;
			case 3:
				memcpy(A, MaxHeap, Nwords * sizeof (char *) ); break;
			case 4:
				memcpy(A, MinHeap, Nwords * sizeof (char *) ); break;
			default:
				return 0;
		}

		switch(flag){
			case 1:
				InsertionSort(A,Nwords); break;
			case 2:
				SelectionSort(A,Nwords); break;
			case 3:
				BubbleSort(A,Nwords);	break;
			case 4:
				HeapSort(A,Nwords); break;
			default:
				return 0;
		}

        if(i==0){
            for(j = 0; j < Nwords ; j++)
                printf("%d %s\n",j+1,A[j]);
        }
    }
    t2 = GetTime();
	switch(flag){
		case 1: 
			printf("insertion sort:\n");break;
		case 2:
			printf("selection sort:\n");break;
		case 3: 
			printf("bubble sort:\n");break;
		default:
			printf("heap sort:\n");break;
	}
    printf("N=%d\nCPU time = %.3g seconds\n", Nwords, (t2-t1)/500.0);


	free(words);	//avoid memory leakage
	return 0;
}
