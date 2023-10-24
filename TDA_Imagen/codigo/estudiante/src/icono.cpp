/**
* @file icono.cpp
 * @brief Calcula el icono de una imagen PGM
 * @authors Irina Kuzyshyn, Roberto Gonzalez
*/

#include <iostream>
#include <cstring>
#include "image.h"

int main(int argc, char *argv[]){
//Filenames of origin and destination
    char *fich_orig, *fich_rdo;
    int factor;
    //Check the number of arguments
    if (argc != 4){
        std::cerr << "Error: Numero incorrecto de parametros.\n";
        std::cerr << "Uso: icono <FicheroOrigen> <FicheroDestino>\n";
        return 1;
    }

    fich_orig = argv[1];
    fich_rdo = argv[2];
    factor = stoi((std::string)(argv[3]));

    Image img_orig;
    if (!img_orig.Load(fich_orig)){
        std::cerr << "Error en la carga de la imagen desde " << fich_orig << std::endl;
        return 1;
    }
    Image img_res = img_orig.Subsample(factor);
    if (!img_res.Save(fich_rdo)){
        std::cerr << "Error en el guardado de la imagen a " << fich_rdo << std::endl;
        return 1;
    }
    return 0;
}