#include<sstream>
#include<iostream>
#include<string>

using namespace std;

string int2str(int &);

int main()
{
    string s, out_str;
    out_str = "";
    //out_str = "3d4";
    int i=0;
    s = int2str(i);
    out_str += s;
    cout << s << " " << out_str << endl;

    return 0;
}

string int2str(int &i) {
    string s;
    stringstream ss(s);
    ss << i;
    return ss.str();
}
