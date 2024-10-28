/*************************************
  EE3980 Algorithms HW07 Huffman Code
  Li-Yu Feng 104061212
  Date:2018/4/23
**************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <stdbool.h>
#include <math.h>

#define LEN 14

typedef struct node{                //node in MinHeap & Tree
    struct node *lchild,*rchild;
    char c, *HMcode;
    int freq;
}Node;


double GetTime(void);
void Heapify(Node *list, int i, int n);     // build a heap for nlgn speed- 
void MinHeap(Node *list,int n);             // finding minimal member
Node *HeapPop(Node *list, int n);           //return minimum
void HeapInsert(Node *list, int n, Node *new);  //insert new member to MinHeap
Node *Tree(Node *list, int n);      //build minimum cost tree
int Encode(Node *node, char *str);  // Huffman encoder, print using recursion

double GetTime(void)
{
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return tv.tv_sec+1e-6*tv.tv_usec;
}

void Heapify(Node *list, int i, int n){
    int j = i*2;
    Node temp = list[i-1];
    bool done = false;

    while(j<=n && !done){
        if(j<n && list[j-1].freq > list[ j+1 -1].freq ) j++;           //list[j-1].freq > list[ j+1 -1].freq
        if(temp.freq < list[j-1].freq ) done = true;
        else{
            list[j/2-1] = list[j-1];
            j *= 2;
        }
        //printf("%d\n",j);
    }
    list[j/2-1] = temp;
}

void MinHeap(Node *list,int n){
    int i;

    for( i = n/2 ; i>0 ; i--)
        {Heapify(list,i,n);}
}

Node *HeapPop(Node *list, int n){
    Node *min;
    
    min = malloc(sizeof(Node));
    *min = list[0];
    list[0] = list[n-1];
    Heapify(list,1, n-1);   //maintain MinHeap

    return min;
}

void HeapInsert(Node *list, int n, Node *new){      //n = current member count
    int j = n+1;

    while( j > 1 && new->freq < list[ j/2 -1].freq ){                 //new->freq < list[ j/2 -1].freq
        list[j-1] = list[j/2 -1];
        j /= 2 ;
    }
    list[j-1] = *new;

}

Node *Tree(Node *list, int n){
    Node *pt,*temp;
    int i;

    for( i = n; i > 1; ){

        pt = malloc(sizeof(Node));
        pt->c = '.';

        for(temp = HeapPop(list, i--);                      //ignore node with 
             temp->freq ==0; temp = HeapPop(list, i--) );   //zero freq
        pt->lchild = temp;
        pt->rchild = HeapPop(list, i--);

        pt->freq = pt->lchild->freq + pt->rchild->freq;

        HeapInsert(list, i++, pt);
        //printf("Take %c(%d) %c(%d)\n",pt->lchild->c,pt->lchild->freq,pt->rchild->c,pt->rchild->freq );
        //printf("I am %d\n",pt->freq );
    }
    return HeapPop(list,1);
}

int Encode(Node *node, char *str){
    char *temp;
    int bitCount = 0;

    node->HMcode = malloc( sizeof(str) );
    temp = malloc( sizeof(str) +1 );
    node->HMcode = str;
    if(node->c != '.' && node->freq != 0){      //print leaf nodes
        if(node->c == '\0') printf("  \\n:  %s\n",node->HMcode );
        else    printf("  %c:  %s\n",node->c, node->HMcode );
        bitCount = strlen(node->HMcode) * node->freq;
    }
    
    strcpy(temp,str);
    
    if (node->lchild != NULL){
        temp[strlen(temp)] = '0';
        bitCount += Encode(node->lchild, temp);
    }
    
    if (node->rchild != NULL){
        temp[strlen(temp)-1] = '1';
        bitCount += Encode(node->rchild, temp);
    }
    return bitCount;
}

void InsertionSort(Node *list,int n){
    int i,j;
    Node temp;

    for(j = 1; j < n; j++){
        temp = list[j];
        i = j-1;
        while((i>=0) && temp.freq > list[i].freq ){
            list[i+1] = list[i];
            i--;
        }
        list[i+1] = temp;
    }
}




int main(){
    int i,j,k;
    int Nwords,Nchar;
    double t;
    char **words;
    Node *list,*temp;
    bool done;

    int count;

	scanf("%d", &Nwords);


    words = (char**)malloc(Nwords * sizeof(char*));		    //
    for(i = 0; i < Nwords; i++)							    //
        words[i] = (char *)malloc( (LEN+1) * sizeof(char));	//


	for(i = 0; i < Nwords ; i++){						    //
		scanf("%s", words[i]);							    //scan words
	}

    list = (Node *)malloc( 27 * sizeof(Node));
    list[0].c = '\0';
    list[0].freq = 0;
	list[0].lchild = NULL;
	list[0].rchild = NULL;

    for (i = 1; i < 27; i++){       //init list
        list[i].c = 'a'-1 +i;
        list[i].freq = 0;
		list[i].lchild = NULL;
		list[i].rchild = NULL;
    }

    Nchar = 0;
    list[0].freq = Nwords;
    for (i = 0; i < Nwords ; i++){              //count char freq
        for(j = 0; words[i][j] != '\0'; j++)
            list[ words[i][j]-'a'+1 ].freq++;
        Nchar += j+1;
    }

    printf("Number of words: %d\nNumber of characters: %d\n",Nwords,Nchar );
    
    /*InsertionSort(list,27);
    for ( i = 0,j = 1, k = 2, count = 0; i < 27; ++i)
    {
        if(i+1 <= k)   count += list[i].freq * j;
        else{
            j++; k *= 2;

            count += list[i].freq * j;
        }
    }
    printf("dummy encoding bit count:%d\n",count );*/


    printf("Huffman coding\n");

    MinHeap(list,27);

    temp = Tree(list,27);
    i = Encode(temp,"");
    printf("Number of encoded bits: %d\n", i );
    printf("Ratio: %.4f %% \n", i / (Nchar*8.0)*100.0 );
    return 0;

}
