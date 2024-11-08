#include <stdio.h>
#include <string.h>
//#include "function.h"
int isPalindrome(char *start, char *end);
int main(void)
{
    char str[5000];
    while(EOF!=scanf("%s", str))
    {
        char *start = str; //start是存取str第1個字元
        char *end = start + strlen(str) - 1; //end是存取str最後一個字元
        //printf("%c ,%c \n",*start,*end);
        if (isPalindrome(start, end)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}
int isPalindrome(char *start, char *end)
{
    int i,j,k;
    /*for(i=0;i<(end-start)/2;i++){
        if(start[i]!=end[i]) return 0;
    }
    return 1;*/
    if(*start==*end){
        //printf("%c ,%c \n",*start,*end);
        if(start>=end) return 1;
        isPalindrome(start+1,end-1);
    }
    else return 0;
}
