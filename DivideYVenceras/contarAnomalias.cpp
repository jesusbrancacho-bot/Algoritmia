#include <iostream>
using namespace std;

int ContarCentro(int *arr,int ini,int medio,int fin) {

    //definimos un tamaño que sea del tamaño del otro arreglo
    int size = fin-ini+1;
    int temp[size];

    //copiar a temporal
    for (int i=0;i<size;i++) {
        temp[i]=arr[ini+i];
    }


    //indice relativo de la mitad izquierda
    int izquierda = 0;

    //indice relativo de la mitad derecha
    int derecha = medio - ini + 1;
    int contador= 0;

    
    for (int j=0;j<size;j++) {
        if (derecha<= fin - ini) {
            if (izquierda <= medio-ini) {
                if (temp[izquierda] > temp[derecha]) {

                    contador+=1;
                    arr[ini+j]=temp[derecha++];
                }
                else {
                    arr[ini+j]=temp[izquierda++];
                }
            }
            else{
            
                arr[ini+j] = temp[derecha++];
            }

        }
        else {
            //solo quedan elementos en izquierda
            arr[ini+j]=temp[izquierda++];
        }

    }

    return contador;

}

int Contador(int* arr,int ini,int fin) {
    int medio = (ini+fin)/2;
    
   if (ini>=fin) return 0;
    //PARES ANOMALOS  (3,4)(3,5) (4,5)
    //BUSCAMOS EN LA PRIMERA MITAD 
    //MEDIO = 2


    //  0  1  2
    // [10,12,14]
   int izquierda = Contador(arr,ini,medio);
   
   //   3, 4  ,5   //SOLO 3,4
   // [13, 11, 15]
   int derecha =  Contador(arr,medio+1,fin);
   
   //ahora buscamos en el centro
   int centro = ContarCentro(arr,ini,medio,fin);

   return izquierda+derecha+centro;





}

int main() {
                 //0  1  2  3  4  5
    int entrada[]={10,12,14,13,11,15};
    int n= 6;
    //queremos contar pares anomales arr[i]> arr[j] 
    cout<<"El numero es: "<<Contador(entrada,0,n-1)<<endl;

    
    return 0;
}

