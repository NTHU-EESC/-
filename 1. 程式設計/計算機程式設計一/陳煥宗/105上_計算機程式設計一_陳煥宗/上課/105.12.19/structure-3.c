#include <stdio.h>
#include <stdlib.h>
/* 定義一個新的型別 */
/* 取名叫做 Point */
/* 裡面包含 x 和 y 兩個 members */
/* 定義過之後   Point 可以被拿來當作一般的型別來使用 */
/* 包括宣告新的變數   或是宣告 function */
typedef struct {
    int x;
    int y;
} Point;

/* ones_vec_1() 會傳回某個 Point 結構的位址 */
/* 這個位址是由 Point 結構組成的陣列的開頭位址 */
Point * ones_vec_1(int length);

void ones_vec_2(int length, Point **bp);

int main(void)
{
   Point *a, *b;
   int i, length;

   printf("The size of a Point is %u bytes.\n", sizeof(Point));

   printf("vector length: ");
   scanf("%d", &length);

   /* 利用 ones_vec_1 取得一個陣列 */
   /* 陣列的每個元素是一個 Point */
   /* 陣列的開頭位址記錄在指標變數 a 裡面 */
   a = ones_vec_1(length);
   ones_vec_2(length, &b); //b是一個位置

   /* a 是個指標變數   它記錄的是某個陣列的開頭位址 */
   /* 陣列的每個元素是 a[i] (是個 Point) */
   /* 所以有兩個 members  分別是 a[i].x 和 a[i].y */
   for (i=0; i<length; i++)
      printf("(%d, %d) ", a[i].x, a[i].y);
   printf("\n");

   for (i=0; i<length; i++)
      printf("(%d, %d) ", b[i].x, b[i].y);
   printf("\n");


   return 0;
}

Point * ones_vec_1(int length)
{
   Point *a;
   int i;
   a = (Point *) malloc(length * sizeof(Point)); //a去取malloc後的開頭位置
   for (i = 0 ; i < length; i++) {
      a[i].x = 1; //(a+i)->x=1;
      a[i].y = 1; //(*(a+i)).y = 1;
   }
   return a;
}

void ones_vec_2(int length, Point* *bp) //bp = &b;
{
   int i;

   *bp = (Point *) malloc(length * sizeof(Point)); //malloc像電腦要空間
   for (i = 0 ; i < length; i++) {
      (*bp)[i].x = 1;
      (*bp)[i].y = 1;
   }
}
