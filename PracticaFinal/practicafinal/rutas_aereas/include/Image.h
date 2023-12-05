//
// Created by alquitran on 28/11/23.
//

#ifndef PRACTICAFINAL_IMAGE_H
#define PRACTICAFINAL_IMAGE_H

#include <iostream>
#include <string>


enum Tipo_Pegado {OPACO, BLENDING};
using namespace std;
struct Pixel{
    unsigned char r,g,b;
    unsigned char transp; //0 no 255 si
};
class Image{
private:
    Pixel ** data;
    int nf,nc;
    void Borrar();
    void Copiar(const Image &I);

public:
    Image();

    Image(int f,int c);

    Image(const Image & I);

    Image & operator=(const Image & I);

    ~Image();

    //set y get
    Pixel & operator ()(int i,int j);

    const Pixel & operator ()(int i,int j)const;

    void EscribirImagen(const char * nombre);

    void LeerImagen (const char *nombre,const string &nombremascara="");
    void LimpiarTransp();
    int num_filas()const{return nf;}
    int num_cols()const{return nc;}
    void PutImagen(int posi,int posj, const Image &I,Tipo_Pegado tippegado=OPACO);
    Image ExtraeImagen(int posi,int posj,int dimi,int dimj);
};

#endif //PRACTICAFINAL_IMAGE_H
