#include <stdio.h>
int path[102][102]={0};
char map[102][102]={0};
void move(int,int,int);
int main(void){
	int row,col,i,j,sr,sc,tr,tc;

	scanf("%d %d",&row,&col);
	getchar();
	for(i=1;i<=row;i++){
		for(j=1;j<=col;j++){
			scanf("%c",&map[i][j]);
			if(map[i][j]=='S'){
				sr=i;
				sc=j;
			}else if(map[i][j]=='T'){
				tr=i;
				tc=j;
			}
		}
		getchar();
	}
	move(sr,sc,0);
	printf("%d\n",path[tr][tc]);
	return 0;
}

void move(int row , int col , int steps){
	if(steps){
		if(map[row][col]=='*')
			return;
		if(map[row][col]==0)
			return;
		if((path[row][col])&&(path[row][col]<=steps))
			return;
	}
	path[row][col]=steps;
	move(row+1 ,col ,steps+1);
	move(row-1 ,col ,steps+1);
	move(row ,col+1 ,steps+1);
	move(row ,col-1 ,steps+1);
}
