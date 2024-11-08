#include<stdio.h>
int main(void)
{
    int b[12] = {1,2,3,4,5,6,0,0,9,10,11,12};
    int* a[3];
    int i, j;
    a[0] = &b[0]; // b[0] => *(b+0) =>b
    a[1] = &b[4]; // b+4
    a[2] = &b[8]; // b+8
    //for(i=0;i<3;i++) a[i] = &b[i*4]; // a[2] = &b[8] = (b+8)
    printf("%d\n",a[2][1]); //*****

    //a[2][1] => *(a[2]+1) => *(b+8 + 1) => *(b+9) => b[9]

    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            printf("%3d",b[i*4 + j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
