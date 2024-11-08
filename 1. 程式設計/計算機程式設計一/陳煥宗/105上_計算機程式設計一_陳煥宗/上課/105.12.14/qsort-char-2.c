#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

int compare_str_ptr(const void *a, const void *b)
{
    /* type = x;
       type* y = &x;*/
    //              a = &ptrs[i]    b = &ptrs[j]
    /* some_type ptrs[i];
       void* a = &ptrs[i];  // ���O��O�����m�s�i��  // a�O�O�����m; *a�O��������
                            // void*�O��Ƶ��c
       some_type* va = (some_type*) a; (��a��m���s�񪺭ȩ�Jva��m) --> char** va = (char**) a; */
    char **pa;
    char **pb;
    pa = (char **) a;
    pb = (char **) b;
    return strcmp(*pa, *pb);
    // int strcmp (const char *s1, const char *s2); �ҥH�s�Js1 & s2����ƫ��O�Ochar*
}

int main(void)
{
    char strs[SIZE][4] ={
        "aab", "abc", "aaa", "abb", "acb",
        "aab", "abc", "aaa", "abb", "acb"
    };
    char *ptrs[SIZE];
    int i;

    for (i=0; i<SIZE; i++) {
        printf("%s\n", strs[i]);
    }
    printf("\n");


    for (i=0; i<SIZE; i++) {
        ptrs[i] = strs[i]; //str[i]�O��4�Ӧr���զ������P���X
    }
    qsort(ptrs, SIZE, sizeof(char*), compare_str_ptr);  //sixeof(*char)�]��ptrs����ƫ��O����  //��ptrs�����F���ܴ�
    for (i=0; i<SIZE; i++) {
        printf("%s\n", ptrs[i]);  // %s��r��print�X��
    }
    printf("\n");
    for (i=0; i<SIZE; i++) {
        printf("%s\n", strs[i]);
    }


    return 0;
}
