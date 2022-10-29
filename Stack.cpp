#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string expr;
    int len,pos;
    stack<int> s;

    getline(cin,expr);
    len=expr.sieze();

    for(int i=0;i<len && !esci;i++){
        if(expr[i]=='(') s.push(i);
        else if(expr[i]==')')
            if(s.empty())
                esci=true;
            else{
                pos=s.top();
                s.pop();
                cout<<"la parentesi in "<<pos<<"si chiude in "<<i<<endl;
            }  
    }

    if((esci==true)||(!s.empty()))
        cout<<"non ben parentesizata";
    else
        cout<<"ben parentesizzato";
}