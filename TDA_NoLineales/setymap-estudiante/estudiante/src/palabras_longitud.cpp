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


    Dictionary dic;
    string palabra;
    ifstream file;
    file.open(argv[1]);

    //abrir fichero
    if (!file) {
        cerr << "Error en la apertura del fichero" << endl;
        return 1;
    }

    //Insertar palabras en el diccionario
    while (file >> palabra) {
        dic.insert(palabra);
    }

    file.close();

    vector<string> words = dic.wordsOfLength(atoi(argv[2]));

    for (auto& word : words) {
        cout << word << endl;
    }


}