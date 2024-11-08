/*
 * exp9.cpp: dynamic memory allocation
 *
 */

#include <iostream>        // for cin and cout functions
using std::cout;

int main(void)
{
    int i=1,j=2;
    int *p1, *p2;
    int *bArray;

    p1=&i;
    p2=&j;
    cout << "i=" << i << "  j=" << j << "\n";
    cout << "*p1=" << *p1 << "  *p2=" << *p2 << "\n";

    p1=new int;
    *(p1)=3;
    p2=new int;
    *(p2)=4;
    cout << "i=" << i << "  j=" << j << "\n";
    cout << "*p1=" << *p1 << "  *p2=" << *p2 << "\n";

    delete p2;
    delete p1;

    bArray=new int[10];
    for (i=0; i<10; i++) bArray[i]=i;

    for (i=0; i<10; i++) {
        cout << "bArray[" << i << "]=" << bArray[i] << "\n";
    }

    delete [] bArray;
}
