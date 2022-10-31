#ifndef dipendente_h
#define dipendente_h

#include<iostream>
#include<cstring>
using namespace std;

class Dipendente{
    string id,nome,cognome;
    float stipendio;

    public:
        Dipendente(){id=nome=cognome="NULL";stipendio=0;}
        Dipendente(const Dipendente& d){id=d.id;nome=d.nome;cognome=d.cognome;stipendio=d.stipendio;}
        Dipendente(const string& id){this->id=id;nome=cognome="NULL";stipendio=0;}
        Dipendente(const string& id,const string& nome,const string& cognome,const float& stipendio);
        
        string get_id() const {return id;}
        string get_nome() const {return nome;}
        string get_cognome() const {return cognome;}
        float get_stipendio() const {return stipendio;}

        void set_id(const string& x){id=x;}
        void set_nome(const string& x){nome=x;}
        void set_cognome(const string& x){cognome=x;}
        void set_stipendio(const float& x){stipendio=x;}

        friend ostream& operator<<(ostream& o,const Dipendente& set);
};

Dipendente::Dipendente(const string& id,const string& nome,const string& cognome,const float& stipendio){
    this->id=id;
    this->nome=nome;
    this->cognome=cognome;
    this->stipendio=stipendio;
}

ostream& operator<<(ostream& o,const Dipendente& set){
    o<<set.get_id()<<" "<<set.get_nome()<<" "<<set.get_cognome()<<" "<<set.get_stipendio();
    return o;
}



#endif




/*int main(){
    Dipendente *foo,*bar,*baz;
    foo=new Dipendente;
    bar=new Dipendente("0x52");
    baz=new Dipendente("0x80","coglione","merdoso",1250.54);
    
    cout<<*foo<<endl;
    cout<<*bar<<endl;
    cout<<*baz<<endl;

    system("pause");
    return 0;
}*/