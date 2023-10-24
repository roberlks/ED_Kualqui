//TODO hacer el brief de este programa

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

    int row, col, side;
    row = atoi(argv[3]);
    col = atoi(argv[4]);
    side = atoi(argv[5]);
    
    //! Ver si tengo que comprobar las precondiciones del crop

    image = image.Crop(row, col, side, side);

    image = image.Zoom2X();

    if (image.Save(destination))
        cout  << "La imagen se guardo en " << destination << endl;
    else{
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    return 0;
}