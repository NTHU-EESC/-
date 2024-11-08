#include<stdio.h>
int x, a, b;
int z[5];
int main(void)
{
    int y[5] = {0,1,2,3,4};
    scanf("%d\n",&x);
    while(x>0){
        scanf("%d%d",&a,&b);
        z[a] = y[b];
        z[b] = y[a];
        y[a] = z[a];
        y[b] = z[b];
        x--;
    }
    printf("%d %d %d %d %d",y[0],y[1],y[2],y[3],y[4]);
    return 0;
}
