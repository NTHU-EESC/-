#include<iostream>
#include <string.h>

using namespace std;
int main()
{
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
    memcpy(def, abc, sizeof(def));
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++) cout << def[i][j] << " ";
        cout << endl;
    }

    if (memcmp(abc, copy1, sizeof(abc)) == 0) //快速比對, ASSERT(sizeof(abc) == sizeof(copy));
        cout << "same" << endl;
    else
        cout << "different" << endl;

    int** a = new int*[3];
    int** b = new int*[3];
    for(int i=0; i<3; i++){
        a[i] = new int[3];
        b[i] = new int[3];
        for(int j=0; j<3; j++) a[i][j] = i*3 + j;
    }
    memcpy(b, a, sizeof(b));
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++) cout << b[i][j] << " ";
        cout << endl;
    }

    return 0;
}
