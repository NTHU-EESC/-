#include<stdio.h>
int main(void)
{
    char ch;
    int operations,Person_Id,coins;
    int i,j,k;
    int a[100];
    for(i=1;i<=10;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&operations);
    for(i=0;i<operations;i++){
        a[0] = 0;
        a[11] = 0;
        scanf("%d %c %d",&Person_Id,&ch,&coins);
        if(a[Person_Id]<coins);
        else{
            if(ch=='F'){
                a[Person_Id+1] += coins;
                a[Person_Id] -= coins;
            }
            if(ch=='B'){
                a[Person_Id-1] += coins;
                a[Person_Id] -= coins;
            }
        }
        a[10] += a[0];
        a[1] += a[11];
    }

    for(i=1;i<=10;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}
