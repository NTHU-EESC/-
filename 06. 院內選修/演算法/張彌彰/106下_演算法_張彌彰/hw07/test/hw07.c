/*Algorithms Homework 7
Huffman Code
2018-04-29
104060009 Liao, Yueh-Fan*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Node {
//store the word list
	int freq, c;
}node;

typedef struct TreeNode {	
//structure for the binary merge tree
	int freq, c;
	struct TreeNode *left, *right, *next;
}tnode;

tnode *new(int freq, int c) {
//new a node in binary merge tree
	tnode *A;
	A=(tnode *)malloc(sizeof(tnode));

	if(A==NULL)
		return NULL;
	A->freq=freq;
	A->c=c;
	A->left=NULL;
	A->right=NULL;
	A->next=NULL;
	return A;
};

tnode *next_push(tnode *list, int freq, int c) {
//insert a node at the end of the tree
	tnode *A=new(freq, c);
	if(list->next == NULL){
		list->next=A;
	}
	else {
		tnode *p=list;
		while(p->next != NULL) {p=p->next;}
		p->next=A;
	}
	return list;
}

tnode *Least(tnode *list) {
//find the character that has the smallest frequency in the list
//and delete the node in the list
	tnode *tmp=list->next;
	tnode *ans=list->next;
	tnode *pre=NULL;

	while(tmp->next != NULL) {
		if((tmp->next)->freq < ans->freq){
			ans=tmp->next;
			pre=tmp;
		}
		tmp=tmp->next;
	}
	if(ans != list->next){
		pre->next=ans->next;
		ans->next=NULL;
	}
	else{	//ans is the first node in the list
		list->next=ans->next;
		ans->next=NULL;
	}
	return ans;
}

tnode *Insert(tnode *list, tnode *pt) {
//insert the tree node pt into the list
	tnode *tmp=list;
	while(tmp->next != NULL) {	//find the last node
		tmp=tmp->next;
	}
	tmp->next=pt;
	return list;
}

tnode *BinaryMergeTree (tnode *list, int k) {
//build the binary merge tree which has k nodes
	int i;
	for(i=0; i<k-1; i++) {
		tnode *pt;
		pt=(tnode *)malloc(sizeof(tnode));
		pt->left=Least(list);
		pt->right=Least(list);
		pt->freq=(pt->left)->freq+(pt->right)->freq;
		pt->c=-1;
		pt->next=NULL;
		list=Insert(list, pt);
	}
	return Least(list);
}

void TreeTraversal(tnode *list, int Huffman[], int code, int len[], int *storage) {
//go through all the node in the binary merge tree
//and print out the Huffman code of each character
	int i, j, tmp;

	if(list == NULL)return;	//termination condition
	if(list->left==NULL && list->right==NULL) {	//leaf node
		int num=list->c+96;
		Huffman[num]=code;					//record the Huffman code
		len[num]=floor(log10(code)) + 1;	//record the length of the code
		*storage+=len[num]*(list->freq);	//calculate the total storage
		if(num >= 97)						//print out the character
			printf("%c : ", num);			//
		else								//
			printf("\\n: ");				//
		for(i=len[num]-1; i>0; i--){		//print out the Huffman code
			tmp=1;							//
			for(j=0; j<i; j++) {			//
				tmp*=10;					//
			}								//
			printf("%d", (code/tmp)%2);		//
			code=code-((code/tmp)%2)*tmp;	//
		}									//
		printf("%d", code%2);				//
		printf("\n");						//
	}
	TreeTraversal(list->left, Huffman, code*10+2, len, storage);
	TreeTraversal(list->right, Huffman, code*10+1, len, storage);
}

int main(void) {
	int i, j, k;				//variables declaration
	int n, num, storage;
	int Huffman[27], len[27];
	float num_ascii;
	char **list;				//2d char array
	node *head;					//linked list
	tnode *tree, *NumOfCharacter;
	char ch;

	head=(node *)malloc(27*sizeof(node));	//initialization
	tree=(tnode *)malloc(27*sizeof(tnode));	//
	for(i=0; i<27; i++) {	//initialization
		head[i].freq=0;
		head[i].c=i;
	}
	scanf("%d", &n);
	printf("Number of words: %d\n", n);
	list=malloc(n*sizeof(char*));			//initialization
	for(i=0; i<n; i++) {					//read the word list
		char tmp[30];
		scanf("%s", tmp);
		list[i]=malloc(strlen(tmp)*sizeof(char));
		strcpy(list[i],tmp);
	}
	for(i=0; i<n; i++) {		//calculate the freq. of the character
		for(j=0; j< strlen(list[i]); j++) {
			num=list[i][j]-96;
			if(num > 0){
				head[num].freq=head[num].freq+1;
				head[num].c=num;
			}
		}
		head[0].freq=head[0].freq+1;
		head[0].c=0;
	}
	k=0;
	for(i=0; i<27; i++) {	//build up the node list
		if(head[i].freq != 0){
			tree=next_push(tree, head[i].freq, head[i].c);
			k++;	//accumulate the number of the character which freq.>0
		}
	}
	storage=0;
	NumOfCharacter=BinaryMergeTree(tree, k);
	printf("Number of character: %d\n", NumOfCharacter->freq);
	printf("Huffman coding\n");
	TreeTraversal(NumOfCharacter, Huffman, 0, len, &storage);
	printf("Number of encoded bits: %d\n", storage);
	num_ascii=(8*NumOfCharacter->freq);
	printf("Ratio: %lf\n", storage/num_ascii);
	return 0;
}