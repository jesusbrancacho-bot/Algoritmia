#include <iostream>
using namespace std;


int buscarCarie(int *entrada,int ini,int fin) {
    if (ini >= fin) {
        return entrada[ini];
    }

    int medio = (ini+fin)/2;
    int bloque = medio - (medio%4);
    bool bloque_completo = false;

    if (bloque+2<= fin and  entrada[bloque] == entrada[bloque+1] and entrada[bloque+1]==entrada[bloque+2] and entrada[bloque+2]==entrada[bloque+3]) {
        bloque_completo = true;
    }


    if (bloque_completo) {
        return buscarCarie(entrada,bloque+4,fin);

    }
    else {
        return buscarCarie(entrada,ini,bloque);
    }
}



int main() {
    //0  1  2  3  4  5
    int entrada[]={

        1,1,1,1,
        2,2,2,2,
        3,
        4,4,4,4,
        5,5,5,5,    //20 + 0 / 2 = 10
        7,7,7,7,
    };
    int n= 21;
    cout<<"El numero es: "<<buscarCarie(entrada,0,n-1)<<endl;


    return 0;
}

