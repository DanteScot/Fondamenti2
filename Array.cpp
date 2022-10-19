#include <iostream>
using namespace std;

int main(){
    //tipo nome[dimensione];
    /*solitamente la dimensione è una costante per garantire retrocompatibilità,
    dim da input non funziona su compilatori vecchi*/

    const unsigned sz=3;    //numero senza segno
    int a1[sz]={0,1,2};
    int a2[]={0,1,2};
    int a3[sz]={0,1,2}; //[0,1,2,default,default] default=0 di solito ma meglio non fare così
    
    //a2=a1; ERRORE
    
    
    system("pause");
    return 0;
}