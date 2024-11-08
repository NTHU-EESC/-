#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(void)
{
    int i, j, k;
    int length, max, max_aplpha, initial;
    int count[26]={0};
    char str[1000]={'0'};
    char ch;
    i = 0;
    while((ch=getchar())!=EOF){
        str[i] = ch;
        i++;
    }
    length = i;
    for(i=0;i<length;i++){
        if(isupper(str[i])) count[str[i]-'A']++;
        else if(islower(str[i])) count[str[i]-'a']++;
    }
    max = 0;
    for(i=0;i<26;i++){
        if(count[i]>max){
            max = count[i];
            max_aplpha = i;
        }
    }//i+'A' -> 'E' => (i+'A')+'E'-'i+'A''
    initial = i+'A';
    for(i=0;i<length;i++){
        if(isupper(str[i])){
            str[i] = str[i]+'E'-initial;
            if('A'-str[i]) str[i] = 'Z'
        }
        else if(islower(str[i])) count[str[i]-'a']++;
    }
    return 0;
}
