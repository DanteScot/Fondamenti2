#include <iostream>
#include <vector>
using namespace std;






/*// ESERCIZIO 4

class triple{
    public:
        char x,y,z;
        triple(const char& _x,const char& _y,const char& _z){x=_x; y=_y; z=_z;}
};

bool canAdd(int x, vector<int>& val){
    for(int i=0; i<val.size(); i++){
        if(val[i]==x)   return false;
    }

    return true;
}

int f(vector<int>& val, const vector<char>& let, char w){
    for(int i=0;i<let.size();i++){
        if(let[i]==w) return val[i];
    }

    return -1;
}

bool isComplete(vector<int>& val, const vector<char>& let, const vector<triple>& C, const int& n){
    if(val.size()!=n) return false;

    bool b1=false,b2=false;

    for(auto t: C){
        b1=b2=false;

        if(f(val,let,t.x)<f(val,let,t.y) && f(val,let,t.y)<f(val,let,t.z)) b1=true;
        if(f(val,let,t.z)<f(val,let,t.y) && f(val,let,t.y)<f(val,let,t.x)) b2=true;

        if(!b1 && !b2) return false;
    }
    return true;
}

bool solve(vector<int>& val, const vector<char>& let, const vector<triple>& C, const int& n){
    int x=1;
    while (x<=n)
    {
        if(canAdd(x,val)){
            val.push_back(x);

            if(isComplete(val,let,C,n)) return true;
            else if(solve(val,let,C,n)) return true;

            val.pop_back(); x++;
        }
        else{
            x++;
        }
    }
    return false;
}


int main(){
    vector<int> val;
    vector<char> let={'a','b','c','d','e'};

    triple A('a','e','d'), B('b','c','d'), C('c','a','b'), D('d','e','c');

    vector<triple> Q={A,B,C,D};

    (solve(val,let,Q,let.size())) ? cout<<"YES" : cout<<"NO";
    
    system("pause");
    return 0;
}*/