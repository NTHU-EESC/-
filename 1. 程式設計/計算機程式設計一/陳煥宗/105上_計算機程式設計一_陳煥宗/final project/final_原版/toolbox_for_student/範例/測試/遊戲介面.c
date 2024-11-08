#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define speedd 1
int speed(double x);
void sleep(clock_t wait );
void main()
{
    int a;
    int symbol[10000];
    double state;
    int i, j, k;
    clock_t start,finish;
    /*char ch[4] = {'a','z','A','Z'};
    int c[4] = {0};
    for(i=0;i<4;i++){
        c[i] = ch[i];
        printf("%d\n",ch[i]);
    }*/
    srand(time(NULL));
    a=(rand()%100)+1;
    //symbol[100]=rand()%26+97;
    for(i=0;i<100;i++){
        if(i<10) state = 1;
        else if(10<=i&&i<20) state = 2;
        else if(20<=i&&i<30) state = 3;
        else if(30<=i&&i<40) state = 4;
        else if(40<=i&&i<50) state = 5;
        else state = 6;
        sleep(speed(state));
        symbol[i]=rand()%26+97;
        printf("%c\n",symbol[i]);
    }
    printf("The Random Number is %d .\n", a);
    printf("%c",symbol);
}
void sleep( clock_t wait )
{
   clock_t goal;
   goal = wait + clock();
   while( goal > clock() );
}
int speed(double x)
{
    return 1000-(200*(x-1));
}
