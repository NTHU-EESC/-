#include<stdio.h>
int main(void)
{
    int i, j, k,tmp;
    int cases, num[1000];
    int test[30][10005];

    scanf("%d",&cases);
    for(i=1;i<=cases;i++){
        scanf("%d",&num[i]);
        for(j=1;j<=num[i];j++){
            scanf("%d",&test[i][j]);
        }
    }
    /*for(i=1;i<=cases;i++){
        for(j=1;j<=num[i];j++){
            printf("%d ",test[i][j]);
        }
        printf("\n");
    }*/
    for(i=1;i<=cases;i++){
        for(j=1;j<=num[i];j++){
            for(k=j+1;k<=num[i];k++){
                if(test[i][j]>test[i][k]){
                    tmp = test[i][k];
                    test[i][k] = test[i][j];
                    test[i][j] = tmp;

                }
            }
        }
    }
    for(i=1;i<=cases;i++){
        printf("%d",test[i][1]);
        for(j=2;j<=num[i];j++){
            printf(" %d",test[i][j]);
        }
        printf("\n");
    }

    return 0;
}
