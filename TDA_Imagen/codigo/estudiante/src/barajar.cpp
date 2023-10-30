/**
 * @file negativo.cpp
 * @brief Baraja de forma pseudoaleatoria una imagen PGM
 * @authors Irina Kuzyshyn, Roberto Gonzalez
 *
 * Este programa baraja de forma pseudoaleatoria una imagen y toma cuatro parámetros de entrada:
 * 1. El nombre del programa (por convención).
 * 2. El nombre del archivo de entrada que contiene la imagen PGM original.
 * 3. El nombre del archivo de salida donde se guardará la imagen PGM barajada.
 * 4. Opcionalmente un número primo para barajar la imagen.
 *
 * EG: ~$ ./barajar ./[ArchivosEntrada]/[ImagenEntrada].pmg ./[CarpetaSalida]/[ImagenSalida].pgm [primo]
 *
 * @param argc Número de argumentos de línea de comandos (debe ser 3).
 * @param argv Arreglo de cadenas que contiene los argumentos de línea de comandos.
 * @return Devuelve 0 si la operación se realizó con éxito, o un valor diferente si hubo un error.
 *
 * @note Este programa escribirá la imagen barajada de la imagen de entrada @p argv [1]
 *       en el archivo de salida especificado. @p argv [2]
 */

#include <iostream>
#include <stdlib.h>
#include "image.h"

using namespace std;

bool isPrime(int n){
    if (n <= 1){
        return false;
    }
    for (int i = 2; i < n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]){
    // arguments should be img_orig, img_dest, [prime number]
    // [] is optional, if not specified, prime number is 9973

    char *fich_orig, *fich_rdo;
    int prime = 9973;
    //Check the number of arguments
    if (argc != 3 && argc != 4){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: barajar <FicheroOrigen> <FicheroDestino> [prime number]\n";
        return 1;
    }
    fich_orig = argv[1];
    fich_rdo = argv[2];
    bool is_prime = false;

    // Mostramos argumentos
    std::cout << std::endl;
    std::cout << "Fichero origen: " << fich_orig << std::endl;
    std::cout << "Fichero resultado: " << fich_rdo << std::endl;


    if (argc == 4){
        prime = atoi(argv[3]);
        is_prime = isPrime(prime);

    }
    //Check if prime is a prime number

    //Open image
    Image img_orig;
    if (!img_orig.Load(fich_orig)){
        cerr << "Error en la carga de la imagen desde " << fich_orig << endl;
        return 1;
    }

    // Mostrar los parametros de la Imagen
    cout << endl;
    cout << "Dimensiones de " << fich_orig << ":" << endl;
    cout << "   Imagen   = " << img_orig.get_rows()  << " filas x " << img_orig.get_cols() << " columnas " << endl;

    //Shuffle image
    if (is_prime){
        img_orig.ShuffleRows(prime);
    }
    else{
        img_orig.ShuffleRows();
    }

    //Save image
    if (!img_orig.Save(fich_rdo)){
        cerr << "Error en el guardado de la imagen a " << fich_rdo << endl;
        return 1;
    }
    return 0;

}