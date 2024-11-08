#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

typedef struct{
    string name;
    string formula;
    double mass;
}mole;

int main()
{
    int num;
    cin >> num;

    ofstream fout("PeriodicTable.txt");

    mole* mole_array;
    mole_array = new mole[num];

    for(int i=0; i<num; i++){
        cin >> mole_array[i].name;
        cin >> mole_array[i].mass;
    }

    for(int i=0; i<num; i++){ // \"表示雙引號
        fout << "else if(s==\""<< mole_array[i].name <<"\") return " << mole_array[i].mass << ";" << endl;
    }

    return 0;
}
