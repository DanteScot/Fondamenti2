#include <iostream>
using namespace std;

//void print(int *x,int dim){
void print(const int x[],int dim){  //se non uso const l'array può essere modificato a livello globale

}

int main(){
    int vect[2]={0,1};
    print(vect,2);
    
    system("pause");
    return 0;
}