#include <iostream>
#include <vector>
using namespace std;

struct bin{
    private:
        vector<int> n;
    
    public:
        bin(int l):n(l,0){}
        bool next();

        void stampa(){
            for(int i=0;i<n.size();i++)
                cout<<n[i];
        }
        int operator[](int x) const{return n[x];}
};

bool bin::next(){
    int last=n.size()-1;
    bool esci=false;

    while(!esci){
        if(n[last]==0)
        {
            n[last]=1;
            esci=true;
        }
        else
        {
            n[last]=0;
            last--;

            if(last<0)  return false;
        }
    }
    
    return true;
}

int main(){
    bin prova(4);
    prova.stampa();
    cout<<endl;
    prova.next();
    prova.stampa();
    cout<<endl;
    prova.next();
    prova.stampa();
    
    cout<<endl;
    cout<<endl;
    for (int i = 0; i < 4; i++)
    {
        cout<<prova[i]<<endl;
    }
        
    return 0;
}