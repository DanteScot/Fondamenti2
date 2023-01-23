#include <iostream>
#include <vector>
#include <list>
using namespace std;

//typedef pair<int,pair<int,pair<int,char>>> porcodio;

int main(){
    int* matricola = new int[6] {2,3,0,6,7,3};
    cout << *(&matricola[4]);





    // list<int> x;
    // for(int i=10;i>0;i--){
    //     x.push_back(i);
    // }

    // cout<<endl<<endl<<endl<<endl;

    // x.insert(x.begin(),500);

    // for(list<int>::iterator it=x.begin();it!=x.end();it++){
    //     cout<<*it<<endl;
    // }

    // vector<int> y(x.begin(),x.end());

    // for(int i=0;i<y.size();i++){
    //     cout<<y[i]<<endl;
    // }

    // pair<int,char> x=make_pair(5,'s');
    // x.first=7;
    // x.second='2';
    
    // cout<<x.first<<endl<<x.second;
    
    return 0;
}