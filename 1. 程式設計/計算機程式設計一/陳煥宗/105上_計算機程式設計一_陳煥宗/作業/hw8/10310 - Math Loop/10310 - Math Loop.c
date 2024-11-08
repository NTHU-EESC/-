#include<stdio.h>
#include<string.h>
void large(int value);
void small(void);
void calculate(int figure);

int frequency;
int lar_value, smal_value;
int num[100], figure[100];

int main(void)
{
    int number;
    scanf("%d",&number);
    figure[0] = number;
    calculate(number);
    return 0;
}

void large(int value)
{
    lar_value = smal_value = 0;
    int i, j, k, x;
    int tmp;

    /*num[3] = value/1000;
    num[2] = (value/100)-10*num[3];
    num[1] = (value%100)/10;
    num[0] = value%10;*/

    k = 0;//
    while(value){//0-->false
        num[k] = value%10;//2->num[0];5->num[1];3->num[2];8->num[3]
        value = value/10;
        k++;
    }
    x = k;//

    for(i=0;i<k;i++){
        for(j=i+1;j<k;j++){
            if(num[i]>num[j]){
                tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }

    //lar_value = 1000*num[3]+100*num[2]+10*num[1]+num[0];
    //smal_value = 1000*num[0]+100*num[1]+10*num[2]+num[3];

    while(k){
        lar_value = 10*lar_value + num[k-1];
        k--;
    }
    for(i=0;i<x;i++) smal_value = 10*smal_value + num[i];
}

/*void small(void)
{
    int tmp, temp;
    tmp = num[0];
    temp = num[1];
    num[0] = num[3];
    num[1] = num[2];
    num[2] = temp;
    num[3] = tmp;
    smal_value = 1000*num[3]+100*num[2]+10*num[1]+num[0];
}*/

void calculate(int x)
{
    int i, j, k;
    large(x);
    //small();
    for(i=0;i<=frequency;i++){
        if((lar_value - smal_value) == figure[i]){
            frequency++;
            printf("%d\n",frequency);
            return;
        }
    }
    /*if((lar_value - smal_value) == x){
        frequency++;
        printf("%d",frequency);
    }*/
    frequency++;
    figure[frequency] = lar_value - smal_value;
    calculate(figure[frequency]);
}
