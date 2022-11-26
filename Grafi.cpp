//creo una matrice di bool che mi dice se tra il nodo i e il nodo j esiste un arco
//G(i,j) ? True : False

//liste di adiacenza    [[][3,4][4][][][6][]]

#include <iostream>
#include <vector>
#include <assert.h>
#include <queue>
#include <list>
using namespace std;

class Grafo{
    protected:
        int vn, vm;
        MatriceDiBool archi;
    public:
        Grafo(int n);
        bool operator()(int i, int j) const;
        void operator()(int i, int j, bool b);
        int n() const;
        int m() const;
        //scrivere una funzione che ricevuto un grafo calcoli il grado del nodo
        vector<int> numAdiacenti(const Grafo& g);
        void disorienta(const Grafo& g, Grafo& g1);
        void dfs(int s,const Grafo& g,vector<bool>& visitati);
        vector<int> bfs(const Grafo& g, int s);
        void ricostruisciCammino(int s, int t, const vector<int> p, queue<int>& cammino);
        bool trovaCammino(const Grafo& g, int s, int t, vector<bool>& visitati, list<int>& cammino);
        Grafo chiusuraTransitiva(const Grafo& g);
};

vector<int> Grafo::numAdiacenti(const Grafo& g){
    vector<int> grado(g.n());
    for (int i = 0; i < g.n(); i++)
    {
        grado[i]=0;
        for (int j = 0; j < g.n(); j++)
        {
            if(i!=j && g(i,j)) grado[i]++;
        }
    }
    return grado;
}

void Grafo::disorienta(const Grafo& g, Grafo& g1){
    assert(g.n()==g1.n());
    g1.svuota();
    for (int i = 0; i < g.n(); i++)
    {
        for (int j = 0; j < g.n(); j++)
        {
            if(i!=j && g(i,j)){
                g1(i,j,true);
                g1(i,j,true);
            }
        }
    }
}

void Grafo::dfs(int s,const Grafo& g,vector<bool>& visitati){
    visitati[s]=true;
    for (int j = 0; j < g.n(); j++)
    {
        if(s!=j && g(s,j) && !visitati[j])
            dfs(j,g,visitati);
    }
}

vector<int> Grafo::bfs(const Grafo& g, int s){
    vector<bool> visitati(g.n(),false);
    vector<int> p(g.n(),-1);
    queue<int> q;
    
    q.push(s); visitati[s]=true;

    while (!q.empty())
    {
        int u=q.front(); q.pop();
        for (int v = 0; v < g.n(); v++)
        {
            if(u!=v && g(u,v) && !visitati[v]){
                q.push(v); visitati[v]=true; p[v]=u;
            }
        }
    }
    return p;
}

void Grafo::ricostruisciCammino(int s, int t, const vector<int> p, queue<int>& cammino){
    if(s==t)    cammino.push(s);
    else if(t==-1)  return;
    else{
        ricostruisciCammino(s,p[t],p,cammino);
        cammino.push(t);
    }
}

bool Grafo::trovaCammino(const Grafo& g, int s, int t, vector<bool>& visitati, list<int>& cammino){
    if(s==t){visitati[t]=true; return true;}
    else{
        bool trovato=false;
        for (int j = 0; j < g.n() && !trovato; j++)
        {
            if(s!=j && g(s,j) && !visitati[j]){
                cammino.push_back(j);
                trovato=trovaCammino(g,j,t,visitati,cammino);
                if(!trovato) cammino.pop_back();
            }
        }
        return trovato;
    }
}

Grafo Grafo::chiusuraTransitiva(const Grafo& g){
    Grafo Gc(g.n());
    vector<bool> visitati(g.n());
    for (int i = 0; i < g.n(); i++)
    {
        visitati.assign(visitati.size(),false);
        dfs(i,g,visitati);
        for (int j = 0; j < g.n(); j++)
        {
            if(i!=j && visitati[j]) Gc(i,j,true);
        }
    }
    return Gc;
}

int main(){
    
    
    system("pause");
    return 0;
}