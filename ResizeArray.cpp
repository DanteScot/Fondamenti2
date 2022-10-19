#include <iostream>
using namespace std;

const int dim_base=10;


void resize(int *&v,int &capacity,int increment){
    int *temp=new int[capacity+increment];
    for (int i = 0; i < capacity; i++)
    {
        temp[i]=v[i];
    }
    
    delete []v;
    v=temp;
    capacity+=increment;
}

int main(){
    int *elenco=new int[dim_base];
    int size=0,elem,capacity=dim_base;
    
    while (cin>>elem)
    {
        if(size<=capacity)  elenco[size++]=elem;
        else{
            resize(elenco,capacity,dim_base);
            elenco[size++]=elem;
        }
    }
    

    system("pause");
    return 0;
}