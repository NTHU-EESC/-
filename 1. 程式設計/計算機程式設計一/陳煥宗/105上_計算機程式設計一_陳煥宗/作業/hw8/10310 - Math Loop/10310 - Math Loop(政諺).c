#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ch[3][8] = {{'0'}};	
int a , b , c;
int lenth = 0;
int difference[100] ;	
int recording = 0;
int result = 0;

void find_BnC(void);
void diff(void);

int main()
{
	int i = 0;

	while( (ch[0][i] = getchar()) != EOF )
		i++;
	ch[0][i] = '\0';

	find_BnC();

	printf("%d\n", result);

	return 0;
}
void find_BnC(void){
	int i , j , temp = 0;

	lenth = strlen(ch[0]);
	for(i = 0 ; i < lenth ; i++)
		ch[1][i] = ch[0][i];

	for(i = 0 ; i < lenth-1 ; i++){
		for(j = 0 ; j < lenth-i-1 ; j++){
			if(ch[1][j+1] > ch[1][j]){
				temp = ch[1][j];
				ch[1][j] = ch[1][j+1];
				ch[1][j+1] = temp;
			}
		}
	}
	for(i = 0 ; i < lenth ; i++)
		ch[2][lenth-i-1] = ch[1][i];

	b = atoi(ch[1]);
	c = atoi(ch[2]);

	diff();
}
void diff(void){
	int i ;
	int temp = b-c;

	for(i = 0 ; i < recording; i++)
		if(temp == difference[i]){		
			result = recording+1;
			return ;
		}

	difference[recording++] = temp;

	// sprintf(輸出之字串，格式，變數1,變數2,…);
	sprintf(ch[0], "%d", temp);	//change from char to integer
	find_BnC();
}