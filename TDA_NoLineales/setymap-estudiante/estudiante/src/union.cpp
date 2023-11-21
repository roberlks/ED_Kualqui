//
// Created by alquitran on 18/11/23.
//
#include "dictionary.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {


    //Comprobar parametros
    if (argc != 3) {
        cerr << "Error en el numero de parametros" << endl;
        return 1;
    }

    //Leer archivo 1 y archivo 2
    Dictionary dic1;
    Dictionary dic2;
    string palabra;
    ifstream file1;
    ifstream file2;
    file1.open(argv[1]);
    file2.open(argv[2]);

    //Comrpobar que se abren correctamente
    if (!file1 || !file2) {
        cerr << "Error en la apertura del fichero" << endl;
        return 1;
    }

    //Leerlos en los diccionarios
    while (file1 >> palabra) {
        dic1.insert(palabra);
    }
    while (file2 >> palabra) {
        dic2.insert(palabra);
    }

    //Sumar
    Dictionary dic3 = dic1 + dic2;

    //Mostrar
















}