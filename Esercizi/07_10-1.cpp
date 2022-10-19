#include <iostream>
using namespace std;


void Riempi(int v[],const int dim, int &max){
    for (int i = 0; i < dim; i++)
    {
        cin>>v[i];
        if(v[i]>max)    max=v[i];
    }
}

void StampaScarto(const int v[],const int dim,const int max){
    for (int i = 0; i < dim; i++)
    {
        cout<<v[i]-max<<" ";
    }
    cout<<endl;
}

int main(){
    const int dim=5;
    int max=0;

    int a[dim];
    Riempi(a,dim,max);
    StampaScarto(a,dim,max);
    
    system("pause");
    return 0;
}