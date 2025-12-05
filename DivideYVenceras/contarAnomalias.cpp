#include <iostream>
using namespace std;

int ContarCentro(int *arr,int ini,int medio,int fin) {

    int size = fin-ini+1;
    int temp[size];

    //copiar a temp
    for (int i=0;i<size;i++) {
        temp[i]=arr[ini+i];
    }
    int izquierda = 0;
    int derecha = medio - ini + 1;
    int contador= 0;

    for (int indice=0;indice<size;indice++) {
        if (derecha<= fin - ini) {
            if (izquierda <= medio-ini) {
                if (temp[izquierda] > temp[derecha]) {

                    contador+=1;
                    arr[ini+indice]=temp[derecha++];
                }
                else {
                    arr[ini+indice]=temp[izquierda++];
                }
            }

        }
        else {
            //solo quedan elementos en izquierda
            arr[ini+indice]=temp[izquierda++];
        }

    }

    return contador;

}

int Contador(int* arr,int ini,int fin) {
    int medio = (ini+fin)/2;

   if (ini>=fin) return 0;

    int izquierda = Contador(arr,ini,medio);
    int derecha =  Contador(arr,medio+1,fin);
    int centro = ContarCentro(arr,ini,medio,fin);

    return izquierda+derecha+centro;





}

int main() {
                 //0  1  2  3  4  5
    int entrada[]={10,12,14,13,11,15};
    int n= 6;
    cout<<"El numero es: "<<Contador(entrada,0,n-1)<<endl;
    return 0;
}

