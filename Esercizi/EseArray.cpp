#include <iostream>
using namespace std;

const int dim=10;

int main(){
    int a[dim];
    cout<<"Inserire "<<dim<<" elemnti"<<endl;

    for (int i = 0; i < dim; i++)
    {
        cin>>a[i];
    }

    for(auto i: a){
        cout<<i<<" ";
    }
    cout<<endl;
    
    
    system("pause");
    return 0;
}