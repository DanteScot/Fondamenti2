#include <iostream>
using namespace std;

int somma(int x, int y){
    return x+y;
}

int moltiplicazione(int x, int y){
    int ret=0;
    for (int i = 0; i < y; i++)
    {
        ret=somma(ret,x);
    }
    return ret;    
}

int main(){
    int x,y;
    cout<<"x: ";
    cin>>x;
    cout<<"y: ";
    cin>>y;

    cout<<"somma: "<<somma(x,y)<<endl;
    cout<<"moltiplicazione: "<<moltiplicazione(x,y)<<endl;
    system("pause");

    return 0;
}