#include <iostream>
using namespace std;

void sistema(int &prec,int &act, int &next){
    prec=act;
    act=next;
    next=NULL;
}

int main(){
    int picchi=0,nDati=0,prec=NULL,act=NULL,next=NULL;

    while (true)
    {
        sistema(prec,act,next);

        cout<<"Giorno "<<nDati+1<<": ";
        cin>>next;

        if (next==-1)   break;

        nDati++;
        if (act>prec && act>next)
        {
            picchi+=1;
            cout<<act<<" "<<nDati-1<<endl;
        }
    }
    
    cout<<"Numero di picchi massimi rilevati: "<<picchi<<endl;
    cout<<"Numero totale dei dati: "<<nDati<<endl;

    system("pause");
    return 0;
}