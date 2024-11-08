/*
 * exp3.cpp: using C++ input/output and namespace
 *
 */

#include <iostream>
#include <cstdio>

/* two ways of using preprocessor using       */
/* 1. the entire namespace,                   */
/*    all variables/functions can be accessed */
/*    without scope operator ::               */
/* 2. individual variable/function            */
/*                                            */
using namespace std;
/* using std::cin;                            */
/* using std::cout;                           */

int main(void)
{
    int i,j;

    printf("Hello world from printf\n");
    std::cout << "Hello world from cout\n";

    cout << "i=";
    cin >> i;
    cout << "j=";
    cin >> j;
    cout << "i=" << i << " j=" << j << "\n";
}
