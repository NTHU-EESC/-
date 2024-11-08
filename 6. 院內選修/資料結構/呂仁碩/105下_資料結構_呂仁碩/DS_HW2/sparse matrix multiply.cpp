#include <iostream>

using namespace std;

class SparseMatrix; //forward declaration

class MatrixTerm{
friend SparseMatrix;
private:
    introw, col, value; // a triple representing a term
};

class SparseMatrix{
public:
    SparseMatrix SparseMatrix;
    SparseMatrix ~SparseMatrix;
    SparseMatrix Transpose();
    SparseMatrix Multiply(SparseMatrix);
//¡K
private:
    int rows, cols, terms, capacity;
    MatrixTerm* smArray;
};

SparseMatrix::SparseMatrix{
:
}


int main()
{

    return 0;
}
