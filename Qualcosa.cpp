#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
    vector<string> vs;
    string s;
    while (getline(cin,s)&&s!="end")
        vs.push_back(s);

    sort(vs.begin(),vs.end());
    auto pos=unique(vs.begin(),vs.end());   //sposta tutti i duplicati alla fine e ci ritorna la POS dell'ultimo elemento unico
    vs.erase(pos,vs.end());
    
}