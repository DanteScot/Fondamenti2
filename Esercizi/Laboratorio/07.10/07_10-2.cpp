#include <iostream>
using namespace std;

int const dim=3;

void Riempi(int v[][dim]){
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            cin>>v[i][j];
        }
    }
}

bool TrovaSella(const int m[][dim]){
    bool trovato=false;
    int indRow[dim];

    int min=INT_MAX;

    //INDICE MINIMO RIGA
    for (int i = 0; i < dim; i++)
    {
        min=INT_MAX;
        for (int j = 0; j < dim; j++)
        {
            if(m[i][j]<=min){
                indRow[i]=j;
                min=m[i][j];
            }
        }
    }

    int colonna,max,indMax;
    for(int k=0;k<dim;k++){
        colonna=indRow[k];
        max=INT_MIN;
        indMax=-1;
        for (int i = 0; i < dim; i++)
        {
            if(m[i][colonna]>=max){
                indMax=i;
                max=m[i][colonna];
            }
        }
        if(k==indMax)    trovato=true;
    }

    return trovato;
}

int main(){
    int m[dim][dim];
    Riempi(m);
    
    bool trovato=TrovaSella(m);

    if (trovato)    cout<<"Trovato"<<endl;
    else    cout<<"NON Trovato"<<endl;    
    
    system("pause");
    return 0;
}