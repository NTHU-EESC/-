#include<stdio.h>
#include<string.h>
void reverse(char*s, char*e)
{
    char tmp;
    while(s<e){
        tmp = *s;
        *s = *e;
        *e = tmp;
        s++;
        e--;
    }
}

int main(void)
{
    char str[100];
    int i;

    scanf("%99s", str);

    while(scanf("%d", &i)!=EOF){
        reverse(str, str+i-1);
        reverse(str+i, str+strlen(str)-1);
        reverse(str, str+strlen(str)-1);
    }
    return 0;
}
