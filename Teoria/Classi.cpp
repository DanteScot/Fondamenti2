// astrazione
// information hiding
// encapsulation
// gerarchie

/*
class nome_classe{
    specificatore1: -> private(interno classe, è la default)/protected(interno e classi derivate)/public(mamma di simone)
        membri -> dati/funzioni(metodi)
    
    specificatore2:
        membri
}*/

#include<iostream>
using namespace std;

class Rettangolo{
    int b,h;

    public:
        Rettangolo();   //si dovrebbe mettere sempre
        Rettangolo(int,int);

        void setH(int); //}  setters
        void setB(int); //}

        int getH();    //}  getters
        int getB();    //}

        int area(){return b*h;};
};


//definire funzioni fuori dall'oggetto
void Rettangolo::setH(int y){
    h=y;
}
int Rettangolo::getH(){
    return h;
}

Rettangolo::Rettangolo(){
    b=h=1;
}
Rettangolo::Rettangolo(int x, int y)
{
    b=x;h=y;
}
/*Rettangolo::Rettangolo(int x, int y):b(x),h=y     preinizializzazione(oggetti negli oggetti)
{
}*/



class Circle{
    double radius;

    public:
        Circle(double r):radius(r){}
        double area(){return radius*radius*3.14;}
};

class Cylinder{
    Circle base;
    double height;

    public:
        Cylinder(double r,double h):base(r),height(h){}
        double volume(){return base.area()*height;}
};




int main(){
    Rettangolo obj(3,4);
    Rettangolo *foo,*bar,*baz;
    foo=&obj;
    bar=new Rettangolo(5,6);
    baz=new Rettangolo[2]{{2,5},{3,6}}; //la {} è opzionale

    cout<<obj.area()<<endl;
    cout<<foo->area()<<endl;
    //cout<<(*foo).area()<<endl;
    cout<<(*bar).area()<<endl;
    cout<<baz[0].area()<<endl;    //baz[i] è un oggetto, non un indirizzo
    cout<<baz[1].area()<<endl;

    delete bar;
    delete []baz;
}