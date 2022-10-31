//leggere una parola terminata da un punto, determinare se la parola è palindroma
#include <iostream>
using namespace std;

const int maxDim=100;

void leggiParola(char v[],int &dim){
    char c;
    dim=0;
    cin>>c;

    while ((c!='.')&&(dim<maxDim))
    {
        v[dim]=c;
        dim++;
        cin>>c;
    }
}


bool palindroma(char v[],int dim){
    bool trovDiv=false;

    for (int i = 0; i < dim/2 && !isPal; i++)
    {
        if (v[i]!=v[dim-1-i])
        {
            trovDiv
        }
    }
    if(trovDiv) return false;
    else return true;
}


int main(){
    
    
    system("pause");
    return 0;
}