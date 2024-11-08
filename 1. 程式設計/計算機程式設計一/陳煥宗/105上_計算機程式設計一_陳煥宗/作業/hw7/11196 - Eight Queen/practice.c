#include<stdio.h>
int q[10][10];
int tmp[10];
int ans;
int temp;

void place(int row);
int valid(int row,int col);
void search(void);

int main(void)
{
    int i, j, k;
    int N;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        for(j=0;j<8;j++){
            for(k=0;k<8;k++){
                scanf("%d",&q[j][k]);
            }
        }
        place(0);
        printf("%d\n",ans);
        ans = temp = 0;
    }
    return 0;
}

int valid(int row,int col)
{
    int i, j, k;
    for(i=0;i<=row-1;i++){
        if(tmp[i]==col||(col-tmp[i])==(row-i)||(row-i)==(tmp[i]-col)) return 0;
        //return 1;
    }
    return 1;
}

void place(int row)
{
    int i, j, k;
    if(row==8) search();
    else{
        for(i=0;i<8;i++){
            if(valid(row,i)){
                tmp[row] = i;
                place(row+1);
            }
        }
    }
}

void search(void)
{
    int i, j;
    temp = 0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(tmp[i]==j) temp += q[i][j];
        }
    }
    if(temp>ans) ans = temp;
}
