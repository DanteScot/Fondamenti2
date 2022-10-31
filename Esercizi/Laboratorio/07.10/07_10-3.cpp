#include <iostream>
using namespace std;

const int dim=5;

int Somma(const int x[],int i){
    if(i==dim)  return 0;

    return x[i]+Somma(x,i+1); 
}

int main(){
    int x[5]={5,3,2,4,1};
    
    cout<<Somma(x,0)<<endl;
    system("pause");
    return 0;
}