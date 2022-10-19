#include <iostream>
using namespace std;

void TowerOfHanoi(int n, char from_rod,char to_rod,char aux_rod){
    if (n==1){
        cout<<"Move disk 1 from "<<from_rod<<" to "<<to_rod<<endl;
        return;
    }

    TowerOfHanoi(n-1,from_rod,aux_rod,to_rod);
    cout<<"Move disk "<<n<<" from "<<from_rod<<" to "<<to_rod<<endl;
    TowerOfHanoi(n-1,aux_rod,to_rod,from_rod);
    return;
}

int main(){
    int n=4;
    TowerOfHanoi(n,'A','C','B');

    system("pause");
    return 0;
}