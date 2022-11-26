#include <iostream>
#include <stack>
using namespace std;

void Stampa(stack<int> x){
    stack<int> aux;
    int sz=x.size();

    for(int i=0;i<sz;i++){
        aux.push(x.top());
        x.pop();
    }

    cout<<"| ";
    sz=aux.size();
    for(int i=0;i<sz;i++){
        cout<<aux.top()<<" ";
        aux.pop();
    }
}

void StampaRicorsiva(stack<int>& s){
    if(s.empty()) return;

    int x=s.top();
    s.pop();
    StampaRicorsiva(s);
    cout<<x<<" ";
    s.push(x);
}

int main(){
    stack<int> x;
    x.push(5);
    x.push(4);
    x.push(3);
    x.push(2);
    x.push(1);

    
    Stampa(x);


    cout<<endl<<endl;
    int sz=x.size();
    for (int i = 0; i < sz; i++)
    {
        cout<<x.top();
        x.pop();
    }
    
    
    system("pause");
    return 0;
}