#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Toggetto{int costo, valore;};

bool greaterThan(Toggetto o1, Toggetto o2){
    return (o1.valore/o1.costo)>(o2.valore/o2.costo);
}

vector<bool> knepsack_o1(vector<Toggetto>& oggetti,int CMax){
    int n=oggetti.size();
    sort(oggetti.begin(),oggetti.end(),greaterThan);

    vector<bool> sol(n,false);
    int Cspeso=0;
    for (int i = 0; i < n && Cspeso < CMax; i++)
    {
        if(Cspeso+oggetti[i].costo <= CMax){
            sol[i]=true;
            Cspeso+=oggetti[i].costo;
        }
    }
    return sol;     
}

int main(){
    
    
    system("pause");
    return 0;
}