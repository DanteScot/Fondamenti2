#include <iostream>
using namespace std;

int mb=0,mt=0,mq=0,mn=0;

bool ricercaLineare(int insieme[],int x,int n){
    //insieme ordinato
    bool trovato=false;
    for (int i = 0; i < n && !trovato && insieme[i]<= x; i++)       //complessità n
    {
        if(insieme[i]==x)   trovato=true;
    }
    return trovato;
}

bool ricercaBinaria(int v[],int x,int in,int fin,int cont){
    if(in>=fin){
        mb+=cont;
        return ((in==fin)&&(x==v[in]));   
    }
    else{
        cont++;
        int medio=(in+fin)/2;
        if(v[medio]<x) in=medio+1;
        else if (v[medio]>x) fin=medio-1;
        else in=fin=medio;
        return ricercaBinaria(v,x,in,fin,cont);
    }
}

int main(){
    int v[]={1,2,3,4,5,6,7,9,10,11};
    int x,cont=0;
    cin>>x;

    cout<<ricercaBinaria(v,x,0,10,cont)<<endl;
    
    system("pause");
    return 0;
}