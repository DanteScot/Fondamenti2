#include<vector>
#include<iostream>
#include<iterator>
#include<cstring>
#include"Dipendenti.h"

class GestoreDipendenti{
    vector<Dipendente> dipendenti;

    public:
        GestoreDipendenti(){};
        GestoreDipendenti(const GestoreDipendenti& gd);
        bool esisteDipendente(string id) const;
        bool aggiungiDipendente(Dipendente d);
        bool rimuoviDipendente(string id);
        //void stampa() const;
        float calcolaCostoDipendenti() const;

        friend ostream& operator<<(ostream& o, const GestoreDipendenti& gd);
};


GestoreDipendenti::GestoreDipendenti(const GestoreDipendenti& gd){
    for(int i=0;i<gd.dipendenti.size();i++)
        dipendenti.push_back(gd.dipendenti[i]);
}

bool GestoreDipendenti::esisteDipendente(string id) const{
    for(int i=0;i<dipendenti.size();i++)
        if(dipendenti[i].get_id()==id)    return true;
    
    return false;
}

bool GestoreDipendenti::aggiungiDipendente(Dipendente d){
    if(!this->esisteDipendente(d.get_id())){    //se non esiste il dipendente lo aggiunge
        dipendenti.push_back(d);
        return true;
    }
    else return false;
}

bool GestoreDipendenti::rimuoviDipendente(string id){
    if(!this->esisteDipendente(id)) return false;
    
    for(int i=0;i<dipendenti.size();i++)
        if(dipendenti[i].get_id()==id)
            dipendenti.erase(dipendenti.begin()+i); //elimina elemento in posizione i
    
    return true;
}

float GestoreDipendenti::calcolaCostoDipendenti() const{
    float tot=0;

    for(int i=0;i<dipendenti.size();i++)    tot+=dipendenti[i].get_stipendio();

    return tot;
}

ostream& operator<<(ostream& o,const GestoreDipendenti& gd){
    for (int i = 0; i < gd.dipendenti.size(); i++)  o<<gd.dipendenti[i]<<"\n";

    return o;    
}


// int main(){
//     Dipendente *foo=new Dipendente("50","pippo","baudo",50);
//     Dipendente *bar=new Dipendente("67","porco","dio",25);
//     Dipendente *baz=new Dipendente("50","cazzo","culo",25);

//     GestoreDipendenti *tmp=new GestoreDipendenti;

//     cout<<tmp->aggiungiDipendente(*foo)<<endl;
//     cout<<tmp->aggiungiDipendente(*bar)<<endl;
//     cout<<tmp->aggiungiDipendente(*baz)<<endl;

//     GestoreDipendenti *gd=new GestoreDipendenti(*tmp);

//     cout<<endl;

//     cout<<gd->esisteDipendente("50")<<endl;
//     cout<<gd->esisteDipendente("80")<<endl;
//     cout<<gd->esisteDipendente("67")<<endl;

//     /*cout<<endl;

//     cout<<gd->rimuoviDipendente("50")<<endl;
//     cout<<gd->rimuoviDipendente("80")<<endl;
//     cout<<gd->rimuoviDipendente("67")<<endl;*/

//     cout<<endl;

//     cout<<gd->calcolaCostoDipendenti()<<endl;

//     cout<<endl;

//     cout<<*gd<<endl;

//     system("pause");
//     return 0;
// }