/**
 * @file check.cpp
 * @brief Comprueba si dos imagenes son iguales.
 * @authors Irina Kuzyshyn, Roberto Gonzalez
 *
 * Este programa comprueba que dos imagenes sean iguales y toma tres parámetros de entrada:
 * 1. El nombre del programa (por convención).
 * 2. El nombre del archivo de entrada que contiene la primera imagen a comparar.
 * 3. El nombre del archivo de entrada que contiene la segunda imagen a comparar.
 *
 * EG: ~$ ./check ./[ArchivosEntrada]/[Imagen1Entrada].pmg ./[ArchivoEntrada]/[Imagen2Entrada].pgm
 *
 * @param argc Número de argumentos de línea de comandos (debe ser 3).
 * @param argv Arreglo de cadenas que contiene los argumentos de línea de comandos.
 * @return Devuelve 0 si la operación se realizó con éxito, o un valor diferente si hubo un error.
 *
 * @note Este programa toma las dos imagenes proporcionadas, las compara y muestra si son 
 * iguales o no por pantalla. 
 */

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

    cout << boolalpha << (i1 == i2) << endl;

    return 0;
}