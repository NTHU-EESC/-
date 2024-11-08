#include<stdio.h>
int main(void)
{
    int col, row, start;
    int count, count_repeat, count_Nrepeat;
    int i, j, k, l;
    int walk[100][100]={0};
    char map[100][100];
    char ch[1000];
    scanf("%d %d %d",&col,&row,&start);
    for(i=0;i<=col+1;i++){
        for(j=0;j<=row+1;j++){
            map[i][j] = 'a';
        }
    }
    for(i=1;i<=col;i++){
        scanf("%s", ch);
        for(j=1;j<=row;j++){
            map[i][j]=ch[j-1];
            //scanf("%c",&map[i][j]);
        }
    }
    /*for(i=0;i<=col+1;i++){
        for(j=0;j<=row+1;j++){
            printf("%c",map[i][j]);
        }
        printf("\n");
    }*/
    walk[1][start] = 1;
    for(i=1,j=start;walk[i][j]!=3;){
        if(map[i][j]=='N'){
            i--;
            if(map[i][j]!='a'){
                walk[i][j]++;
            }
        }
        else if(map[i][j]=='S'){
            i++;
            if(map[i][j]!='a'){
                walk[i][j]++;
            }
        }
        else if(map[i][j]=='W'){
            j--;
            if(map[i][j]!='a'){
                walk[i][j]++;
            }
        }
        else if(map[i][j]=='E'){
            j++;
            if(map[i][j]!='a'){
                walk[i][j]++;
            }
        }
        if(map[i][j]=='a'){
            break;
        }
    }
    if(map[i][j]=='a'){
        count = 0;
        for(k=1;k<=col;k++){
            for(l=1;l<=row;l++){
                if(walk[k][l]==1){
                    count++;
                }
            }
        }
        printf("%d",count);
    }
    if(walk[i][j]==3){
        count_Nrepeat = 0;
        count_repeat = 1;
        for(k=1;k<=col;k++){
            for(l=1;l<=row;l++){
                if(walk[k][l]==2){
                    count_repeat++;
                }
                else if(walk[k][l]==1){
                    count_Nrepeat++;
                }
            }
        }
        printf("%d %d",count_Nrepeat,count_repeat);
    }
    return 0;
}
