//leggere array di 10 elementi e un intero x, verificare la presenza di x nell'array

#include <iostream>
using namespace std;

const int dim=10;

bool cerca(const int v[],const int dim,const int x){
    bool trovato=false;

    for(int i=0;i<dim;i++){ //c++ ha la mamma troia ed il foreach non funziona in funzioni diverse
        if (v[i]==x)
        {
            trovato=true;
            break;
        }
    }

    return trovato;
}

int main(){
    int v[dim],x;
    for (int i = 0; i < dim; i++)   cin>>v[i];
    cout<<"Valore da cercare: ";
    cin>>x;

    if (cerca(v,dim,x)) cout<<"Trovato"<<endl;
    else cout<<"NON Trovato"<<endl;
    
    
    
    system("pause");
    return 0;
}