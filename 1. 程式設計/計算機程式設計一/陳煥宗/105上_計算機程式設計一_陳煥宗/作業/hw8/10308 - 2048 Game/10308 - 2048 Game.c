#include <stdio.h>

#define WIDTH 4
#define HEIGHT 4

int col[WIDTH+1];
int map[HEIGHT+1][WIDTH+1];

void collapse(int col){
    int i, j, k;
    for(k=0;k<HEIGHT-1;k++){
        for(i=HEIGHT;i>1;i--){
            if(map[i][col]==0){
                map[i][col] = map[i-1][col];
                map[i-1][col] = 0;
            }
        }
    }
}

void slide(int col){
    int i, j, k;
    if(col==5) return;
    collapse(col);
    for(i=HEIGHT;i>0;i--){
        if(map[i][col]==map[i-1][col]){
            map[i][col] *= 2;
            map[i-1][col] = 0;
        }
    }
    collapse(col);
    slide(col+1);
}

void show(){
    int i, j;
    for(i=1;i<=WIDTH;i++){
        for(j=1;j<=HEIGHT;j++){
            if(map[j][i]==0)col[i]++;
            /*if(map[j][i]!=0){
                printf("%d ",col[i]);
            }*/
        }
    }
    for(i=1;i<=WIDTH;i++) printf("%d ",col[i]);
    printf("\n");
}


int main()
{
    int N, d;
    int i, j;
    scanf("%d", &N);//N為下滑幾次//output為最後每行各有幾個0
    for(i=1; i<=HEIGHT; i++){
        for(j=1; j<=WIDTH; j++){
            scanf("%d", &map[i][j]);
        }
    }
    for(i=0; i<N; i++) slide(1);
    show();
    /*for(i = 1; i <= HEIGHT; i++){
        for(j = 1; j <= WIDTH; j++){
            printf("%5d", map[i][j]);
        }
        printf("\n");
    }*/
    return 0;
}
