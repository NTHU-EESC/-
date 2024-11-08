#include<stdio.h>
int x,y,z;
int a[11],b[11];
int main(void)
{
   y = 1;
   scanf("%d%d%d%d%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9]);//a[k]!=a[i]
   b[0]=a[1];//a[1] = b[0] is wrong
   x = a[1];
   while(a[x]!=a[1]){
        b[y] = a[x];//¤£¦æa[x]=b[y]
        x = a[x];//a[x] = x is wrong
        y++;
   }
   y--;
   z = 0;
   while(y>=0){
        z = z + b[y];
        y--;
   }
   printf("%d",z);
}
