#include<stdio.h>
//1073741824 = 2^30
void showbit(int x, int n)  //判斷x在n位置時是0還是1
{
    if(n>30) n = 30;
    int m = 1 << (n-1);
    while(m>0){
        printf("%d ",(x&m)!=0); //(x&m)!=0為判斷式 //**ex.(0110010&0000010 = 0000010(2))!=0 is true -->print"1";                                                  //**ex.(0110010&0000100 = 0000000(0))!=0 is wrong -->print"0"
        m = m >> 1;
    }
}

int main(void)
{
    int x, n, c1, c2, c3;
    scanf("%d %d",&x,&n);
    c2 = 0;
    c3 = 0;
    c1 = x/1073741824;
    x = x%1073741824;
    if((n-90)>0) showbit(~c3, n-90);
    if((n-60)>0) showbit(~c2, n-60);
    if(x==0) showbit(~c1+1, n-30);
    else showbit(~c1, n-30);
    showbit(~x+1,30);
    printf("\n");
    //showbit(~x+1,n);
    //showbit(4,2);
    return 0;
}
