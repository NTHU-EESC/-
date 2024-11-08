// Example program
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int c2i(char v)
{
  return v - '0';
}

int main()
{
  int v = c2i('8');
  cout << v << endl;

  string s1 = "312645";
  char str1[2], str2[2];
  str1[0] = s1[2];
  str1[1] = '\0';
  str2[0] = s1[4];
  str2[1] = '\0';
  int i_dec, i_dec2;
  i_dec = atoi(str1);
  i_dec2 = atoi(str2);
  cout << str1[0] << ","<< i_dec << endl;
  cout << str2[0] << ","<< i_dec2 << endl;

  return 0;
}

