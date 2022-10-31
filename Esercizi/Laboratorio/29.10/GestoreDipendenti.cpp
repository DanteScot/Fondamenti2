#include<vector>
#include<iostream>
#include<iterator>
#include"Dipendenti.h"

class GestoreDipendenti{
    vector<Dipendente> dipendenti;

    public:
        GestoreDipendenti(){};
        GestoreDipendenti(const vector<Dipendente>& vd);
        bool esisteDipendente(string id) const;
        bool aggiungiDipendente(Dipendente d);
        void rimuoviDipendente(string id);
        //void stampa() const;
        float calcolaCostoDipendenti() const;

        friend ostream& operator<<(ostream& o, const GestoreDipendenti& gd);
};


GestoreDipendenti::GestoreDipendenti(const vector<Dipendente>& vd){
    for(int i=0;i<dipendenti.size();i++)
        dipendenti.push_back(vd[i]);
}

bool GestoreDipendenti::esisteDipendente const(string id){
    for(int i=0;i<dipendenti.size();i++)
        if(strcmp(dipendenti[i].get_id(),id)==0)    return true;
    
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
    
    for(int i=0;i<dipendenti.size();i++){
        if(dipendenti[i].get_id()==id){
            dipendenti.erase(dipendenti.begin()+i); //elimina elemento in posizione i
            return true
        }
    }
}

float GestoreDipendenti::calcolaCostoDipendenti() const{
    float tot=0;

    for(int i=0;i<dipendenti.size();i++)    tot+=dipendenti[i].get_stipendio();

    return tot;
}

ostream& operator<<(ostream& o,const GestoreDipendenti& gd){
    for (int i = 0; i < gd.dipendenti.size(); i++)  o<<gd.dipendenti[i]<<endl;

    return o;    
}