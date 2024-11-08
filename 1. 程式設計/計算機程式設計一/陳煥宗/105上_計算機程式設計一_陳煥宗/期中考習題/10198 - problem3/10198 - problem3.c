#include<stdio.h>
int main(void){
    int x,a,b,r;
    int i,j,k;
    char f[100][100];
    scanf("%d",&x);
    scanf("%d %d",&a,&b);
    scanf("%d",&r);

    for(i=0;i<x;i++){
        for(k=0;k<x;k++){
            f[i][k] = '-';
            }
    }
    f[a-1][b-1] = 'S';
    a = a-1;
    b = b-1;
    for(i=1;i<r+1;i++){
        if(0<=(a-i)){
            f[a-i][b] = '+';
        }
        if((a+i)<x){
            f[a+i][b] = '+';
        }
        if(0<=(b-i)){
            f[a][b-i] = '+';
        }
        if((b+i)<x){
            f[a][b+i] = '+';
        }
    }
    for(i=0;i<x;i++){
        for(k=0;k<x;k++){
            printf("%c",f[i][k]);
            }
        printf("\n");
    }

    return 0;
}
