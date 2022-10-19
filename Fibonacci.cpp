#include <iostream>
using namespace std;

int F(int x){
    if(x==0) return 0;
    if(x==1) return 1;

    return F(x-1)+F(x-2);
}

int main(){
    int x;
    cin>>x;

    cout<<F(x)<<endl;

    system("pause");
    return 0;
}