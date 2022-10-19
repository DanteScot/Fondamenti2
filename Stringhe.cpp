#include <iostream>
using namespace std;

int main(){
    char str[10]={'C','+','+','\0'};
    //char str[]="parole a caso"
    char *str2=new char[10];
    cin>>str2;   //nell'array di caratteri puoi usare il cin per tutti gli elementi

    /*con la libreria <cstring> abbiamo molte funzioni
    strlen(p)   strcmp(p1,p2)//comparare stringhe   strcpy(p1,p2)//modificando p1   strcat(p1,p2)//concatena p2 a p1
    
    system("pause");
    return 0;
}