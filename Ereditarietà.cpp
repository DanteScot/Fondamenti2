//class nomeEreditaria:specificatori momeclasse{};
//                      public/protected/private

class Poligono{
    protected:
        int base,altezza;
    public:
        void set_values(int a,int b){base=a;altezza=b;}
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
    r.set_values(4,5);
    t.set_values(4,5);
    //r.base EROORE
    cout<<r.area()<<endl;   //20
    cout<<t.area()<<endl;   //10
}