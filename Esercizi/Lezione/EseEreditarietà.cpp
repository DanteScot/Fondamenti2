#include <iostream>
using namespace std;

class Prodotto{
    string id;
    float prezzo;

    public:
        Prodotto(string i, float p):id(i),prezzo(p){}
        friend ostream& operator<<(ostream& o,const Prodotto& p){return p.stampa(o);}
        virtual void stampaPrezzoScontato() const{cout<<prezzo<<endl;}
        virtual ~Prodotto(){}

        string get_id(){return id;}
        float get_prezzo(){return prezzo;}

    protected:
        virtual ostream& stampa(ostream& out) const{out<<"Prodotto: "<<id<<" "<<prezzo;    return out;}
};

class Libro:public Prodotto{
    string titolo, autore;

    public:
        Libro(string id,float prezzo,string t,string a):Prodotto(id,prezzo),titolo(t),autore(a){}
        void stampaPrezzoScontato() const{cout<<get_prezzo()-get_prezzo()*0.3<<endl;}

    protected:
        ostream& stampa(ostream& out) const{out<<"Libro: "<<id<<" "<<prezzo<<" "<<titolo<<" "<<autore;    return out;}
};

class Computer:public Prodotto{
    string modello;

    public:
        Computer(string id,float prezzo,string m):Prodotto(id,prezzo),modello(m){}
        void stampaPrezzoScontato() const{cout<<get_prezzo()-get_prezzo()*0.05<<endl;}
};

int main(){
    Prodotto *p1=new Libro("Id1",10.0,"I promessi sposi","Manzoni");
    Prodotto *p2=new Computer("Id3",700.0,"hp ax8p3");
    p1->stampaPrezzoScontato(); //atteso 7.0 (10-30%)
    p2->stampaPrezzoScontato(); //atteso 665.0 (700-5%)
    cout<<*p1<<endl; //tutto
    cout<<*p2<<endl; //solo id e prezzo
    delete p1;
    delete p2;
    system("pause");
    return 0;
}