#include<stdio.h>
#include<string.h>
int main(void)
{
    int i;
    char word[40];
    scanf("%s",word);
    for(i=1;i<=strlen(word);i++){
        printf("%*.*s\n",strlen(word),i,word);
    }
    return 0;
}
