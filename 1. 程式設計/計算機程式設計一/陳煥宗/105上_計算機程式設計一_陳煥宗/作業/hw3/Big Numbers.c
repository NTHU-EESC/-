#include <stdio.h>
/* 2016/09/22 */
int first4(int x){
   return x/10000;
}
int last4(int x){
   /* The operator % in C computes the remainder after division.
      For example, the answer of 23%7 will be 2.*/
   return x%10000;
}
int first8(int x){
   return x/100000000;
}
int last8(int x){
   return x%100000000;
}
int shift4(int x){
   return x*10000;
}
int main(void){
  int x;
  int a, b;
  int c1, c2, c3;
  /* Assume that the input is always an 8-digit positive integer. */
  scanf("%d",&x);
  a = first4(x);
  b = last4(x);
  c3 = last4(b*b);
  c2 = 2*a*b+first4(b*b)+shift4(last4(a*a));//last8(shift(a*a))不行，因為這樣裡面就12位數，overflow
  c1 = first4(a*a)+first8(c2);
  printf("%4d%08d%04d", c1, last8(c2), c3);
  /* %04d will display a 4-digit number and add 0 as padding before the number if necessary */
  return 0;
}
/*Assume that the input 8-digit integer x can be expressed by a*10000 + b .
The square of x can be expressed as a*a*100000000 + 2*a*b*10000 + b*b .
We may partition the computation into three parts.
An illustration of the idea is as follows:

| 4 digits | 4 digits | 4 digits | 4 digits |
                      |        b * b            |
          |      2 * a * b         |
|        a * a            |
|    c1      |          c2              |    c3     |

※要注意進位的情形!!*/
