#include <iostream>
using namespace std;

int main(){
    int cf=0,cm=0, ct=0;
    int x;

    while (true)
    {
        cin>>x;
        if (x==-1)  break;;
        
        if (x==0)
        {
            if (cf>cm)  cm=cf;
            ct++;
            
            cf=0;
        }else
        {
            cf++;
        }
    }

    cout<<"cardinalitàa' famiglia: "<<ct<<endl;
    cout<<"cardinalita' massima: "<<cm<<endl;

    system("pause");
    return 0;
}