#include <iostream>
using namespace std;

int busquedaBinaria(int* arr,int ini,int fin) {

  //buscamos la posicion media
    int medio = (ini+fin)/2;

  //cuando llega a pasar entonces devolvemos el valor
    if (ini>fin) {
        return arr[ini];
    }

    //cuando es impar y la siguiente posicon son iguales debe buscar por la izquierda  
    if (medio %2 !=0 and arr[medio] == arr[medio+1]) {
        return busquedaBinaria(arr,ini,medio-1);

    }
    //si buscamos y el medio es par entonces debe buscar por la derecha
    else if (medio %2 ==0 and arr[medio] == arr[medio+1]) {
  
      return busquedaBinaria(arr,medio+1,fin);
    }
  //si es impar y el arreglo anterior es igual, busca por la derecha
    else if ( medio %2 !=0 and arr[medio-1] == arr[medio]) {
        return busquedaBinaria(arr,medio+1,fin);
    }
    else {
        return busquedaBinaria(arr,ini,medio-1);
    }
  


int main() {
                  //0 1  2 3  4  5  6  7  8  9 10
    int entrada[]={1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};

    int n=11;


    int no_repite = busquedaBinaria(entrada,0,n);

    cout<<"el numero que no se repite es "<< no_repite;

    return 0;
}
