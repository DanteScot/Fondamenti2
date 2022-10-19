#include <iostream>
using namespace std;

int main(){
    int a[]={0,1,2,3,4,5};
    auto ia2=a; //int *
    int *p=a;   //le due istruzioni sono identiche
    //ia2=35    //ERRORE

    cout<<ia2<<endl;        //stampa indirizzo
    cout<<*ia2<<endl;       //stampa 0
    cout<<ia2[1]<<endl;     //stampa 1

    ia2++;      //aumento il puntatore in base al tipo così da avere la cella successiva
    cout<<*ia2<<endl;       //stampa 1
    cout<<ia2[1]<<endl;     //stampa 2


    //begin->ritorna l'indirizzo della prima cella dell'array
    //end->ritorna l'indirizzo della prima cella SUCCESSIVA all'ultima dell'array

    auto n=end(a)-begin(a);     //calcolare lunghezza array

    int *beg=begin(a);
    int *last=end(a);

    while (beg!=last)
    {
        cout<<*beg<<" ";
        beg++;
    }
    

    system("pause");
    return 0;
}