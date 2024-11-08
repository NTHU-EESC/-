#include<stdio.h>
#include<string.h>
int main(void)
{
    int biggest, length;
    int i, j, k;
    char previous, currence;
    char ch[100];
    scanf("%s",ch);
    currence = '0';
    biggest = 1;
    for(i=0;i<strlen(ch);i++){
        previous = currence;
        currence = ch[i] % 32;
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
