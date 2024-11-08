#include<iostream>
#include<string>
#include <stdlib.h>
#include <string.h>

using namespace std;
int main()
{
    /*string path[2];
    path[1] = "grsd";
    path[2] = "fgs";
    cout << "path[1]=" << path[1] << endl;
    cout << "path[1][2]=" << path[1][2] << endl;
    cout << "path[1].length =" << path[1].length() << endl;
    cout << "path[2]=" << path[2] << endl;*/

    string s1 = "312645";
    char str1[1], str2[1];
    str1[0] = s1[2];
    str2[0] = s1[4];
    int i_dec, i_dec2;
    i_dec = atoi(str1);
    i_dec2 = atoi(str2);
    cout << str1[0] << ","<< i_dec << endl;
    cout << str2[0] << ","<< i_dec2 << endl;
    cout << "s1_string:" << s1 << ",s1_int[2]&s1_int[4]:" << i_dec << "," << i_dec2 << endl;

    int abc[3][3]= {3,4,5, 6,7,8, 9,0,1};
    int def[3][3]= {1,2,3, 4,5,6, 7,8,9};
    int copy1[3][3];
    if (memcmp(abc, def, sizeof(abc)) == 0) //快速比對, ASSERT(sizeof(abc) == sizeof(def));
        cout << "same" << endl;
    else
        cout << "different" << endl;
    memcpy(copy1, abc, sizeof(copy1)); //快速拷貝, ASSERT(sizeof(abc) == sizeof(copy));
    copy1[2][1] = 10;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++) cout << copy1[i][j] << " ";
        cout << endl;
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++) cout << abc[i][j] << " ";
        cout << endl;
    }
    if (memcmp(abc, copy1, sizeof(abc)) == 0) //快速比對, ASSERT(sizeof(abc) == sizeof(copy));
        cout << "same" << endl;
    else
        cout << "different" << endl;

    return 0;
}
