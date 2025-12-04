#include <iostream>
using namespace std;


int contarCeros(int* arr,int ini,int fin,int contador) {

  //salida
    if (ini>fin) {
        return contador;
    }

  //posicion media
    int medio = (ini+fin)/2;


  //El arreglo del medio
    if (arr[medio] == 0){
      //va por la izquierda y cuenta que todos los que son de su derecha son 0s
        return   contarCeros(arr,ini,medio-1,contador+fin-medio+1);
    }
    else{
        //va por la derecha
        return contarCeros(arr,medio+1,fin,contador);
    }

}
