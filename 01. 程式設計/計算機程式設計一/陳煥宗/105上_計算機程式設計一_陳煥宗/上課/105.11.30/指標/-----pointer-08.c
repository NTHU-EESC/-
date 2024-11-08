/* W10_03.c */
#include<stdio.h>
typedef int row_vector [5];


int main(void)
{
   int a[][4] = { {1, 2, 3, 4}, {5, 6}, {9, 10, 11, 12}};
   int b[][4] = { 1, 2, 3, 4, 5, 6, 9, 10, 11, 12};
   int i, j;
   row_vector matrix[4];


   printf("a:       %d bytes\n", sizeof(a));
   printf("a[0]:    %d bytes\n", sizeof(a[0]));
   printf("a[0][0]: %d bytes\n", sizeof(a[0][0]));

   printf("\n");
   for (i=0; i<3; i++) {
      for (j=0; j<4; j++) {
         printf("%3d ", a[i][j]);
      }
      printf("\n");
   }
   printf("\n");
   for (i=0; i<3; i++) {
      for (j=0; j<4; j++) {
         printf("%3d ", b[i][j]);
      }
      printf("\n");
   }

   return 0;
}

