//riferimenti &
//puntatori *
#include <iostream>
using namespace std;

int main(){
    /*int ival=42;
    int &refval=ival;           //riferimento, cambiando il riferimento cambi l'originale
    refval=2;
    cout<<ival;*/
    
    int *p1,*p2;
    double dp,*dp2;            //serve per avere gli indirizzi di memoria
    int ival=42;
    int *p=&ival;

    cout<<*p<<endl<<p1<<endl<<p2;
    cin>>ival;
}