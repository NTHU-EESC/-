#include<stdio.h>
int main(void)
{

    char ch;
    int L,T,i,j,k;

    scanf("%c %d %d", &ch, &L, &T);
    if(L==1){
        for(i=0;i<T-1;i++){
            printf("%c\n",ch);
        }
        printf("%c",ch);
    }
    else{
    for(k=1;k<=T;k++){
        for(i=1;i<=L;i++){
            for(j=1;j<=i;j++){
                printf("%c",ch);
            }
            printf("\n");
        }

        for( i=L-1;i>1;i--){
         for(j=i;j>=1;j--){
            printf("%c",ch);
         }
         printf("\n");
        }

    }
    printf("%c", ch);
    }
    return 0;
}
