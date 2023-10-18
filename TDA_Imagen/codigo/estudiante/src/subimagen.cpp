//TODO el brief del programas

#include <iostream>
#include <cstring>
#include <cstdlib>

#include "image.h"

using namespace std;

int main(int argc, char* argv[]){
    //Filenames of origin and destination
    char *origin, *destination;
    Image image, cropped;

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

    //! Ver si tengo que comprobar que los numeros son numeros validos

    int row, col, rows_sub, cols_sub;
    row = atoi(argv[3]);
    col = atoi(argv[4]);
    rows_sub = atoi(argv[5]);
    cols_sub = atoi(argv[6]);

    cropped = image.Crop(row, col, rows_sub, cols_sub);

    if (image.Save(destination))
        cout  << "La imagen se guardo en " << destination << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }


    return 0;
}