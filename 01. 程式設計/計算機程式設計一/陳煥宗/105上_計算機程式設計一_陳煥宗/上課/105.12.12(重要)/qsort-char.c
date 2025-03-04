#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //內有strcmp
#define SIZE 10

// strcmp可參考 http://pydoing.blogspot.tw/2010/07/c-strcmp.html
/*int cmpstr(const void *p, const void *q)
{
    const char * sp = (const char*) p;
    const char * sq = (const char*) q;
    return strcmp(sp, sq);
}*/

int main(void)
{
    char strs[SIZE][4] ={
        "aab", "abc", "aaa", "abb", "acb",
        "aab", "abc", "aaa", "abb", "acb"
    };
    // 每個陣列的元素包含三個英文字元外加後面跟著一個 '\0' 字元 總共 4 bytes
    /*strs[SIZE][4] 這個二維陣列的內容
      strs[0] 對應到 "aab"
      strs[1] 對應到 "abc"
      strs[0][1] 對應到 'a'
      strs[5][3] 對應到 '\0'*/
    int i;

    for (i=0; i<SIZE; i++) {
        printf("%s\n", strs[i]);
    }
    printf("\n");
    qsort(strs, SIZE, 4*sizeof(char), (int (*) (const void *, const void *))strcmp);
    /*讓 strcmp 變成符合型別
      原本 strcmp 的型別 int strcmp (const char *s1, const char *s2);
      經過型別轉換之後變成 int strcmp (const void *s1, const void *s2);*/
    // 4*sizeof(char)--4是因為每棟房子都有4個bytes，所以在搬時要一次搬4個bytes
    for (i=0; i<SIZE; i++) {
        printf("%s\n", strs[i]);
    }
    return 0;
}
