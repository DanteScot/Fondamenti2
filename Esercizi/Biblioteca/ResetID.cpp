#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream out;
    out.open("IDs.txt");

    string temp;

    for (int i = 1; i < 10000; i++){
        temp=to_string(i);
        while(temp.length()<4){
            temp.insert(temp.begin(),'0');
        }
        out<<temp<<endl;
    }
    


    out.close();

    system("pause");
    return 0;
}