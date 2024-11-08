#include <iostream>
#include <stack>
#include <fstream>
#include <stdlib.h>

using namespace std;




template<class T>
class Rectangle{
    public:
        Rectangle(T Height = 0,T Width = 0);
        ~Rectangle();
        T H,W;
        T getArea();
};

template<class T>
Rectangle<T>::Rectangle(T Height ,T Width ){
    H = Height;
    W = Width;
}

template<class T>
Rectangle<T>::~Rectangle(){};

template<class T>
inline T Rectangle<T>::getArea(){
    return H*W;
}

const Rectangle<int> Vfunc(Rectangle<int> &A, Rectangle<int> &B){
    Rectangle<int> C;

    C.W = A.W + B.W;
    C.H = max(A.H,B.H);

    return C;
}

const Rectangle<int> Hfunc(Rectangle<int> &A, Rectangle<int> &B){
    Rectangle<int> C;

    C.W = max(A.W,B.W);
    C.H = A.H + B.H;

    return C;
}

Rectangle<int> *A;
int *sizes;

void Eval(int NArrangement,int NRegtangle){
    stack< Rectangle<int> > s;
    Rectangle<int> X, Y;
    char buff[10];
    sizes = new int[NArrangement];

    for(int i = 0;i < NArrangement ;i++){
        for(int j = 2*NRegtangle-1; j >0; j--){
            scanf("%s", buff);
            if(buff[0] == 'V'){
                X = s.top(); s.pop();
                Y = s.top(); s.pop();
                X = Vfunc(X,Y);
                s.push(X);
            }
            else if (buff[0] == 'H'){
                X = s.top(); s.pop();
                Y = s.top(); s.pop();
                X = Hfunc(X,Y);
                s.push(X);
                //cout << "Y";
                //cout <<"H: "<< A[Acapacity-1].H << "W: "<<A[Acapacity-1].W<< endl;
            }
            else s.push( A[atoi(buff)]); //cout << "Z";}
            cout << buff <<" ";
        }
        sizes[i] = X.getArea();
        cout  <<X.H<<" "<<X.W<< " "<< sizes[i] << endl;
    }

}


int main()
{
    int NRegtangle;
    int NArrangement;
    int temp;
    char buff[10];

    //freopen("t3.txt", "r", stdin);
    //freopen("o3.txt", "w", stdout);

    cin >> NRegtangle;
    cout << NRegtangle <<endl;
    A = new Rectangle<int>[NRegtangle+1];
    for(int i =0 ;i < NRegtangle ; i++){
        cin >> temp;
        cin >> A[i].H;
        cin >> A[i].W;
    }


    for(int i =0 ;i < NRegtangle ; i++){
        cout << i <<" ";
        cout << A[i].H << " ";
        cout << A[i].W << endl;
    }
    cin >> NArrangement;
    cout << NArrangement<< endl;
    Eval(NArrangement,NRegtangle);
    /*for(int i = 0;i < NArrangement ;i++){
        for(int j = 2*NRegtangle-1; j >0; j--){
            scanf("%s", buff);
            cout << buff << " ";
        }
        cout << endl;
    }*/
    int Max,Min,mindex,maxdex,i;
    for( Min = sizes[0],mindex = 0, i = 1;i < NArrangement; i++)
        if(sizes[i] < Min ) {Min = sizes[i];mindex = i;}
    cout <<"min = " << sizes[mindex]<<"(" << mindex <<")"<< endl;
    for( Max = sizes[0],maxdex = 0 , i = 1;i < NArrangement; i++)
        if(sizes[i] > Max ) {Max = sizes[i];maxdex = i;}
    cout <<"max = " << sizes[maxdex]<<"(" << maxdex <<")"<< endl;

    /*cout << A[0].H << endl;
    A[0].H = 20;
    A[0].W = 50;
    cout << A[0].getArea()<< endl;
    A[1].H = 30;
    A[1].W = 40;
    A[2] = Vfunc(A[1],A[0]);
    cout << A[2].H << endl;
    cout << A[2].W << endl;
    cout << A[2].getArea()<< endl;
    A[2] = Hfunc(A[1],A[0]);
    cout << A[2].H << endl;
    cout << A[2].W << endl;
    cout << A[2].getArea()<< endl;*/

    return 0;
}
