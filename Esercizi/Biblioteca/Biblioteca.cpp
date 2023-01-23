#include <iostream>
#include <vector>
using namespace std;


//CLIENTE
class Cliente{
    static int _id_;
    string id, nome, cognome, cf;
    bool noleggio=false;

    string generaId(int x);

    public:
        Cliente(const string& _nome,const string& _cognome,const string& _cf);
        Cliente(const Cliente& c);

        string get_id(){return id;}
        string get_nome(){return nome;}
        string get_cognome(){return cognome;}
        string get_cf(){return cf;}
        bool staNoleggiando(){return noleggio;}

        void set_nome(const string& _nome){nome=_nome;}
        void set_cognome(const string& _cognome){cognome=_cognome;}
        void set_cf(const string& _cf){cf=_cf;}
        void set_noleggio(const bool& b){noleggio=b;}

        friend ostream& operator<<(ostream& o,const Cliente& c);
};

int Cliente::_id_=0;

string Cliente::generaId(int x){
    string temp;

    temp=to_string(x);
    while(temp.length()<4){
        temp.insert(temp.begin(),'0');
    }

    return temp;
}

Cliente::Cliente(const string& _nome,const string& _cognome,const string& _cf){
    _id_++;

    id=generaId(_id_);

    nome=_nome;
    cognome=_cognome;
    cf=_cf;
}
Cliente::Cliente(const Cliente& c){
    id=c.id;
    nome=c.nome;
    cognome=c.cognome;
    cf=c.cf;
    noleggio=c.noleggio;
}

ostream& operator<<(ostream& o,const Cliente& c){
    o<<c.id<<" "<<c.nome<<" "<<c.cognome<<" "<<c.cf<<" "<<c.noleggio;
    return o;
}
//FINE CLIENTE



//INIZIO LIBRO

class Libro{
    static int _id_;
    string id, titolo, autore, editore;
    bool noleggiato=false;

    string generaId(int x);

    public:
        Libro(const string& _titolo,const string& _autore, const string& _editore);
        Libro(const Libro& l);

        string get_id(){return id;}
        string get_titolo(){return titolo;}
        string get_autore(){return autore;}
        string get_editore(){return editore;}
        bool inNoleggio(){return noleggiato;}

        void set_titolo(const string& _titolo){titolo=_titolo;}
        void set_autore(const string& _autore){autore=_autore;}
        void set_editore(const string& _editore){editore=_editore;}
        void set_noleggio(const bool& b){noleggiato=b;}

        friend ostream& operator<<(ostream& o,const Libro& l);
};

int Libro::_id_=0;

string Libro::generaId(int x){
    string temp;

    temp=to_string(x);
    while(temp.length()<4){
        temp.insert(temp.begin(),'0');
    }

    return temp;
}

Libro::Libro(const string& _titolo,const string& _autore, const string& _editore){
    _id_++;

    id=generaId(_id_);

    titolo=_titolo;
    autore=_autore;
    editore=_editore;
}
Libro::Libro(const Libro& l){
    id=l.id;
    titolo=l.titolo;
    autore=l.autore;
    editore=l.editore;
    noleggiato=l.noleggiato;
}

ostream& operator<<(ostream& o,const Libro& l){
    o<<l.id<<" "<<l.titolo<<" "<<l.autore<<" "<<l.editore<<" "<<l.noleggiato;
    return o;
}

//FINE LIBRO




//INIZIO BIBLIOTECA

class Biblioteca
{
    vector<pair<Cliente,Libro>> noleggi;

    public:
        Biblioteca(/* args */);
        ~Biblioteca();
};

Biblioteca::Biblioteca(/* args */)
{
}

Biblioteca::~Biblioteca()
{
}

//FINE BIBLIOTECA




















int main(){
    /*Libro *a=new Libro("porco","di","dio");
    Libro *b=new Libro("mannaia","la","madonna");
    cout<<*a<<endl<<*b<<endl;

    Libro *c=new Libro("porcaccio","il","cristo");

    cout<<*c<<endl;*/


    system("pause");
    return 0;
}