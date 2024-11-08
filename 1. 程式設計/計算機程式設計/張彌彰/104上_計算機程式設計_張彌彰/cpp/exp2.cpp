/*
 * exp2.cpp: namespace and variable scopes
 *
 */
#include <iostream>
using std::cin;
using std::cout;
int i=200;    // global variables
int j=300;    // global variables
namespace mySpace {    // namespace variables
  int i=20;
  int j=30;
  int k=40;
};
namespace mySpace2 {    // another namespace variables
  int i=2000;
  int j=3000;
};
/* example of conflicts */
/* using mySpace::i; */
using mySpace::k;

int main(void)
{
    int i=1,j=2;
    int k=3;

    cout << "i=" << i << "\n";
    cout << "j=" << j << "\n";
    cout << "mySpace::i=" << mySpace::i << "\n";
    cout << "mySpace::j=" << mySpace::j << "\n";
    cout << "mySpace2::i=" << mySpace2::i << "\n";
    cout << "mySpace2::j=" << mySpace2::j << "\n";
    cout << "i=" << ::i << "\n";
    cout << "j=" << ::j << "\n";

    cout << "k=" << k << "\n";
}
