#include<stdio.h>
#include<string.h>
int main(void){
    char word[40];
    int word_len;
    int i,j,k;

    /*for(i=0;word[i]!='\0';i++){
        scanf("%c",&word[i]);
    }*/
    scanf("%s", &word);

    word_len = strlen(word);
    k = word_len;
    for(j=0;j<word_len;j++){
        for(i=0;i<k-1;i++){
            printf(" ");
        }
        for(i=0;i<j+1;i++){
            printf("%c",word[i]);
        }
        k--;
        printf("\n");
    }
    return 0;
}
