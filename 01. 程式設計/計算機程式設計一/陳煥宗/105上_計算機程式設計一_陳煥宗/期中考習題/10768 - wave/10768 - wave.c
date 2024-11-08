#include<stdio.h>
int main(void)
{
    char ch;
    int x,y,z;
    int i,j,k;
    scanf("%c %d %d",&ch,&x,&y);
    if(x!=1){
    for(i=0;i<y;i++){
            for(k=1;k<=x;k++){
                for(j=0;j<k;j++){
                    printf("%c",ch);
                }
                printf("\n");
            }
            for(k=x;k>2;k--){
                    for(j=k;j>1;j--){
                        printf("%c",ch);
                    }
                    printf("\n");
            }
    }
    printf("%c",ch);
    }
    if(x==1){
        for(i=0;i<y-1;i++){
            printf("%c\n",ch);
        }
        printf("%c",ch);
    }
    return 0;
}
