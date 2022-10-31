#include<iostream>
using namespace std;

template<class T>
class Calcolatrice{
    T num1,num2;

    public:
        Calcolatrice(const T& x,const T& y){num1=x;num2=y;}
        T somma(){return num1+num2;}
        T sottrazione(){return num1-num2;}
        T moltiplicazione(){return num1*num2;}
        T divisione(){return num1/num2;}
};

int main(){
    int x=5,y=2;
    Calcolatrice<int>* calc=new Calcolatrice(x,y);

    cout<<calc->somma()<<endl;
    cout<<calc->sottrazione()<<endl;
    cout<<calc->moltiplicazione()<<endl;
    cout<<calc->divisione()<<endl;

    system("pause");
    return 0;
}