#include<stdio.h>
#include<ctype.h>
int main(void)
{
    int biggest, length;
    char ch, previous, currence;
    biggest = 1;
    currence = '0';
    length = 1;
    while((ch=getchar())!='\n'){
        previous = currence;
        currence = toupper(ch);
        if(currence == previous){
            length++;
        }
        else{
            length = 1;
        }
        if(length > biggest){
            biggest = length;
        }
        else{
            continue;
        }
    }
    printf("%d\n",biggest);
    return 0;
}
