//funzioni hash

//hash map unordered_map    <tipo chiave,tipo valore>

//Tipi di funzioni hash
//Metodo del modulo var % ncella
//Metodo del quadrato centrale - k val bin p ncella - k^2 prendo m bit centrali int inferiore m=log p
//Metodo dell'avvolgimento

#include <unordered_map>
using namespace std;

int main(){
    unordered_map<string,string> mymap;
    mymap["Backery"]="Barbara";

    string name=mymap["Backery"];
    string name=mymap["Terracina"]; //name sarà vuoto e verrà creata la chiave terracina con val vuoto
}