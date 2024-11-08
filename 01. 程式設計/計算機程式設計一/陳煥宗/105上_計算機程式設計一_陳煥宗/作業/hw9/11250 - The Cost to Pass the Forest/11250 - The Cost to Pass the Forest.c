#include<stdio.h>

int min;

void route(char map[105][105],int walk[105][105],int row,int col,int path);

int main(void)
{
    min=10000;
    char map[105][105] = {0};
    int walk[105][105] = {0};
    //int sum=0, max=0, path=0;
    int row, col;
    int now_r, now_c;
    int i, j, k;

    scanf("%d %d", &row, &col);
    for(i=0;i<=row+1;i++){
        for(j=0;j<=col+1;j++){
            map[i][j] = 'b';
        }
    }
    char ch;
    scanf("%c",&ch);
    for(i=1;i<=row;i++){
        for(j=1;j<=col;j++){
            scanf("%c",&map[i][j]);
            if(map[i][j]=='S'){
                walk[i][j]=1;
                now_r = i;
                now_c = j;
            }
        }
        scanf("%c",&ch);
    }

    /*for(i=1;i<=row;i++){
        for(j=1;j<=col;j++){
            printf("%c",map[i][j]);
        }
        printf("\n");
        //printf("%c",&ch);
    }*/
    route(map,walk,now_r,now_c,1);
    if(min==10000) min = 0;
    printf("%d\n",min);
    return 0;
}

void route(char map[105][105],int walk[105][105],int i,int j,int path)
{
    //printf("%d\n",path);
    //printf("%d %d\n",i,j);
    //if((map[i][j]=='*')||(map[i][j]=='b')) return ;

    if((map[i+1][j]=='#')&&(walk[i+1][j]==0)){
        path++;
        walk[i+1][j] = path;
        route(map,walk,i+1,j,path);
        path--;
        walk[i+1][j] = 0;
    }
    if((map[i-1][j]=='#')&&(walk[i-1][j]==0)){
        path++;
        walk[i-1][j] = path;
        route(map,walk,i-1,j,path);
        path--;
        walk[i-1][j] = 0;
    }
    if((map[i][j+1]=='#')&&(walk[i][j+1]==0)){
        path++;
        walk[i][j+1] = path;
        route(map,walk,i,j+1,path);
        path--;
        walk[i][j+1] = 0;
    }
    if((map[i][j-1]=='#')&&(walk[i][j-1]==0)){
        path++;
        walk[i][j-1] = path;
        route(map,walk,i,j-1,path);
        path--;
        walk[i][j-1] = 0;
    }
    if(map[i+1][j]=='T'){
        //path++;
        //walk[i+1][j] = path;
        if(path<min) min = path;
        //else return ;
    }
    if(map[i-1][j]=='T'){
        //path++;
        //walk[i-1][j] = path;
        if(path<min) min = path;
        //return ;
    }
    if(map[i][j+1]=='T'){
        //path++;
        //walk[i][j+1] = path;
        if(path<min) min = path;
        //else return ;
    }
    if(map[i][j-1]=='T'){
        //path++;
        //walk[i][j-1] = path;
        if(path<min) min = path;
        //else return ;
    }
}
