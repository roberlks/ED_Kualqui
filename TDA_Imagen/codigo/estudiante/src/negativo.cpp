/**
 * @file negativo.cpp
 * @brief Calcula el negativo de una imagen PGM
 *
 * Este programa calcula el negativo de una imagen PGM y toma tres parámetros de entrada:
 * 1. El nombre del programa (por convención).
 * 2. El nombre del archivo de entrada que contiene la imagen PGM original.
 * 3. El nombre del archivo de salida donde se guardará la imagen PGM negativa.
 *
 * EG: ~$ ./negativo ./[ArchivosEntrada]/[ImagenEntrada].pmg ./[CarpetaSalida]/[ImagenSalida].pgm
 *
 * @param argc Número de argumentos de línea de comandos (debe ser 3).
 * @param argv Arreglo de cadenas que contiene los argumentos de línea de comandos.
 * @return Devuelve 0 si la operación se realizó con éxito, o un valor diferente si hubo un error.
 *
 * @note Este programa escribirá la imagen negativa  de la imagen de entrada @p argv [0]
 *       en el archivo de salida especificado. @p argv [1]
 */


#include <iostream>
#include <cstring>
#include <cstdlib>

#include "image.h"

using namespace std;

int main (int argc, char *argv[]){
 
  char *origin, *destination; // nombres de los ficheros
  Image image;

  // Comprobar validez de la llamada
  if (argc != 3){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino>\n";
    exit (1);
    //! por que esto es exit y no return 
  }

  // Obtener argumentos
  origin  = argv[1];
  destination = argv[2];

  // Mostramos argumentos
  cout << endl;
  cout << "Fichero origen: " << origin << endl;
  cout << "Fichero resultado: " << destination << endl;

  // Leer la imagen del fichero de entrada
  if (!image.Load(origin)){
    cerr << "Error: No pudo leerse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }

  // Mostrar los parametros de la Imagen
  cout << endl;
  cout << "Dimensiones de " << origin << ":" << endl;
  cout << "   Imagen   = " << image.get_rows()  << " filas x " << image.get_cols() << " columnas " << endl;

  // Calcular el negativo
  image.Invert();

  // Guardar la imagen resultado en el fichero
  if (image.Save(destination))
    cout  << "La imagen se guardo en " << destination << endl;
  else{
    cerr << "Error: No pudo guardarse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    return 1;
  }

  return 0;
}
