#include <iostream>
#include<list>
using namespace std;

template<class T>
class CatenaDiMontaggio{
    list<T> cat;

    public:
        void aggiungi(T elemento);
        void rimuovi();
        const T& prossimo() const;
        unsigned int size() const;
};

template<class T>
void CatenaDiMontaggio<T>::aggiungi(T elemento){
    cat.push_back(elemento);
}

template<class T>
void CatenaDiMontaggio<T>::rimuovi(){
    cat.pop_front();
}

template<class T>
const T& CatenaDiMontaggio<T>::prossimo() const{
    return *(cat.begin());
}

template<class T>
unsigned int CatenaDiMontaggio<T>::size() const{
    unsigned sz=cat.size();
    return sz;
}



int main(){
    CatenaDiMontaggio<int> cat;
    cat.aggiungi(50);
    cat.aggiungi(37);
    cat.aggiungi(43);

    cat.rimuovi();

    cout<<cat.size()<<endl;

    cout<<cat.prossimo()<<endl;
    
    system("pause");
    return 0;
}