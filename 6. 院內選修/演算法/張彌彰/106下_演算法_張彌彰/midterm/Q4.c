// Q4 104061212 馮立俞
// Minimum communication groups
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int time;
int f[108];
int count = 0;

typedef struct node{			//graph node
	char *name; 
	int index;
	int edges;
	bool visited;
	struct node *next, *end;
}Node;

int insertNode(Node **list, int N, char *winner, char *loser);	//record match
void DFS_d(Node **list, int N, int index);
void BubbleSort(Node **list, int N);

int insertNode(Node **list, int N, char *winner, char *loser){
	Node *temp, *temp2;
	int i;		//looping index
	int j, k;	//to find winner,loser
	int m, n;	//record winnner/loser location

	i = 0;
	j = 1; 
	k = 1;
	m = -1;
	n = -1;
	for(i = 0, j = 1; i < N && j != 0; i++){	//find winner location
		j = strcmp(list[i]->name, winner);
	}
	m = i-1;
	for(i = 0, k = 1; i < N && k!=0; i++){		//find loser
		k = strcmp(list[i]->name, loser);
	}
	n = i-1;

	temp = list[m]->end;
	
	temp2 = malloc(sizeof(Node));
	temp2->name = malloc(  strlen(loser) + 1 );
	temp2->name = loser;
	temp2->visited = false;				//
	temp2->index = n;					//
	temp2->next = NULL;					//add node to linked list
	temp->next = temp2;
	list[m]->end = temp2;
	return 0;
}

void DFS_d(Node **list, int N, int index){
	Node *temp = list[index];

	temp->visited = true;
	
	time++;
	for(;temp != NULL; temp = temp->next)
		if(list[temp->index]->visited == false) 
			DFS_d(list,N,temp->index);
	
	time++;
	f[index] = time;
	printf("%d %s \n",count++, list[index]->name);
}

void BubbleSort(Node **list, int N){
	Node *temp;
	int intemp;
	int i,j;

	for (i = 0; i < N-1; i++){
        for(j = N-1; j > i; j--){
            if( f[j] > f[j-1] ){
               temp = list[j];				// swapping
               intemp = f[j];
               list[j] = list[j-1];			//
               f[j] = f[j-1];
               list[j-1] = temp;			//
               f[j-1] = intemp;
            }
        }
    }
}

int main(){

	int Nplayers,Ntour;		//108,63
	Node **NameList, **NameList_t, *iter;
	int i,j,k;
	char *temp1, *temp2;	//input buffer
	char **rank;			//final ranking

	temp1 = malloc(sizeof(char *));
	temp2 = malloc(sizeof(char *));

	scanf("%d", &Nplayers);
	printf("%d\n",Nplayers );
	

	NameList = (Node **)malloc(Nplayers * sizeof(Node *));
	for (i = 0; i < Nplayers; ++i){
		NameList[i] = (Node *)malloc(sizeof(Node));
		NameList[i]->name = malloc(sizeof(char *));
	}

	NameList_t = (Node **)malloc(Nplayers * sizeof(Node *));
	for (i = 0; i < Nplayers; ++i){
		NameList_t[i] = (Node *)malloc(sizeof(Node));
		NameList_t[i]->name = malloc(sizeof(char *));
	}

	for (i = 0; i < Nplayers; ++i)
		f[i] = 0;
	time = 0;

	printf("OK\n");
	for (i = 0; i < Nplayers; ++i)
	{
		scanf("%s", NameList[i]->name);			//read martial artists' name
		NameList[i]->end = NameList[i];
		NameList[i]->next = NULL;
		NameList[i]->visited = false;						//input players &
		NameList[i]->index = i;								//init NameList
		NameList[i]->edges = 0;

		NameList_t[i]->name =  NameList[i]->name;
		NameList_t[i]->end = NameList_t[i];
		NameList_t[i]->next = NULL;
		NameList_t[i]->visited = false;				
		NameList_t[i]->index = i;
		NameList_t[i]->edges = 0;
		//printf("%d %s\n",i, NameList[i]->name );

	}


	scanf("%d", &Ntour);
	printf("%d\n",Ntour);
	for (i = 0; i < Ntour; ++i){
		scanf("%s %s %s",temp1, temp2, temp2 );
		//printf("%d %s %s\n",i, temp1, temp2 );
		insertNode(NameList, Nplayers, temp1, temp2);
		insertNode(NameList_t, Nplayers, temp2, temp1);
	}

	
	for(i = 0,j = 1; i < Nplayers; i++){	                     
		if( NameList[i]->visited ==false ){
			printf("Group%d\n",j++ );
			DFS_d(NameList,Nplayers,i);
		}
	}

	//for (iter = NameList_t[21], printf("%s\n",iter->name ); iter != NULL; iter = iter->next )
	//	printf("%d\n", iter->index);

	BubbleSort(NameList_t,Nplayers);

	//for (iter = NameList_t[0], printf("%s\n",iter->name ); iter != NULL; iter = iter->next )
	//	printf("%d\n", iter->index);

	/*for(i = 0; i< Nplayers; i++){
		if(NameList_t[i]->visited == false)
			printf("Normal ");
		printf("%d f %d  %s\n",i,f[i], NameList_t[i]->name );
	}*/

	time = 0;
	count = 0;
	printf("\n\n\n\n\n\n\n\nComm Groups:\n");
	for(i = 0,j = 1; i < Nplayers; i++){	
		//printf("i = %d\n",i );                     
		if( NameList_t[i]->visited ==false ){
			printf("Group%d\n",j++ );
			DFS_d(NameList_t,Nplayers,i);
		}
	}
	printf("%d group(s) in total\n",--j );
}
