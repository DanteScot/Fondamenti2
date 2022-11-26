// non vengono ereditati:
// costruttore
// distruttore
// operatore =
// amici
// membri privati

class Mother{
    public:
        Mother(){cout<<"Mother: nessun parametro\n";}
        Mother(int a){cout<<"Mother: costruttore con un parametro\n";}
};

class Daughter:public Mother{
    Daughter(int a){cout<<"Daughter: costruttore con un parametro\n";}
};

class Son:public Mother{
    public:
        Son(int a):Mother(a){cout<<"Son: costruttore con un parametro\n";}
};

int main(){
    Daughter kelly(0); //Mother: nessun parametro\n     Daughter: costruttore con un parametro\n
    Son tizio(0); //Mother: costruttore con un parametro\n      Son: costruttore con un parametro\n
}

//una classe può ereditare più classi
class Rettangolo:public Poligono,public Output{};