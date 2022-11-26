#ifndef SimmetricMatrix_h
#define SimmetricMatrix_h

#include <iostream>
#include <assert.h>
#include "Matrice.h"
using namespace std;

template<class T>
class SimmetricMatrix:public Matrix<T>{
    using Matrix<T>::rows;  //derivare da classi template dà problemi, usando questa istruzione gli dico quali variabili usare
    //Matrix<T>::rows ogni volta
    //this->rows stessa cosa
    using Matrix<T>::cols;
    using Matrix<T>::mat;

    public:
        SimmetricMatrix(int _rows, const T& initial);
        T& operator()(int row,int col);
}

SimmetricMatrix::SimmetricMatrix(int _rows, const T& initial){
    rows=cols=_rows;
    mat.resize(_rows);
    for(int i=0;i<_rows;i++){
        mat[i].resize(i+1,initial);
    }
}

T& SimmetricMatrix::operator()(int row,int col){
    assert(row<rows && col<cols);
    if(row<col) return mat[col][row];
    else return mat[row][col];
}


#endif