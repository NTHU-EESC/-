#include<stdio.h>
int main(void){
    int x, y, z, a, b, e, i, j;
    scanf("%d",&x);
    b = x;
    for(j=1;j<=x;j++){           //�W�b��
        for(i=0;i<b-1;i++){      //�W�b�����ť�
            printf(" ");
        }
        for(i=0;i<j;i++){        //�W�b��������V�r��
            printf("%c",i+'A');
        }
        for(i=j-2;i>=0;i--){     //�W�b�����Ϥ�V�r��
            printf("%c",i+'A');
        }
        b--;
        printf("\n");
    }
    for(j=x-1;j>0;j--){
        for(i=j;i<x;i++){
            printf(" ");
        }
        for(i=0;i<j;i++){
            printf("%c",i+'A');
        }
        for(i=j-2;i>=0;i--){
            printf("%c",i+'A');
        }
        printf("\n");
    }
    return 0;
}
