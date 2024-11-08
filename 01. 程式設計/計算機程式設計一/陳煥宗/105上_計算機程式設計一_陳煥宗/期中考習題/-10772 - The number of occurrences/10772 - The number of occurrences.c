#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(void)
{
    int number_of_strings, count, max_of_occurences;
    int i, j, k, x, y;
    char ch, rc;
    char word[20], cases[20];
    i = 0;
    j = 0;
    x = 0;
    max_of_occurences = 0;
    while((ch = getchar())!='\n'){
        word[i] = ch;
        i++;
    }
    getchar();
    word[i]='\0';  //把打的'\n'空行去掉
    //printf("%s", word);
    scanf("%d",&number_of_strings);
    for(i=0;i<number_of_strings;i++){
        while((rc = getchar())!='\n'){
            cases[j] = rc;
            j++;
        }
        getchar();
        cases[j]='\0';
        //printf("%d\n",strlen(cases));
        count=0;
        for(j=0;j<strlen(cases);j++){
            for(k=j;k<strlen(cases);k++){
                if(cases[k] == word[x]){
                    x++;
                    y++;
                }
                else{
                    x = 0;
                    y = 0;
                }
                if(y == strlen(word)){
                count++;
                }
            }
        }
        if(count > max_of_occurences){
            max_of_occurences = count;
        }
        //printf("%d\n", max_of_occurences);
        j = 0;
    }
    printf("%d",max_of_occurences);
    return 0;
}
