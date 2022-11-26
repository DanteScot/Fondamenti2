#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int i=0,n,m;

    cin>>n;
    cin>>m;

    unordered_map<int,pair<bool,int>> is_in;
    vector<int> xs(n);
    
    for(int i=0;i<n;i++){
        cin>>xs[i];
        is_in[xs[i]].first=true;
        is_in[xs[i]].second=i;
    }
    
    for(int i=0;i<n;i++){
        int target=m-xs[i];
        if(is_in[target].first && is_in[target].second!=i){
            cout<<"Trovata soluzione: "<<xs[i]<<xs[is_in[target].second]<<endl;
            return 0;
        }
    }

    system("pause");
    return 0;
}