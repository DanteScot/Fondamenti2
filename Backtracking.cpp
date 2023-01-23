// COLORABILITà DI UNA MAPPA

// assegna 1 colore a ciascuna nazione
// nessuna nazione confinante ha lo stesso colore
// usando al più 3 colori


#include <iostream>
#include <list>
#include <vector>
using namespace std;


//PSEUDO CODICE
//list sol={};
/*bool solve(sol){
    x=min_val;
    while (x<=max_val)
    {
        if(canAdd(x,sol)){
            add(x,sol);

            if(isComplete(sol)) return true;
            else if(solve(sol)) return true;

            remove(x,sol); x=next(x);
        }
        else{
            x=next(x);
        }
    }
    return false;
}*/

//INPUT: Grafo mappe
//SOLUZIONE: Vector<Colori>
//DOMINIO: Rosso, Verde, Blu
    //enum Colori{Rosso=0, Verde=1, Blu=2}

//min_val=0 max_val=2

enum Colori{Rosso=0, Verde=1, Blu=2};

class Grafo{};

struct BTProblem{
    Grafo mappe;
    vector<Colori> sol;

    BTProblem(Grafo g):mappe(g){}

};

void add(Colori x, BTProblem& bt){
    bt.sol.push_back(x);
}
void remove(Colori x, BTProblem& bt){
    bt.sol.pop_back();
}
Colori next(Colori x){
    //return x++;
}

bool canAdd(Colori  x, const BTProblem& bt){
    int size=bt.sol.size();

    for(int i=0;i<size;i++)
        if(bt.mappe(i,size) && bt.sol[i]==x) return false;
    
    return true;
}

bool isComplete(const BTProblem& bt){
    return bt.sol.size()==bt.mappe.n();
}

int main(){
    
    
    system("pause");
    return 0;
}