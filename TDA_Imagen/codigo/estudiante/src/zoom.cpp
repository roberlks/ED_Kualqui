/**
 * @file zoom.cpp
 * @brief Recorta una imagen PGM
 * @authors Irina Kuzyshyn, Roberto Gonzalez
 *
 * Este programa hace zoom a una imagen y toma 6 parametros de entrada
 * 1. El nombre del programa (por convención).
 * 2. El nombre del archivo de entrada que contiene la imagen PGM original.
 * 3. El nombre del archivo de salida donde se guardará la imagen PGM recortada.
 * 4. La fila donde empieza el zoom
 * 5. La columna donde empieza el zoom
 * 6. El lado de la imagen que recortamos para hacerle zoom a posteriori
 *
 * EG: ~$ ./zoom ./[ArchivosEntrada]/[ImagenEntrada].pmg ./[CarpetaSalida]/[ImagenSalida].pgm fila columna lado
 *
 * @param argc Número de argumentos de línea de comandos (debe ser 6).
 * @param argv Arreglo de cadenas que contiene los argumentos de línea de comandos.
 * @return Devuelve 0 si la operación se realizó con éxito, o un valor diferente si hubo un error.
 *
 * @note Este programa escribirá la imagen aumentada de la imagen de entrada @p argv [1]
 *       en el archivo de salida especificado. @p argv [2] segun los parametros de @p argv [3-5]
 */

#include <iostream>
#include <cstring>
#include <cstdlib>

#include "image.h"

using namespace std;

int main(int argc, char* argv[]){
    //Filenames of origin and destination
    char *origin, *destination;
    Image image;

    //Check the number of arguments
    if (argc != 6){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: zoom <FicheroOrigen> <FicheroDestino> <fila> <col> <side>\n";
        return 1;
    }

    origin = argv[1];
    destination = argv[2];

    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origin << endl;
    cout << "Fichero resultado: " << destination << endl;


    if(!image.Load(origin)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    int row, col, side;
    row = atoi(argv[3]);
    col = atoi(argv[4]);
    side = atoi(argv[5]);

    // Check the preconditions of crop()
    
    if (row < image.get_rows() && col < image.get_cols()){
        side = ((image.get_rows() - row) > side) ? side : (image.get_rows() - row);
        side = ((image.get_cols() - col) > side) ? side : (image.get_cols() - col);
        image = image.Crop(row, col, side, side);
        image = image.Zoom2X();
        // Mostramos que hemos recortado la imagen con exito y le hemos hecho zoom
        cout << "Se ha hecho zoom a la imagen con los parametros establecidos correctamente" << endl;
    }
    else{
        cout << "Se guardara la imagen original, parametros introducidos incorrectos" << endl;
    }
    

    if (image.Save(destination))
        cout  << "La imagen se guardo en " << destination << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    return 0;
}