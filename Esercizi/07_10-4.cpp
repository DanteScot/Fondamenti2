#include <iostream>
using namespace std;

const int n=3;

void riempi(int m[][n]){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>m[i][j];
        }
    }
}

// 4   5   9
// 3   1   2
// 7   4   6

// 3   4   9
// 6   5   7
// 7   4   6


int CalcGrado(const int a[][n],const int b[][n],int i,int j){
    int v[n],w[n],grado=0;
    
    for (int k = 0; k < n; k++)
    {
        v[k]=a[k][i];
        w[k]=b[k][j];
    }

    // cout<<"A:";
    // for (int k = 0; k < n; k++)
    // {
    //     cout<<v[k];
    // }
    // cout<<endl;
    
    // cout<<"B:";
    // for (int k = 0; k < n; k++)
    // {
    //     cout<<w[k];
    // }
    // cout<<endl;
    
    
    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l < n; l++)
        {
            if (v[k]==w[l])
            {
                grado++;
                w[k]=-1;
            }
        }
    }
    
    return grado;
}

void CalcVectJ(const int a[][n],const int b[][n],int v[]){
    for (int i = 0; i < n; i++)
    {
        v[i]=CalcGrado(a,b,i,i);
    }
}


int main(){
    int A[n][n],B[n][n],v[n],i,j;
    cout<<"A:"<<endl;
    riempi(A);
    cout<<"B:"<<endl;
    riempi(B);

    do{
        cout<<"i:";
        cin>>i;
    }while(i<0||i>=n);
    do{
        cout<<"j:";
        cin>>j;
    }while(j<0||j>=n);

    cout<<"grado:"<<CalcGrado(A,B,i,j)<<endl;
    
    CalcVectJ(A,B,v);
    // cout<<endl<<endl<<endl<<endl;
    // for (int k = 0; k < n; k++)
    // {
    //     cout<<v[k]<<endl;
    // }
    

    
    system("pause");
    return 0;
}