/**
* @file contraste.cpp
 * @brief
 * @return 0 if everything went well, 1 otherwise.
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
    Image img_orig;
    if (!img_orig.Load(fich_orig)){
        cerr << "Error en la carga de la imagen desde " << fich_orig << endl;
        return 1;
    }
    img_orig.AdjustContrast(e1,e2,s1,s2);
    if (!img_orig.Save(fich_rdo)){
        cerr << "Error en el guardado de la imagen a " << fich_rdo << endl;
        return 1;
    }
    return 0;
}