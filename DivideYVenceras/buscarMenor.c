#include <iostream>
using namespace std;


int encontrarRotado(int* arr,int ini,int fin) {
    int medio = (ini+fin)/2;
    if (ini==fin) {
        return arr[ini];
    }


    //aqui ya me devuelve el menor del arreglo 
    if (arr[medio] < arr[medio-1]) {
        return   arr[medio];
    }

    //si es mayor que el fin entonces busco por la derecha
    if (arr[medio] > arr[fin]) {
        return encontrarRotado(arr,medio+1,fin);
    }
    else {
        //si es menor que el fin entonces busco por la izquierda
        return encontrarRotado(arr,ini,medio-1);
    }


}

int main() {
                 //0,1,2,3,4,5
    int entrada[]={2,3,4,5,6,1};
    int n= 6;
    int cant=0;

    cout<<"El numero es: "<<encontrarRotado(entrada,0,n-1)<<endl;
    return 0;
}
