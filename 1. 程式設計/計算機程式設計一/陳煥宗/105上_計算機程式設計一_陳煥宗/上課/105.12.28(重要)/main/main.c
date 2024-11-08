#include<stdio.h>
#include<stdlib.h>

extern int get_var(void);
extern int val;

int main(void)
{
    int var;
    printf("in main: %d\n", var);
    printf("in get_var() :%d\n", get_var());
    printf("in get_var() :%d\n", get_var());
    printf("in get_var() :%d\n", get_var());
    return 0;
}
