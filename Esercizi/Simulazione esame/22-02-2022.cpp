#include <iostream>
#include <list>
#include <algorithm>
using namespace std;


/*ESERCIZIO 1
void func(char& a, char b){
    char c = a;
    a = b;
    b = c;
}
int main()
{
    char* nome = new char[3]{'k','e','v'};
    //1. La seguente istruzione è corretta? Se sì, cosa stampa?
    cout << *(nome[1]) << endl; //errore
    //2. La seguente istruzione è corretta? Se sì, cosa stampa?
    cout << *(nome + 2) << endl; //v
    //3. La seguente istruzione è corretta? Se sì, cosa stampa?
    char* a = &nome[2];
    cout << *(a - 1) << endl; //e
    //4. Cosa viene stampato dalla seguente porzione di codice?
    char* nome_prof = new char[3]{'m','a','t'};
    func (nome_prof[0], nome_prof[1]);
    cout << nome_prof[0] << " " << nome_prof[1] << endl; //a a
}*/

bool fakeHelp(int i, int j){return (i>j);}
class FakeList:protected list<int>{
    public:
        int getFakeSize() const{return size()*2;}
        void insert(int el){find(begin(),end(),el)!=end() ? push_back(el):push_front(el);}
        void fakeSort(bool s){s ? sort():sort(fakeHelp);}
        void fakeClear(bool c){if(c) clear();}
        void stampa(){for(list<int>::iterator it=begin(); it != end(); ++it)  cout<<*it<<endl;}
};

int main(){
    FakeList f;
    f.insert(5);
    f.insert(7);
    f.insert(6);
    f.insert(5);

    f.stampa();
    cout<<endl<<endl;

    // cout<<f.getFakeSize()<<endl;
    f.fakeSort(true);
    f.stampa();
    cout<<endl<<endl;
    f.fakeSort(false);
    f.stampa();
    // f.fakeClear(false);
    // cout<<f.getFakeSize()<<endl;
}