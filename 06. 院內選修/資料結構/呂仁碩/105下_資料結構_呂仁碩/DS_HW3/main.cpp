#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//#define ARRAY_SIZE 6

using namespace std;

class term{
    public:
        term();
        ~term();
        char character;
        bool Lroot;
        bool Rroot;
        int io_index;
        int Nlevel;

};

term::term(){
    character = '\0';
    Lroot = true;
    Rroot = true;

}

term::~term(){};


int main()
{
    //freopen("t2.txt", "r", stdin);
    //freopen("o2.txt", "w", stdout);

    int j;
    int ARRAY_SIZE;
    int Ntree;
    vector<char> A,B,LvNewArray;
    vector<term> Terms, NewTerms;
    vector<char>::iterator ci,ci2;
    vector<term>::iterator ti;


    char temp;

    cin >> Ntree;
    cout << Ntree;
    while(Ntree >0){

    for(getchar(), temp =  getchar(); temp != '\n'
        ; temp = getchar())
        A.push_back(temp);


    //char *A  = new char[ARRAY_SIZE];//[ARRAY_SIZE] = {'a','b','d','c','e','f'};
    //char *B  = new char[ARRAY_SIZE];//[ARRAY_SIZE] = {'a','d','b','e','c','f'};
    //char *LvNewArray = new char[ARRAY_SIZE];


    cout <<"456";
    for( ci = A.begin(), ti = Terms.begin(); ci != A.end() ; ci++, ti++ ){///////
        *ti.character = *ci;
        cout << *ti.character  ;
    }
    cout << endl;
    for(int i = 0; i < (signed int)A.size() ; i++){
       B.push_back( getchar() ) ;
    }

    for( ci = B.begin(); ci != B.end() ; ci++ ) cout << *ci ;

    cout << " ";

    for( ci = A.begin(); ci != A.end() ; ci++ ) {
        for( ci2 = B.begin(); ci2 != B.end() ; ci++ ){
            if( ti.character == *ci2) Terms[ci- A.begin()].io_index = ci2 - B.begin();
        }
    }
    cout << "123";
    for( int i = 0; i < A.size() ; i++ )
        {cout << Terms[i].io_index ; if(i != A.size()-1) cout << "-";}


    for( int i = 0; i < A.size() ; i++ ){
        if( i == 0 ) Terms[i].Nlevel = 1;
        NewTerms[ Terms[i].io_index ] = Terms[i];
        for(j = Terms[i].io_index - 1 ; NewTerms[j].character =='\0' && j >= 0 ; j--);
        if( j != -1 && NewTerms[j].Rroot == true){
            NewTerms[j].Rroot = false;
            NewTerms[Terms[i].io_index].Nlevel = NewTerms[j].Nlevel + 1;
            continue;
        }
        for(j = Terms[i].io_index + 1 ; NewTerms[j].character =='\0' && j < A.size() ; j++);
        if( j != A.size() && NewTerms[j].Lroot == true ) {
            NewTerms[j].Lroot = false;
            NewTerms[Terms[i].io_index].Nlevel = NewTerms[j].Nlevel + 1;
        }
    }

    for(int counter = 0, level = 1; counter < A.size() ; level ++ )
        for( int i = 0; i < A.size() ; i++)
            if(NewTerms[i].Nlevel  == level) LvNewArray[counter++] = NewTerms[i].character;
    //for( int i = 0; i < ARRAY_SIZE ; i++ ) cout << NewTerms[i].Nlevel << " " ;
    //cout << endl;
    //for( int i = 0; i < ARRAY_SIZE ; i++ ) cout << LvNewArray[i] << " ";
    //cout << endl;
    for( j = 0; j < A.size() && LvNewArray[j] == Terms[j].character ; j++ );
    if (j == A.size()) cout << " OK" << endl;

    A.erase(A.begin(),A.end());
    B.erase(B.begin(),B.end());
    LvNewArray.erase(LvNewArray.begin(),LvNewArray.end());
    Terms.erase(Terms.begin(),Terms.end());
    NewTerms.erase(NewTerms.begin(),NewTerms.end());
    Ntree--;
    }
    return 0;
}
