#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

enum Direzione{sin=0,des=1};

template<class T>
class AlberoB{

};

typedef AlberoB<int> AlberoBint;    //definisco un nome per il casting, utile per evitare problemi


void visitaPerLivelli(AlberoB<int> a){
    if(a.nullo()) return;
    queue<AlberoBint> q;
    q.push(a);

    while(!q.empty()){
        AlberoBint temp=q.front(); q.pop();
        cout<<temp.radice()<<" ";

        if(!temp.figlio(sin).nullo())   q.push(temp.figlio(sin));
        if(!temp.figlio(des).nullo())   q.push(temp.figlio(des));
    }
}

AlberoB<int> cerca(AlberoB<int> a, int v){
    if((a.radice()==v)||(a.nullo())) return a;

    AlberoB<int> tmp=cerca(a.figlio(sin),v);

    if(!tmp.nullo()) return tmp;

    return cerca(a.figlio(des),v);
}



int main(){
    string temp; bool firstline=true;
    AlberoB<int> A(42);

    while (getline(cin,temp))
    {
        if(temp=="-1") break;

        if(firstline){
            int v=stoi(temp);   //stoi -> String TO Int
            A.modRadice(v);
            firstline=false;
            continue;
        }

        int indiceDuePunti=temp.find(":");
        int indiceSpazio=temp.find(" ");

        string sinistra=temp.substr(0,indiceDuePunti);  //substr(partenza(inclusa),nCelle(percorse,esclusa))
        string destra=temp.substr(indiceDuePunti+1,indiceSpazio-indiceDuePunti);

        Direzione d2=sin;

        if(temp[indiceSpazio+1]=='d') d2=des;

        int nuovoNodo=stoi(sinistra);
        int valorePadre=stoi(destra);

        AlberoB<int>
    }
    
    
    system("pause");
    return 0;
}