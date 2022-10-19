#include <iostream>
using namespace std;

class CVector{
    int x,y;
    public:
        CVector(){}
        CVector(int a, int b):x(a),y(b){}
        CVector operator + (const CVector &param);  //tipo operator simbolo (eventuali parametri)
        CVector operator = (const CVector &param);

        friend ostream &operator << (ostream &os,const CVector &v);
        friend istream &operator >> (istream &is,CVector &v);   //creo un amico che può accedere alle var private
        //friend CVector operator+(const CVector &lhs,const CVector &rhs);
};

CVector CVector::operator+(const CVector &param){
    CVector temp;
    temp.x=x+param.x;
    temp.y=y+param.y;
    return temp;    //copia superficiale
}

/*CVector operator+(const CVector &lhs,const CVector &rhs){   //funziona solo se x e y sono pubblici
    CVector temp;
    temp.x=lhs.x+rhs.x;
    temp.y=lhs.y+rhs.y;
    return temp;
}*/

CVector CVector::operator = (const CVector &param){
    x=param.x;
    y=param.y;
    return *this;
}

ostream &operator << (ostream &os,const CVector &v){
    os<<"["<<v.x<<","<<v.y<<"]";
    return os;
}
istream &operator >> (istream &is,CVector &v){
    is>>v.x>>v.y;
    return is;
}

int main(){
    CVector foo(3,1),bar(1,2),result;
    result=foo+bar; //[4,3]
    cout<<result<<endl;
    
    system("pause");
    return 0;
}