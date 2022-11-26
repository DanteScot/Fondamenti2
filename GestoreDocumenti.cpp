#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Documento{
    protected:
        string proprietario,descrizione;
        int dimFile;
    
    public:
        string get_proprietario(){return proprietario;}
        string get_descrizione(){return descrizione;}
};

class DocumentoPDF:public Documento{
    bool sign=false;
};

class DocumentoMP3:public Documento{
    float duration=0;
};

class GestoreDocumenti{
    list<Documento*> gd;
    bool check(string x, string y){return x<y}

    public:
        void aggiungiDocumento(Documento* d){gd.push_back(d);}
        void rimuoviDocumento(Documento* d);
        void stampaDocumenti() const;
        void ordinaDocumenti(int val);
}

void GestoreDocumenti::rimuoviDocumento(Documento *d){
    for(List<Documento*>::iterator it=gd.begin();it!=gd.end();it++){
        if(*it==d) gd.erase(it);
    }
}

void GestoreDocumenti::stampaDocumenti() const{
    for(List<Documento*>::iterator it=gd.begin();it!=gd.end();it++){
        cout<<it->get_proprietario()<<" "<<it->get_descrizione()<<endl;
    }
}

void GestoreDocumenti::ordinaDocumenti(int val){
    switch (val)
    {
    case 1:
        gd.sort(gd.begin(),gd.end(),check);
        break;
    case 2:
        gstjkng
        break;
    case 3:
        gstjkng
        break;
    
    default:
        break;
    }
}

int main(){
    
    
    system("pause");
    return 0;
}