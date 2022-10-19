#include <iostream>
using namespace std;

int main(){
    //new e delete servono per allocare e de-allocare spazio in memoria
    
    int *pi=new int(1024);    //creo una nuova cella di memoria contenente int e puntata da pi
    //la parentesi con il valore è opzionale e serve ad assegnare un valore (pi deve sempre essere puntatore)

    //auto p1=new auto(obg);

    delete pi;      //elimino la cella di memoria creata in precedenza  !pi CONTINUA AD ESISTERE!

    /*int i=5;
    delete i;  ERRORE*/

    const int capacity=10;
    int *elenco=new int[capacity];  //creo un array in maniera dinamica
    delete []elenco;
    
    system("pause");
    return 0;
}