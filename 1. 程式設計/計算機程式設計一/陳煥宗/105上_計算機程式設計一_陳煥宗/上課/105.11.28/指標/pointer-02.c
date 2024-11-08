#include<stdio.h>
int main(void)
{
    int x[5] = {100,200,300,400,500};
    double y[5] = {100,200,300,400,500};
    double* z;  // z是記憶體位置; *z是對應的值
    int i;
    printf("%p\n",&x);
    for(i=0;i<5;i++){
        printf("x[%d] at %p\n",i,&x[i]);//會發現每個位置差4
    }

    printf("%p\n",&y);
    for(i=0;i<5;i++){
        printf("y[%d] at %p\n",i,&y[i]);//會發現每個位置差8
    }
    for(i=0;i<5;i++){
        printf("y[%d]: %f\n",i,*(y+i));
    }
    printf("\n");
    //y[3] = 401 ~= *(0060FED0 + 8*3) = 401;等價的寫法

    z = y;
    for(i=0;i<5;i++){
        printf("y[%d]: %f %f %f\n",i,*(z+i),i[z],z[i]);//z+i是看第幾個
    }
    printf("\n");

    for(i=0;i<5;i++){
        printf("y[%d]: %f\n",i,*(z));
        z++; //0060FED0+8
    }

    return 0;
}
