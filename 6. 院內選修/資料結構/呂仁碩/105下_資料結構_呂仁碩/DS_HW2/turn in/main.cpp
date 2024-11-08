#include <iostream>
#include <fstream>

using namespace std;

int Index_R;

class SparseMatrix; //forward declaration

class MatrixTerm{
friend class SparseMatrix;
private:
    int row, col, value; // a triple representing a term
};

class SparseMatrix{
public:
    SparseMatrix(int Nrow,int Ncol,int Ncapacity);
    ~SparseMatrix();
    SparseMatrix Invert();
    void Print() const;
    void AddTerms(int xrow, int xcol, int xvalue);
    void ChangeSize1D(const int newSize);
    int DotMult(const SparseMatrix b);
    SparseMatrix tempMatrixGen(int r, int c, int dr, int dc);
    void wipe();
    //SparseMatrix Transpose();
    //SparseMatrix Multiply(SparseMatrix b);
//
private:
    int rows, cols, terms, capacity;
    MatrixTerm* smArray;
};

SparseMatrix::SparseMatrix(int Nrow,int Ncol,int Ncapacity ){
    rows = Nrow;
    cols = Ncol;
    capacity = Ncapacity;

    smArray = new MatrixTerm [capacity];
    for(int i = 0; i < capacity ;i++){
        smArray[i].row = 0 ;
        smArray[i].col = 0;
        smArray[i].value = 0;
    }
    terms = 0;
}

SparseMatrix::~SparseMatrix(){
    delete[] smArray;
}

SparseMatrix SparseMatrix::Invert(){
    SparseMatrix b(rows, cols, capacity);
    //SparseMatrix *p = &b;

    for(int i = 0; i< terms ; i++){
        b.smArray[i].row = rows -1 - smArray[terms -1 - i ].row ;
        b.smArray[i].col = cols -1 - smArray[terms -1 - i ].col ;
        b.smArray[i].value = smArray[terms -1 - i].value;
    }
    b.terms = this->terms;
    return b;
}

void SparseMatrix::Print()const{
    cout << rows << " "<< cols << " "<<terms<< endl;
    for(int i = 0;i < terms ; i++){
        cout << smArray[i].row << " ";
        cout << smArray[i].col << " ";
        cout << smArray[i].value ;
        cout << endl;
    }
    //cout << "capacity = " << capacity << endl;
    //cout << "terms = " << terms<< endl;
    //cout << "-----------------------------------"<< endl;
}
void SparseMatrix::AddTerms(int xrow, int xcol, int xvalue){
    if(xvalue != 0){
        if(terms == capacity)ChangeSize1D(2*capacity);
        smArray[terms].row = xrow;
        smArray[terms].col = xcol;
        smArray[terms++].value = xvalue;
    }
}

void SparseMatrix::ChangeSize1D(const int newSize){
// change the array size to newSize
    if(newSize < terms)
        throw "New size must be >= number of terms";

    MatrixTerm *temp = new MatrixTerm[newSize]; // new array
    copy(smArray, smArray + terms, temp);
    delete[]smArray;
    smArray= temp; // make smArraypoint to the newly created array
    capacity = newSize;
}

int SparseMatrix::DotMult(const SparseMatrix b){
    int sum ;
    int aIndex ,bIndex;

    if(rows != b.rows || cols != b.cols)
        cout << "Incompatible Matrix for DotMult" << endl;

    for(sum = 0, aIndex = 0, bIndex = 0
        ;aIndex < this->terms  && bIndex < b.terms ;){
        if(smArray[aIndex].row < b.smArray[bIndex].row)
            aIndex ++;
        else if(smArray[aIndex].row > b.smArray[bIndex].row)
            bIndex ++;
        else if(smArray[aIndex].col < b.smArray[bIndex].col)
            aIndex++;
        else if(smArray[aIndex].col > b.smArray[bIndex].col)
            bIndex++;
        else sum += smArray[aIndex++].value * b.smArray[bIndex++].value;
    }
    return sum;

}
SparseMatrix SparseMatrix::tempMatrixGen(int r, int c, int dr, int dc){
    int Index;
    SparseMatrix B(dr,dc,5);

    for(Index = Index_R; smArray[Index].row < r-(dr-1)/2; Index++);
    Index_R = Index;
    for(;smArray[Index].row <= r+(dr-1)/2 && Index < terms ;Index++){
        int col_diff = smArray[Index].col - c;

        if( col_diff <= (dc-1)/2 && col_diff >= -(dc-1)/2 )
            B.AddTerms(smArray[Index].row - (r-(dr-1)/2),
                       smArray[Index].col - (c-(dc-1)/2),
                       smArray[Index].value             );
    }
    return B;
}
void SparseMatrix::wipe(){
    for(int i = 0; i < capacity ;i++){
        smArray[i].row = 0 ;
        smArray[i].col = 0;
        smArray[i].value = 0;
    }
    terms = 0;
}


int main()
{
    freopen("t7.txt", "r", stdin);
    freopen("a7.txt", "w", stdout);
    int Ntests;

    int Rows ; int Cols;
    int rows ; int cols;
    int nonZero;
    int r,c,v;
    for(cin >> Ntests;Ntests > 0;Ntests--){

        cin >> Rows >> Cols >> nonZero;
        //cout << "building...."<<endl;
        SparseMatrix A(Rows,Cols,5);
        //cout << dimr << dimc << nonZero <<endl;
        for(;nonZero>0;nonZero--){
            cin >> r >> c >> v;
            A.AddTerms(r,c,v);
        }
        //A.Print();


        cin >> rows >> cols >> nonZero;
        //cout << "building...."<<endl;
        SparseMatrix B(rows,cols,5);
        //cout << dimr << dimc << nonZero <<endl;
        for(;nonZero>0;nonZero--){
            cin >> r >> c >> v;
            B.AddTerms(r,c,v);
        }
       // B.Print();
        SparseMatrix b = B.Invert();

        int sum = 0 ;
        SparseMatrix C(Rows,Cols,5);
        Index_R = 0;
        for(int r =0; r < Rows ; r++){
        for(int c = 0; c < Cols ;c++){
            sum = b.DotMult( A.tempMatrixGen(r,c,rows,cols) );
            if(sum != 0)
                C.AddTerms(r,c,sum);
        }
    }
        C.Print();
    }
    return 0;

    /*B.AddTerms(0,0,2);
    B.AddTerms(1,1,1);
    B.AddTerms(2,0,3);
    B.AddTerms(2,2,1);
    B.Print();
    SparseMatrix b = B.Invert();
    b.Print();

    SparseMatrix C(6,6,5);

    C.AddTerms(1,1,15);
    C.AddTerms(1,4,22);
    C.AddTerms(2,2,11);
    C.AddTerms(2,3,3);
    C.AddTerms(3,4,-6);

    SparseMatrix p(3,3,3);*/

/*
    int sum = 0 ;
    SparseMatrix D(6,6,5);

    for(int r =0; r < Rows ; r++){
        for(int c = 0; c < Cols ;c++){
            sum = b.DotMult( C.tempMatrixGen(r,c,rows,cols) );
            if(sum != 0)
                D.AddTerms(r,c,sum);
        }
    }
    D.Print();
    return 0;*/
}
