#include <stdio.h>
#include <ctype.h>
int main (void){
    char ch,pre_ch;
    int big,length;
    big = 0;
    length = 0;
    pre_ch = 0;
    while((ch=getchar())!='\n'){
        ch = toupper(ch);
        length++;
        if(ch!=pre_ch)length=1;
        if(length>=big)big=length;
        pre_ch = ch;
    }
    printf("%d\n",big);
    return 0;
}

