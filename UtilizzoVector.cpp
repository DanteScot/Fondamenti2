#include<iostream>
using namespace std;
#include ".\\Classi\\vector.h"

int main(){
    Vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    
    for (int i = 0; i < v.size(); i++)
        cout<<v[i];
    

    Vector<char> vc;
    Vector<Vector<int>> m;
    
    system("pause");
    return 0;
}