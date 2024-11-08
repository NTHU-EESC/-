/* 亂數 */
//qsort 可參考 http://www2.lssh.tp.edu.tw/~hlf/class-1/lang-c/qsort.htm
//rand() 可參考 http://dhcp.tcgs.tc.edu.tw/c/p005.htm
//RAND_MAX這個常數是rand()所能產生的最大亂數，定義在stdlib.h裡面
#include <stdio.h>
#include <stdlib.h> //內有qsort, rand(), RAND_MAX
#include <string.h>
#define SIZE 10
int compare_int (const void *a, const void *b)  //const確保參數傳進來不會被修改->不能被改值->不能做++or--等等
{
    const int *va = (const int *) a;
    const int *vb = (const int *) b;
    return *va-*vb;
    //return *((const int *)a) - *((const int *)b);  //亦可以把上面三行簡化成此
}
int compare_double (const void *a, const void *b)  //標準寫法
{
    const double *da = (const double *) a;
    const double *db = (const double *) b;
    return (*da > *db) - (*da < *db);  //(*da > *db)與(*da < *db)是判斷式，分別只會回傳1或是0
    /*if(*da>*db) return 1;
    else if(*da<*db) return -1;
    else return 0;*/                   //亦可這樣寫
}

int main(void)
{
    int data1[SIZE];
    double data2[SIZE];
    int i;

    for (i=0; i<SIZE; i++) {
        data1[i] = rand()%SIZE;
        data2[i] = (double) rand()/RAND_MAX;  //***把rand()轉換成double
    }

    printf("original: ");
    for (i=0; i<SIZE; i++) {
        printf("%d ", data1[i]);
    }
    printf("\n");

    printf("  sorted: ");
    qsort(data1, SIZE, sizeof(int), compare_int);  //***
    for (i=0; i<SIZE; i++) {
        printf("%d ", data1[i]);
    }
    printf("\n");

    printf("original: ");
    for (i=0; i<SIZE; i++) {
        printf("%.2f ", data2[i]);
    }
    printf("\n");

    printf("  sorted: ");
    qsort(data2, SIZE, sizeof(double), compare_double);
    for (i=0; i<SIZE; i++) {
        printf("%.2f ", data2[i]);
    }
    printf("\n");

    return 0;
}
