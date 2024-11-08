/* �y�� */
//qsort �Ʌ��� http://www2.lssh.tp.edu.tw/~hlf/class-1/lang-c/qsort.htm
//rand() �Ʌ��� http://dhcp.tcgs.tc.edu.tw/c/p005.htm
//RAND_MAX�@��������rand()���ܮa�������y�������x��stdlib.h�e��
#include <stdio.h>
#include <stdlib.h> //����qsort, rand(), RAND_MAX
#include <string.h>
#define SIZE 10
int compare_int (const void *a, const void *b)  //const�_���������M�������޸�->���ܱ���ֵ->������++or--�ȵ�
{
    const int *va = (const int *) a;
    const int *vb = (const int *) b;
    return *va-*vb;
    //return *((const int *)a) - *((const int *)b);  //�H����԰��������к����ɴ�
}
int compare_double (const void *a, const void *b)  //�˜ʌ���
{
    const double *da = (const double *) a;
    const double *db = (const double *) b;
    return (*da > *db) - (*da < *db);  //(*da > *db)�c(*da < *db)���Д�ʽ���քeֻ���؂�1����0
    /*if(*da>*db) return 1;
    else if(*da<*db) return -1;
    else return 0;*/                   //����@�ӌ�
}

int main(void)
{
    int data1[SIZE];
    double data2[SIZE];
    int i;

    for (i=0; i<SIZE; i++) {
        data1[i] = rand()%SIZE;
        data2[i] = (double) rand()/RAND_MAX;  //***��rand()�D�Q��double
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
