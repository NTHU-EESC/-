/*
 * exp1.cpp: C and C++ I/O functions
 */

#include <cstdio>
#include <iostream>

int main(void)
{
    int i,j;

    printf("Hello world\n");
    std::cout << "Hello world\n";

    /* C input and output */
    printf("i=");
    scanf("%d",&i);
    printf("j=");
    scanf("%d",&j);
    printf("i=%d j=%d\n",i,j);

    /* C++ input and output */
    std::cout << "i=";
    std::cin >> i;
    std::cout << "j=";
    std::cin >> j;
    std::cout << "i=" << i << " j=" << j << "\n";
}
