/*************************************
  EE3980 Algorithms HW05 Linear Sort
  Li-Yu Feng 104061212
  Date:2018/4/15
**************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include<stdbool.h>
#define LEN 14
char **A;


double GetTime(void);
void RadixSort(char **list,int n);
void CountingSort(char **list,int n, int loc);
void Heapify(char **list, int i, int n);
void HeapSort(char **list,int n);
double GetTime(void)
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec+1e-6*tv.tv_usec;
}


void CountingSort(char **list, int n, int loc){ 
    int count[27];              //n:size loc:sorting radix location
    int i,index;
    char *temp;

    
    for (i = 0; i < 27; ++i)    //init count array
    {
        count[i] = 0;
    }


    for (i = 0; i < n; i++){                //count alphabet occuring times
        if(list[i][loc] == '\0')
            count[0]++;
        else count[ list[i][loc] - 96 ]++;
    }


    for(i = 1; i< 27; i++){         // calculate each alphabet's 
        count[i] += count[i-1];     // dictionary order
    }


    for(i = n-1; i >= 0; i-- ){
        temp = list[i];
        if (temp[loc] == '\0')   index = 0;     //deal with '\0' (ASCII 0)
        else index = temp[loc] - 96;            //lower case alphabet
        A[ count[ index ]- 1] = temp;           //put word in new array
        count[ index ]--;                       //update count array
    }

    for ( i = 0; i < n; ++i)                    //output current result
    {  
        list[i] = A[i];
    }
    
}



void RadixSort(char **list,int n){
    int i;

    for (i = LEN-1; i >= 0; --i){
        CountingSort(list, n, i);
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
        //printf("%d\n",j);
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

int main(){
    int i,j;
    int Nwords;
    double t;
    char **words,**temp;

	scanf("%d", &Nwords);
    A = (char **)malloc( Nwords * sizeof(char*) );
    temp = (char **)malloc( Nwords * sizeof(char*) );
    words = (char**)malloc(Nwords * sizeof(char*));		    //
    for(i = 0; i < Nwords; i++)							    //
        words[i] = (char *)malloc( (LEN+1) * sizeof(char));	//


	for(i = 0; i < Nwords ; i++){						    //
		scanf("%s", words[i]);							    //scan words
	}
    t = GetTime();

    for(i =0; i<500;i++){                                   //sort 500 times
        for (j = 0; j < Nwords; ++j)
        {
            temp[j] = words[j];
        }
        RadixSort(temp, Nwords);
    }


    for(i = 0; i < Nwords ; i++){                       //print result
        printf("%d %s\n",i, temp[i]);                          
    }

    t = GetTime() - t;
    printf("%s:\nN=%d\nCPU time = %.3g seconds\n", "Linear Sort",
                        Nwords, t / 500.0);

    t = GetTime();

    for(i =0; i<500;i++){                                   //sort 500 times
        for (j = 0; j < Nwords; ++j)
        {
            temp[j] = words[j];
        }
        HeapSort(temp, Nwords);
    }


    for(i = 0; i < Nwords ; i++){                       //print result
        printf("%d %s\n",i, temp[i]);                          
    }

    t = GetTime() - t;
    printf("%s:\nN=%d\nCPU time = %.3g seconds\n", "Heap Sort",
                        Nwords, t / 500.0);


    return 0;

}
