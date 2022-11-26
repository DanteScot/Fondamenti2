#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int>& s){
    if(s.empty()) return;

    int x=s.top();
    s.pop();
    printStack(s);
    cout<<x<<" ";
    s.push(x);
}

void print_rod_in_order(stack<int> from_rod, stack<int> to_rod, stack<int> aux_rod,char f,char t,char a){
    if(f=='A'){cout<<"A | "; printStack(from_rod); cout<<endl;}
    else if(t=='A'){cout<<"A | "; printStack(to_rod); cout<<endl;}
    else if(a=='A'){cout<<"A | "; printStack(aux_rod); cout<<endl;}

    if(f=='B'){cout<<"B | "; printStack(from_rod); cout<<endl;}
    else if(t=='B'){cout<<"B | "; printStack(to_rod); cout<<endl;}
    else if(a=='B'){cout<<"B | "; printStack(aux_rod); cout<<endl;}

    if(f=='C'){cout<<"C | "; printStack(from_rod); cout<<endl;}
    else if(t=='C'){cout<<"C | "; printStack(to_rod); cout<<endl;}
    else if(a=='C'){cout<<"C | "; printStack(aux_rod); cout<<endl;}
}

void TowerOfHanoi(int n, stack<int>& from_rod, stack<int>& to_rod, stack<int>& aux_rod,char f,char t,char a){
    if(n==1){
        to_rod.push(from_rod.top()); from_rod.pop();
        print_rod_in_order(from_rod,to_rod,aux_rod,f,t,a);
    }

    TowerOfHanoi(n-1,from_rod,aux_rod,to_rod,f,a,t);

    to_rod.push(from_rod.top()); from_rod.pop();
    print_rod_in_order(from_rod,to_rod,aux_rod,f,t,a);

    TowerOfHanoi(n-1,aux_rod,to_rod,from_rod,a,t,f);
}

int main(){
    stack<int> s,d,a;
    int n;

    cin>>n;

    for(int i=n;i>=1;i--) s.push(i);

    cout<<"lo stato iniziale e': \n";
    cout<<"A | "; printStack(s); cout<<endl;
    cout<<"B | "; printStack(a); cout<<endl;
    cout<<"C | "; printStack(d); cout<<endl;

    TowerOfHanoi(n,s,d,a,'A','C','B');
    
    system("pause");
    return 0;
}