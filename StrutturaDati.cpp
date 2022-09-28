//tipi di dato definiti dall'utente
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    struct punto{
        int x;
        int y;
    };

    /*punto p1,p2;
    double distance;

    cout<<"punto uno"<<endl;
    cin>>p1.x>>p1.y;
    cout<<"punto due"<<endl;
    cin>>p2.x>>p2.y;

    distance=sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2));
    cout<<distance;
    cin>>p1.x;
    return 0;*/


    punto p1;p1.x=3;p1.y=4;
    punto *pp1=&p1;

    cout<<(*pp1).x<<(*pp1).y<<endl;
    cout<<pp1->x<<pp1->y<<endl;

    cin>>p1.x;
}