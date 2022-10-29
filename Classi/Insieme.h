#ifndef insieme_h
#define insieme_h

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <iterator>

template<class T>
class Insieme{
    vector<T> s;
    
    public:
        Insieme(){};
        Insieme(const Insieme<T>& set):s(set.s){};
        bool empty() const{return s.size()==0;};
        bool add(const T&);
        bool remove(const T&);
        bool isIn(const T&);
        Insieme<T>& unionTo(const Insieme<T>&);
        Insieme<T>& intersectTo(const Insieme<T>&);
        Insieme<T>& differenceWith(const Insieme<T>&);

        template<class U>   //dato che sarà una funzione esterna non può usare T, ma dovrà avere un template suo
        friend ostream& operator<<(ostream& o,const Insieme<U>& set);
};

template<class T>
bool Insieme<T>::add(const T& e){
    if(find(s.begin(),s.end(),e)!=s.end()) return false;

    s.push_back(e);
    return true;
}

template<class T>
bool Insieme<T>::remove(const T& e){
    auto it=(find(s.begin(),s.end(),e));
    if(it!=s.end()){
        s.erase(it);
        return true;
    }
    return false;
}

template<class T>
bool Insieme<T>::isIn(const T& e){
    if(find(s.begin(),s.end(),e)==s.end()) return false;

    return true;
}

template<class T>
Insieme<T>& Insieme<T>::unionTo(const Insieme<T>& set){
    Insieme<T>* temp=new Insieme<T>(set);
    for (int i = 0; i < s.size(); i++)
        temp->add(s[i]);

    return *temp;
}

template<class T>
Insieme<T>& Insieme<T>::intersectTo(const Insieme<T>& set){
    Insieme<T>* temp=new Insieme<T>;
    for (int i = 0; i < s.size(); i++)
    {
        for(int j=0;j<set.s.size();j++){
            if(s[i]==set.s[j])
                temp->add(s[i]);
        }
    }
    
    return *temp;
}

template<class T>
Insieme<T>& Insieme<T>::differenceWith(const Insieme<T>& set){
    Insieme<T>* temp=new Insieme<T>;
    bool trovato=false;
    
    for (int i = 0; i < s.size(); i++)
    {
        for(int j=0;j<set.s.size();j++){
            if(s[i]==set.s[j])
                trovato=true;
        }
        if(!trovato)
            temp->add(s[i]);
        
        trovato=false;
    }

    for (int i = 0; i < set.s.size(); i++)
    {
        for(int j=0;j<s.size();j++){
            if(set.s[i]==s[j])
                trovato=true;
        }
        if(!trovato)
            temp->add(set.s[i]);
        
        trovato=false;
    }
    
    return *temp;
}

template<class U>
ostream& operator<<(ostream& o,const Insieme<U>& set){
    o<<"{ ";
    for (int i = 0; i < set.s.size(); i++)
    {
        o<<set.s[i]<<" ";
    }
    o<<"}";

    return o;
}


/*int main(){
    Insieme<int> a,b,c;

    cout<<"unione:"<<endl;
    a.add(1);
    a.add(2);
    a.add(3);
    b.add(15);
    b=b.unionTo(a);
    cout<<b<<endl;
    a=b=c;
    
    cout<<"intersezione:"<<endl;
    a.add(1);
    a.add(2);
    a.add(3);
    b.add(2);
    a=a.intersectTo(b);
    cout<<a<<endl;
    a=b=c;

    cout<<"differenza:"<<endl;
    a.add(1);
    a.add(2);
    a.add(3);
    b.add(2);
    b.add(7);
    b.add(8);
    a=a.differenceWith(b);
    cout<<a<<endl;
    
    if(a.isIn(1)){
        cout<<"porco ";
    }
    if(!b.isIn(62)){
        cout<<"dio"<<endl;
    }

    system("pause");
    return 0;
}*/


#endif