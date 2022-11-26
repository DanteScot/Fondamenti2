#ifndef matrice_h
#define matrice_h

#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

template<class T>
class Matrix{
    protected:
        int rows,cols;
        vector<vector<T>> mat;

    public:
        Matrix(){rows=0;cols=0;}
        Matrix(int _rows,int _cols,const T& initial);
        Matrix(const Matrix<T>& m);
        int rsize(){return rows;}
        int csize(){return cols;}
        virtual void resize(int _rows,int _cols);
        virtual T& operator()(int row,int col){assert(row<rows && col<cols); return mat[row][col];}
        void print();
}

Matrix::Matrix(int _rows,int _cols,const T& initial){
    rows=_rows;
    cols=_cols;
    mat.resize(_rows);
    for(int i=0;i<mat.size();i++)   mat[i].resize(_cols,initial);
}

Matrix::Matrix(const Matrix<T>& m){
    rows=m.rows;
    cols=m.cols;
    mat=m.mat;
}

virtual void Matrix::void resize(int _rows,int _cols){
    rows=_rows;
    cols=_cols;
    mat.resize(_rows);
    for(int i=0;i<mat.size();i++)   mat[i].resize(_cols,initial);
}

void Matrix::print(){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<<(*this)(i,j)<<" ";
        }
        cout<<endl;
    }
}

#endif