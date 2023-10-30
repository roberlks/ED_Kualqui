/**
 * @file icono.cpp
 * @brief Calcula el icono de una imagen PGM
 * @authors Irina Kuzyshyn, Roberto Gonzalez
 * 
 * Este programa calcula el icono de una imagen y toma cuatro parámetros de entrada:
 * 1. El nombre del programa (por convención).
 * 2. El nombre del archivo de entrada que contiene la imagen PGM original.
 * 3. El nombre del archivo de salida donde se guardará el icono de la imagen.
 * 4. El factor con el que se reduce la imagen.
 *
 * EG: ~$ ./icono ./[ArchivosEntrada]/[ImagenEntrada].pmg ./[CarpetaSalida]/[ImagenSalida].pgm factor
 *
 * @param argc Número de argumentos de línea de comandos (debe ser 3).
 * @param argv Arreglo de cadenas que contiene los argumentos de línea de comandos.
 * @return Devuelve 0 si la operación se realizó con éxito, o un valor diferente si hubo un error.
 *
 * @note Este programa escribirá el icono de la imagen de entrada @p argv [1]
 *       en el archivo de salida especificado. @p argv [2]
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
        std::cerr << "Uso: icono <FicheroOrigen> <FicheroDestino> <Factor>\n";
        return 1;
    }

    fich_orig = argv[1];
    fich_rdo = argv[2];
    factor = stoi((std::string)(argv[3]));

    // Mostramos argumentos
    std::cout << std::endl;
    std::cout << "Fichero origen: " << fich_orig << std::endl;
    std::cout << "Fichero resultado: " << fich_rdo << std::endl;


    Image img_orig;




    if (!img_orig.Load(fich_orig)){
        std::cerr << "Error en la carga de la imagen desde " << fich_orig << std::endl;
        return 1;
    }

    // Mostrar los parametros de la Imagen
    std::cout << std::endl;
    std::cout << "Dimensiones de " << fich_orig << ":" << std::endl;
    std::cout << "   Imagen   = " << img_orig.get_rows()  << " filas x " << img_orig.get_cols() << " columnas " << std::endl;
    if (factor <= 0){
        std::cerr << "Error: El factor de submuestreo debe ser mayor que 0.\n";
        img_orig.Save(fich_rdo);
        return 1;
    }
    Image img_res = img_orig.Subsample(factor);
    if (!img_res.Save(fich_rdo)){
        std::cerr << "Error en el guardado de la imagen a " << fich_rdo << std::endl;
        return 1;
    }
    return 0;
}