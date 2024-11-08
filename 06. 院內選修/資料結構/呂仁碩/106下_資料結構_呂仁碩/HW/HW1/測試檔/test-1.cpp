#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

typedef struct{
    string str;
}tt;

int main()
{
    tt st, st1;
    string ter;
    int n;
    st.str = "steexf";
    ter = "sdfd";
    //st1 = st + 's';
    st1.str = st.str+' ';
    cout << st1.str <<endl;
    cout << st1.str.length() << endl;
    st1.str = st.str+ter;
    cout << st1.str <<endl;
    cout << st1.str.length() << endl;
    n = st1.str.length();
    st1.str += 's';
    cout << st1.str <<endl;
    cout << st1.str.length() << endl;
    cout << "st1[7] = " << st1.str[st1.str.length()-1] << endl;
    st1.str[n] = '\0';
    cout << st1.str <<endl;
    cout << st1.str.length() << endl;
    st1.str += 's';
    cout << st1.str <<endl;
    cout << st1.str.length() << endl;

    /*string in;
    cin >> in;
    if(in=="in") cout << in;*/

    string s1, s2, s3;
    string a;
    char q = 'a';
    //a += 'a';
    a += q;
    s1 = s2 = "1234567890";
    cout << s1 << endl;
    cout << s1.length() << endl;
    s1.insert(5,a);
    cout << s1 << endl;
    cout << s1.length() << endl;
    q = s1[s1.length()-1];
    cout << q << endl;

    return 0;
}
