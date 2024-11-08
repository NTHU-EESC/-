#include<stdio.h>

void showbit(int x, int n)  //�P�_x�bn��m�ɬO0�٬O1
{
    int m = 1 << (n-1);
    while(m>0){
        printf("%d",(x&m)!=0); //(x&m)!=0���P�_�� //**ex.(0110010&0000010 = 0000010(2))!=0 is true -->print"1";
                                                  //**ex.(0110010&0000100 = 0000000(0))!=0 is wrong -->print"0"
        m = m >> 1;
    }
    printf("\n");
}

int main(void)
{
    int x,n;
    showbit(5,4);
    /*scanf("%d%d",&x,&n);
    showbit(x,n);
    showbit(~x,n);*/

    int y,z;
    y = 25;
    showbit(y,6);
    z = 13;
    showbit(z,6);
    printf("y=%d z=%d\n",y,z);

    y = y^z;
    //showbit(y,6);
    printf("XOR mask: ");
    showbit(y,6);

    z = y^z;
    showbit(z,6);
    printf("New z: %d\n", z);

    y = y^z;
    showbit(y,6);
    printf("New y: %d\n",y); //�H�W�i�H���Ψ�ĤT���ܼƴN����swap���ĪG

    printf("%d\n",1<<3); //1000 = 8;
    printf("%d\n",32>>2); //100000(32)>>2 -> 1000(8)

    return 0;
}
