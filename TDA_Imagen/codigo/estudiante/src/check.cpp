#include <iostream>
#include <cstring>
#include <cstdlib>

#include "image.h"

using namespace std;

int main(int argc, char *argv[]){
    if (argc != 3){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: check <FicheroIm1> <FicheroIm2>\n";
        return 1;
    }

    Image i1, i2;

    if(!i1.Load(argv[1])){
        cerr << "Error al leer el primer fichero\n";
        return 1;
    }

    if(!i2.Load(argv[2])){
        cerr << "Error al leer el segundo fichero\n";
        return 1;
    }

    cout << (i1 == i1);

    return 0;
}