/**
 * @file contraste.cpp
 * @brief Ajusta el contraste de una imagen PGM (estiramiento del histograma)
 * @authors Irina Kuzyshyn, Roberto González
 * 
 * Este programa ajusta el contraste de una imagen y toma siete parámetros de entrada:
 * 1. El nombre del programa (por convención).
 * 2. El nombre del archivo de entrada que contiene la imagen PGM original.
 * 3. El nombre del archivo de salida donde se guardará el icono de la imagen.
 * 4. El umbral inferior de la imagen de entrada.
 * 5. El umbral superior de la imagen de entrada.
 * 6. El umbral inferior de la imagen de salida.
 * 7. El umbral superior de la imagen de salida.
 *
 * EG: ~$ ./contraste ./[ArchivosEntrada]/[ImagenEntrada].pmg ./[CarpetaSalida]/[ImagenSalida].pgm e1 e2 s1 s2
 *
 * @param argc Número de argumentos de línea de comandos (debe ser 3).
 * @param argv Arreglo de cadenas que contiene los argumentos de línea de comandos.
 * @return Devuelve 0 si la operación se realizó con éxito, o un valor diferente si hubo un error.
 *
 * @note Este programa escribirá el ajuste del contraste de la imagen de entrada @p argv [1]
 *       en el archivo de salida especificado. @p argv [2]
*/


#include <iostream>
#include "image.h"


using namespace  std;
int main(int argc, char * argv[]){
    char *fich_orig, *fich_rdo;
    byte e1, e2, s1, s2;
    if (argc != 7){
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: contraste <FicheroOrigen> <FicheroDestino> <e1> <e2> <s1> <s2>\n";
        return 1;
    }
    fich_orig = argv[1];
    fich_rdo = argv[2];
    e1 = stoi((string)(argv[3]));
    e2 = stoi((string)(argv[4]));
    s1 = stoi((string)(argv[5]));
    s2 = stoi((string)(argv[6]));

    // Mostramos argumentos
    std::cout << std::endl;
    std::cout << "Fichero origen: " << fich_orig << std::endl;
    std::cout << "Fichero resultado: " << fich_rdo << std::endl;

    Image img_orig;
    if (!img_orig.Load(fich_orig)){
        cerr << "Error en la carga de la imagen desde " << fich_orig << endl;
        return 1;
    }

    // Mostrar los parametros de la Imagen
    cout << endl;
    cout << "Dimensiones de " << fich_orig << ":" << endl;
    cout << "   Imagen   = " << img_orig.get_rows()  << " filas x " << img_orig.get_cols() << " columnas " << endl;

    img_orig.AdjustContrast(e1,e2,s1,s2);
    if (!img_orig.Save(fich_rdo)){
        cerr << "Error en el guardado de la imagen a " << fich_rdo << endl;
        return 1;
    }
    return 0;
}