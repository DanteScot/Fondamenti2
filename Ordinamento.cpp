#include <iostream>
using namespace std;


void bubbleSort(int a[],int n){
    bool scambi;
    int x=n,lastswap;
    do{
        scambi=false;
        for (int i = 0; i < x-1; i++)
        {
            if (a[i]>a[i+1])
            {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                scambi=true;
                lastswap=i;
            }
            x=lastswap;
        }
    }while (scambi);
}

void selectionSort(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        int min=i;
        for (int j = i; j < n; j++)
        {
            if(a[j]<a[min]) min=j;
        }
        int temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
}

void insertionSort(int a[],int n){
    for (int i = 1; i < n; i++)
    {
        int temp=a[i];
        int j=i-1;
        while (j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

//counting/integer Sort


//I DUE ORDINAMENTI PIù EFFICIENTI
void mergeSort(int v[],int in,int fin){ //n log n
    if(fin-in<20) insertionSort(v,fin);
    else
    {
        int medio=(in+fin)/2;
        mergeSort(v,in,medio);
        mergeSort(v,medio+1,fin);
        merge(v,in,fin,medio);
    }
    
}
void merge(int v[],int in,int fin,int medio){
    int a[fin-in];
    int i1=in,i2=medio+1,i3=0;
    while (i1<=medio && i2<=fin)
    {
        if(v[i1]<v[i2]){
            a[i3]=v[i1];
            i1++;
            i3++;
        }
        else
        {
            a[i3]=v[i2];
            i2++;
            i3++;
        }
    }

    while(i1<=medio){
        a[i3]=v[i1];
        i1++;
        i3++;
    }
    while (i2<=fin)
    {
        a[i3]=v[i2];
        i2++;
        i3++;
    }
    
    for(i3=0,i1=in;i1<=fin;i1++,i3++) v[i1]=a[i3];
}

void quickSort(int v[],int in,int fin){ //mediamente n log n
    if(fin-in<20) insertionSort(v,fin);
    else
    {
        int posOrd=partizione(v,in,fin);
        quickSort(v,in,posOrd-1);
        quickSort(v,posOrd+1,fin);
    }
}
int partizione(int v[],int in,int fin){
    int i=in,j=fin+1;
    while (i<j)
    {
        do j--; while(v[in]<v[j]);
        do i++; while(v[in]>=v[i] && i<j);

        if(i<j) scambia(v[i],v[j]);
    }
    scambia(v[in],v[j]);
    return j;
}

int main(){
    
    
    system("pause");
    return 0;
}