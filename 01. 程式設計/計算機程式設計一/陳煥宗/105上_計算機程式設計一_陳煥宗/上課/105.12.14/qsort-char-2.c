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
       void* a = &ptrs[i];  // 此是把記憶體位置存進來  // a是記憶體位置; *a是對應的值
                            // void*是資料結構
       some_type* va = (some_type*) a; (把a位置內存放的值放入va位置) --> char** va = (char**) a; */
    char **pa;
    char **pb;
    pa = (char **) a;
    pb = (char **) b;
    return strcmp(*pa, *pb);
    // int strcmp (const char *s1, const char *s2); 所以存入s1 & s2的資料型別是char*
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
        ptrs[i] = strs[i]; //str[i]是由4個字元組成的門牌號碼
    }
    qsort(ptrs, SIZE, sizeof(char*), compare_str_ptr);  //sixeof(*char)因為ptrs的資料型別為此  //把ptrs指的東西變換
    for (i=0; i<SIZE; i++) {
        printf("%s\n", ptrs[i]);  // %s把字串print出來
    }
    printf("\n");
    for (i=0; i<SIZE; i++) {
        printf("%s\n", strs[i]);
    }


    return 0;
}
