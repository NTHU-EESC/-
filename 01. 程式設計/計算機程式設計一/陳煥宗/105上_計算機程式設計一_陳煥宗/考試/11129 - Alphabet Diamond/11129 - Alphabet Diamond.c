#include<stdio.h>
int main(void){
    int x, y, z, a, b, e, i, j;
    scanf("%d",&x);
    b = x;
    for(j=1;j<=x;j++){           //场
        for(i=0;i<b-1;i++){      //场フ
            printf(" ");
        }
        for(i=0;i<j;i++){        //场タよダ
            printf("%c",i+'A');
        }
        for(i=j-2;i>=0;i--){     //场はよダ
            printf("%c",i+'A');
        }
        b--;
        printf("\n");
    }
    for(j=x-1;j>0;j--){
        for(i=j;i<x;i++){
            printf(" ");
        }
        for(i=0;i<j;i++){
            printf("%c",i+'A');
        }
        for(i=j-2;i>=0;i--){
            printf("%c",i+'A');
        }
        printf("\n");
    }
    return 0;
}
