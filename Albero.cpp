#include <iostream>
#include <assert.h>
#include <queue>
#include <cstring>
using namespace std;

enum Direzione{sin=0,des=1};

template<class U>
struct SNodo{
    U vinfo;
    SNodo *ppadre,*pfiglio[2];

    SNodo(const U& inf):vinfo(inf){ppadre=pfiglio[0]=pfiglio[1]=nullptr;}
    ~SNodo(){delete pfiglio[sin]; delete pfiglio[des];}
};

template<class T>
class AlberoB{
    //potrei creare qui SNodo per tenerlo nascosto all'esterno

    protected:
        SNodo<T> *pradice;
    
    public:
        AlberoB():pradice(nullptr){};
        AlberoB(const T& a){pradice=new SNodo<T>(a);}
        void insFiglio(Direzione d, AlberoB<T>& ac);
        bool nullo() const{return pradice==nullptr;}
        bool foglia() const{return !nullo && figlio(sin).nullo() && figlio(des).nullo()}
        AlberoB<T> figlio(Direzione d) const;
        const T& radice() const;
        AlberoB<T> padre() const;
        void modRadice(const T& a);
        AlberoB<T> estraiFiglio(Direzione d);
        AlberoB<T> copia() const;
        void svuota();
        int profondita(AlberoB<T> a);
        bool bilanciato(AlberoB<T> a);
        bool bilanciatoProfondo(AlberoB<T> a, int &p); //calc. bilanciato e profondità insieme
};

template<class T>
void AlberoB<T>::insFiglio(Direzione d, AlberoB<T>& ac){
    if(!ac.nullo()){
        assert(!nullo()); assert(figlio(d).nullo());

        pradice->pfiglio[d]=ac.pradice;
        ac.pradice->ppadre=pradice;
    }
}

template<class T>
AlberoB<T> AlberoB<T>::figlio(Direzione d) const{
    assert(!nullo());
    AlberoB<T> ac;
    ac.pradice=pradice->pfiglio[d];
    return ac;
}

template<class T>
int AlberoB<T>::profondita(AlberoB<T> a){
    if(a.nullo()) return 0;

    int p1=profondita(a.figlio(sin));
    int p2=profondita(a.figlio(des));

    return (p1>p2) ? p1+1 : p2+1;
    /*si traduce in
    if(p1>p2) return p1+1;
    else return p1+1;*/
}

template<class T>
bool AlberoB<T>::bilanciato(AlberoB<T> a){
    if(a.nullo()) return true;

    int p1=profondita(a.figlio(sin));
    int p2=profondita(a.figlio(des));

    return abs(p1-p2)<=1 && bilanciato(a.figlio(sin)) && bilanciato(a.figlio(des));
}



// VISITE SUGLI ALBERI
//
// pre-ordine (anticipata) v-s-d
// post-ordine (posticipata) s-d-v
// simmetrica s-v-d
// per livelli


void visitaSimmetrica(AlberoB<int> a){
    if(a.nullo()) return;

    visitaSimmetrica(a.figlio(sin));    //visita s
    cout<<a.radice()<<" ";              //valuta
    visitaSimmetrica(a.figlio(des));    //visita d
}


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

        //NON FINITO
    }
    
    
    system("pause");
    return 0;
}