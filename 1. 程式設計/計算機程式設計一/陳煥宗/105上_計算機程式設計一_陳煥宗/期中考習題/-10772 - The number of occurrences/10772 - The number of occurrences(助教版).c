#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(void)
{
    int numA, numB[10];
    int n;
    int i, j, k;
    int isSame;
    int count, max;
    char a[10],b[10][10];
    char ch;

    numA = 0;

    while((ch = getchar())!='\n'){
        a[numA++] = ch;
    }
    //getchar();
    scanf("%d",&n);
    getchar();
    max = 0;
    for(i=0;i<n;i++){
        numB[i] = 0;
        while((ch = getchar())!='\n'){
            b[i][numB[i]++] = ch;
        }
    }
    isSame=0;
    for(i=0;i<n;i++){
        count = 0;
        for(j=0;j<(numB[i]-numA+1);j++){
            isSame = 1;
            for(k=0;k<numA;k++){
                if(a[k]!=b[i][j+k]){
                    isSame = 0;
                    break;
                }
            }
            if(isSame==1){
                count++;
            }
        }
        if(count>=max){
            max = count;
        }
    }
    printf("%d",max);
    return 0;
}
