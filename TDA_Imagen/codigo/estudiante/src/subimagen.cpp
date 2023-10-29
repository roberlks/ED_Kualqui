/**
 * @file subimagen.cpp
 * @brief Recorta una imagen PGM
 * @authors Irina Kuzyshyn, Roberto Gonzalez
 *
 * Este programa recorta una imagen y toma 7 parametros de entrada
 * 1. El nombre del programa (por convención).
 * 2. El nombre del archivo de entrada que contiene la imagen PGM original.
 * 3. El nombre del archivo de salida donde se guardará la imagen PGM recortada.
 * 4. La fila donde empieza el recorte.
 * 5. La columna donde empieza el recorte.
 * 6. Las filas de la imagen recortada, la altura.
 * 7. Las columnas de la imagenn recortada, la anchura.
 *
 * EG: ~$ ./subimagen ./[ArchivosEntrada]/[ImagenEntrada].pmg ./[CarpetaSalida]/[ImagenSalida].pgm fila columna altura anchura
 *
 * @param argc Número de argumentos de línea de comandos (debe ser 7).
 * @param argv Arreglo de cadenas que contiene los argumentos de línea de comandos.
 * @return Devuelve 0 si la operación se realizó con éxito, o un valor diferente si hubo un error.
 *
 * @note Este programa escribirá la imagen recortada de la imagen de entrada @p argv [1]
 *       en el archivo de salida especificado. @p argv [2] segun los parametros de @p argv [3-6]
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
    if (argc != 7){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: subimagen <FicheroOrigen> <FicheroDestino> <fila> <columna> <filasSubimagen> <columnasSubimagen>\n";
        return 1;
    }

    origin = argv[1];
    destination = argv[2];

    //! no se si esto es necesario
    // Mostramos argumentos
    cout << endl;
    cout << "Fichero origen: " << origin << endl;
    cout << "Fichero resultado: " << destination << endl;


    if(!image.Load(origin)){
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    
    int row, col, rows_sub, cols_sub;
    row = atoi(argv[3]);
    col = atoi(argv[4]);
    rows_sub = atoi(argv[5]);
    cols_sub = atoi(argv[6]);

    if (row < image.get_rows() && col < image.get_cols()){
        rows_sub = ((image.get_rows() - row) > rows_sub) ? rows_sub : (image.get_rows() - row);
        cols_sub = ((image.get_cols() - col) > cols_sub) ? cols_sub : (image.get_cols() - col);
        image = image.Crop(row, col, rows_sub, cols_sub);
        // Mostramos que hemos recortado la imagen con exito
        cout << "Se ha recortado la imagen con los parametros establecidos correctamente" << endl;
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