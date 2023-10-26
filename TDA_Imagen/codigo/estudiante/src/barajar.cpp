/**
* @file barajar.cpp
 * @brief Baraja una imagen PGM (por filas)
*/

#include <iostream>
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
    if (argc == 4){
        prime = stoi((string)(argv[3]));
    }
    //Check if prime is a prime number
    bool is_prime = isPrime(prime);

    //Open image
    Image img_orig;
    if (!img_orig.Load(fich_orig)){
        cerr << "Error en la carga de la imagen desde " << fich_orig << endl;
        return 1;
    }
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