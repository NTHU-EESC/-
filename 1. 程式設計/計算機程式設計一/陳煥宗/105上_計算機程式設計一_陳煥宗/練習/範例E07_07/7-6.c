#include<stdio.h>
#include<ctype.h>
#define STOP 'I'
int main(void)
{
    char c;
    char prev;
    long n_chars = 0L;
    int n_lines = 0;
    int n_words = 0;
    int p_lines = 0;
    int inword = 0;//**

    printf("Enter text to be analyzed (I to terminate): \n");
    prev = '\n';
    while((c=getchar())!=STOP){
        n_chars++;
        if(c=='\n') n_lines++;
        if(!isspace(c) && !inword){
            inword = 1;
            n_words++;
        }
        if(isspace(c) && inword) inword = 0;
        prev = c;
    }
    if(prev != '\n') p_lines = 1;

    printf("character = %d, words = %d, lines = %d, ", n_chars, n_words, n_lines);
    printf("partial lines = %d\n");

    return 0;
}
