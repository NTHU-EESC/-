#include<stdio.h>
int main(void)
{
    int i, j, k, z;
    int fraction;
    int len[26];
    char button[26];
    char necklace[26][26]={'0'};
    scanf("%d",&fraction);
    for(i=0;i<fraction;i++){
        scanf("%s%n",necklace[i],&len[i]);//%n是把前面的位元數輸入len[i]
        button[i] = necklace[i][len[i]-2];
    }
    printf("%s",necklace[0]);
    k = 0;
    for(i=1;i<fraction;i++){
        for(j=1;j<fraction;j++){
            if(necklace[j][0]==button[k]) break;
        }
        for(z=1;z<(len[j]-1);z++) printf("%c",necklace[j][z]);
        k = j;
    }
    printf("\n");
    return 0;
}
