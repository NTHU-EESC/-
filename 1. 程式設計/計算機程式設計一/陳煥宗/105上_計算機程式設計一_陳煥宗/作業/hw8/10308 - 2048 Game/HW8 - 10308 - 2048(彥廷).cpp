#include <stdio.h>

#define WIDTH 4
#define HEIGHT 4

int map[HEIGHT][WIDTH];

void show(){
    int i,j,k;
    for(i=0;i<WIDTH;i++){
    	k=0;
    	for(j=0;j<HEIGHT;j++){
    		if(map[j][i]==0)
    			k++;
		}
		printf("%d ",k);
	}
	printf("\n");
	
}

void collapse(int to,int row,int col){
	int tmp;
    if(row<0)
    	return;
	
	if(!map[row][col])
    	collapse(to,row-1,col);
    else{
    tmp = map[to][col];
    map[to][col]=map[row][col];
    map[row][col]=tmp;
    collapse(to-1,row-1,col);
	}
    
    	
}

void slide(){
	int i,j;
	for(i=0;i<WIDTH;i++)
		collapse(3,3,i);
		
    for(i=0;i<WIDTH;i++){
    	for(j=HEIGHT-1;j>0;j--){
    		if(map[j][i]==map[j-1][i]){
    			map[j][i]*=2;
    			map[j-1][i]=0;
			}
		}
	}
	
	for(i=0;i<WIDTH;i++)
		collapse(3,3,i);
	
}





int main()
{
    int N, d;
    int i, j;

    scanf("%d", &N);
    for(i = 0; i < HEIGHT; i++){
        for(j = 0; j < WIDTH; j++){
            scanf("%d", &map[i][j]);
        }
    }

    for(i = 0; i < N; i++){
        slide();
    }

    show();

    return 0;
}
