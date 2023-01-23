#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

/*// ESERCIZIO 1

int main()
{
    int* matricola = new int[6]{2,3,0,6,7,3}; //scrivi sul foglio la tua matricola
    
    //1. La seguente istruzione è corretta? Se sì, cosa stampa?
    cout << *(matricola + 3) << *(matricola + 2) << endl;   // 60 

    //2. La seguente istruzione è corretta? Se sì, cosa stampa?
    //cout << *(matricola[0]) << endl;    // errore

    //3. Cosa viene stampato dalla seguente porzione di codice? 
    int& a = matricola[4];
    int b = matricola[5];
    --a;
    b += 1;
    cout << matricola[4] << " " << matricola[5] << endl;    // 63




    //4. Come andrebbe deallocata la memoria dinamica allocata inizialmente?
    
    // //A 
    // for(int i = 0; i < 6; i++)
    // delete matricola[i];
    
    // //B
    // for(int i = 0; i < 6; i++)
    // delete *matricola[i];
    
    // //C
    // Nel main non serve deallocare la memoria dinamica.
    
    //D QUESTA
    delete [] matricola;
}*/







/*// ESERCIZIO 2

class GestoreValori{
    protected:
        vector<pair<int,char>> x;

    public:
        void inserisciCoppia(int a,char b){
            pair<int,char> tmp;
            tmp.first=a;
            tmp.second=b;
            x.push_back(tmp);
        }

        int numCoppie(){
            return x.size();
        }

        virtual int getRisultato(){
            return -1;
        }
};

class GestoreValoriA:public GestoreValori{
    public:
        int getRisultato(){
            int sum=0;
            for(int i=0;i<x.size();i++)
                if(x[i].second=='a')    sum+=x[i].first;
            
            return sum;
        }
};
class GestoreValoriB:public GestoreValori{
    public:
        int getRisultato(){
            int sum=0,count=0;
            for(int i=0;i<x.size();i++)
                if(x[i].second=='b'){
                    sum+=x[i].first;
                    count++;
                }
            
            if(count==0)    return 0;

            return sum/count;
        }
};

int main(){
    GestoreValoriB gs;
    gs.inserisciCoppia(5,'a');
    gs.inserisciCoppia(5,'b');
    gs.inserisciCoppia(6,'b');
    gs.inserisciCoppia(2,'a');
    gs.inserisciCoppia(5,'o');

    cout<<gs.numCoppie()<<endl;
    cout<<gs.getRisultato()<<endl;
}*/







// ESERCIZIO 3

int f(int x, const Grafo& g){
    vector<bool> visitati(g.n(),false);
    queue<int> q;

    q.push(x);
    visitati[x]=true;

    int attuale, nodi=g.n()-1;    //n nodi che non raggiungono il nodo in questione
    while(!q.empty()){
        attuale=q.front();
        q.pop();

        for(int i=0;i<g.n();i++){
            if(i!=attuale && !visitati[i] && g(i,attuale)){
                q.push(i);
                visitati[i]=true;
                nodi--;
            }
        }
    }

    return nodi;
}

int esercizio3(const Grafo& g){
    int val=INT_MIN;    //massima qta di nodi che non raggiungono il nodo in questione
    int nodo=INT_MAX;

    for(int i=0;i<g.n();i++){
        int temp=f(i,g);
        if(temp>val){
            val=temp;
            nodo=i;
        }
    }

    return nodo;
}







/*// ESERCIZIO 4

bool esercizio4(const Grafo& g,int k1, int k2){
    list<int> sol={};
    
    return solve(sol);
}

bool canAdd(int x, list<int> sol,int k1, int k2){
    if(sol.size()>=k2)  return false;

    for(auto it=sol.begin();i!=sol.end();i++){
        if(*it==x)  return false;
    }

    for(int i=0;i<sol.size();i++)
            for(int j=0;j<sol.size();j++)
                if(i!=j && g(i,j))
                    return false;

    return true;
}

bool isComplete(list<int> sol,int k1, int k2){
    if(k1<=sol.size() && sol.size()<=k2) return true;

    return false;
}

bool solve(list<int> sol,int k1, int k2){
    int x=0;
    while (x<g.n())
    {
        if(canAdd(x,sol,k1,k2)){
            sol.push_back(x);
            

            if(isComplete(sol,k1,k2)) return true;
            else if(solve(sol)) return true;

            sol.pop_back(); x++;
        }
        else{
            x++;
        }
    }
    return false;
}*/