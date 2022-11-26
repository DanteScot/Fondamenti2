#include <iostream>
#include <vector>
using namespace std;

class Cliente{
    string nome,trattamento;
    int durataTrattamento;
    float prezzo;

    public:
        Cliente(const string name,const string something,const int lenghtSomething,const float price);
        int get_durataTrattamento() const{return durataTrattamento;};
        float get_prezzo() const{return prezzo;};

        friend ostream& operator<<(ostream& o,const Cliente& c);
};

Cliente::Cliente(const string name,const string something,const int lenghtSomething,const float price){
    nome=name;
    trattamento=something;
    durataTrattamento=lenghtSomething;
    prezzo=price;
}

ostream& operator<<(ostream& o,const Cliente& c){
    o<<c.nome<<" "<<c.trattamento<<" "<<c.durataTrattamento<<" "<<c.prezzo;

    return o;
}


class Parrucchiere{
    vector<Cliente> clienti;
    int orario;
    float incasso;

    public:
        Parrucchiere(){orario=480;incasso=0;}
        void nuovoCliente();
        bool estraiCliente();
        void prossimoOrario();
        void stampaFila();
        void orarioAttuale();
        void stampaIncasso(){cout<<incasso;}
};

void Parrucchiere::nuovoCliente(){
    string nome,trattamento;
    int durataTrattamento;
    float prezzo;

    cout<<"Nome: ";
    cin>>nome;
    cout<<"Trattamento: ";
    cin>>trattamento;
    cout<<"Durata Trattamento: ";
    cin>>durataTrattamento;
    cout<<"Prezzo: ";
    cin>>prezzo;

    Cliente c(nome,trattamento,durataTrattamento,prezzo);

    clienti.push_back(c);
}

bool Parrucchiere::estraiCliente(){
    if(clienti.empty()) return false;

    orario+=clienti.front().get_durataTrattamento();
    incasso+=clienti.front().get_prezzo();

    clienti.erase(clienti.begin());
    return true;
}

void Parrucchiere::prossimoOrario(){
    int tmp=orario;
    for(int i=0;i<clienti.size();i++)
        tmp+=clienti[i].get_durataTrattamento();
    

    int ora=tmp/60,minuti=tmp%60;
    if(ora<10) cout<<0<<ora<<":";
    else cout<<ora<<":";
    if(minuti<10) cout<<0<<minuti;
    else cout<<minuti;
}

void Parrucchiere::stampaFila(){
    for(int i=0;i<clienti.size();i++)
        cout<<clienti[i];
}

void Parrucchiere::orarioAttuale(){
    int ora=tmp/60,minuti=tmp%60;
    if(ora<10) cout<<0<<ora<<":";
    else cout<<ora<<":";
    if(minuti<10) cout<<0<<minuti;
    else cout<<minuti;
}


int main(){
    int scelta=0;
    bool esci=false;

    Parrucchiere p;
    
    while(!esci){
        system("cls");
        cout<<"Cosa vuoi fare?"<<endl;
        cout<<"1) Nuovo Cliente"<<endl;
        cout<<"2) Estrai Cliente"<<endl;
        cout<<"3) Prossimo Orario"<<endl;
        cout<<"4) Stampa Fila"<<endl;
        cout<<"5) Orario Attuale"<<endl;
        cout<<"6) Stampa Incasso"<<endl;
        cout<<"Altro per uscire\n\n"<<endl;

        cin>>scelta;

        switch (scelta)
        {
        case 1:
            p.nuovoCliente();
            break;
        case 2:
            p.estraiCliente();
            break;
        case 3:
            cout<<"Prossimo orario disponibile: ";
            p.prossimoOrario();
            cout<<endl;
            system("pause");
            break;
        case 4:
            p.stampaFila();
            cout<<endl;
            system("pause");
            break;
        case 5:
            cout<<"Orario attuale: ";
            p.orarioAttuale();
            cout<<endl;
            system("pause");
            break;
        case 6:
            cout<<"Incasso attuale: ";
            p.stampaIncasso();
            cout<<endl;
            system("pause");
            break;
        
        default:
            esci=true;
            break;
        }
    }

    return 0;
}