//class nomeEreditaria:specificatori momeclasse{};
//                      public/protected/private

#include<vector>

class Poligono{//classe astratta perché ho una funzione virtuale pura => non posso definire oggetti di tipo poligono ma posso definire un puntatore a poligono
    protected:
        int base,altezza;
    public:
        void set_values(int a,int b){base=a;altezza=b;}
        virtual int area() = 0; //in questo modo prevedo una funzione area ma non ne definisco il comportamento(funzione virtuale pura)
}

class Rettangolo:public Poligono{   //public indica il massimo livello di visibilità dei dati ereditati es.protected=public->protected
    public:
        int area(){return base*altezza;}
}

class Triangle:public Poligono{
    public:
        int area(){return (base*altezza)/2;}
}

int main(){
    Rettangolo r;
    Triangle t;
    /*r.set_values(4,5);
    t.set_values(4,5);
    //r.base EROORE
    cout<<r.area()<<endl;   //20
    cout<<t.area()<<endl;   //10*/
    Poligono *pp1=&r;
    Poligono *pp2=&t;
    pp1->set_values(4,5);
    pp2->set_values(4,5);

    cout<<pp1->area();// funziona solo perché area è presente in poligono come virtuale e overloadata in rettangolo 

    vector<Poligono*> pl;// in questo modo posso "inserire" nel vettore triangoli rettangoli o qualsiasi altra classe derivata da poligono
}