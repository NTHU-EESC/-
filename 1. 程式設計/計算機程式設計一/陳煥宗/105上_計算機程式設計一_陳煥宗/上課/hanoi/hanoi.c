#include<stdio.h>
void hanoi(int n, int start, int end,int buf);
int main(void)
{
    int N,start,end,buf;
    printf("please enter the layer of the hanoi:");
    scanf("%d",&N);
    printf("please enter the start place of the hanoi:");
    scanf("%d",&start);
    printf("please enter the end place of the hanoi:");
    scanf("%d",&end);
    printf("please enter the buf place of the hanoi:");
    scanf("%d",&buf);
    hanoi(N,start,end,buf);
    return 0;
}
void hanoi(int n, int start, int end,int buf)
{
    if(n==0) return;
    hanoi(n-1,start,buf,end);
    printf("%d->%d\n",start,end);
    hanoi(n-1,buf,end,start);
}
