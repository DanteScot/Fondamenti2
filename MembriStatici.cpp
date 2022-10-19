#include <iostream>
using namespace std;

class Dummy{
    public:
        static int n;
        Dummy(){n++;}
};
int Dummy::n=0;


int main(){
    Dummy a;
    cout<<a.n<<endl;
    cout<<Dummy::n<<endl;

    Dummy b[5]; //n diventa 6
    Dummy *c=new Dummy; //n diventa 7
    
    system("pause");
    return 0;
}