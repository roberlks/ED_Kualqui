/**
 * @file imageop.cpp
 * @brief Fichero con definiciones para el resto de métodos de la clase Image
 */

#include <iostream>
#include <cmath>
#include <image.h>

#include <cassert>

void Image::Invert(){
    for (int i=0; i<this->size(); i++)
        this->set_pixel(i,255-this->get_pixel(i));

}

enum Rango{rango1, rango2, rango3};


void Image::AdjustContrast(byte in1, byte in2, byte out1, byte out2) {
    Rango PixelRange;

    /*
     * e1, e2 = in1, in2 = a,b
     * s1, s2 = out1, out2 = min,max
     *
     * Rangos == 0-e1 -> 0-s1
     *           e1-e2 -> s1,s2
     *           e2-255 -> s2-255
     */


    // Establecer constantes..


    for (int i = 0; i < this->get_rows(); i++){
        for (int j = 0; j < this->get_cols(); j++){
            //Recorrer pixel a pixel, establecer rango y aplicar transformacion
            byte z = this->get_pixel(i,j);

            if (z <= in1){
                PixelRange = Rango::rango1;
            }
            else if (z <= in2){
                PixelRange = Rango::rango2;
            }
            else if (z <= 255){
                PixelRange = Rango::rango3;
            }
            else{
                throw invalid_argument();
                return;
            }// z == this->get_pixel(i,j)


            switch (PixelRange) {
                case Rango::rango1:
                    //do smt
                    break;
                case Rango::rango2:
                    //do smt2
                    break;
                case Rango::rango3:
                    //do smt3
                    break;
                default:
                    //wtf? Aqui no llegas nunca lmao
                    throw invalid_argument();
                    return;

            }
        }
    }

}

void Image::ShuffleRows() { //ARREGLARRRRRRRR CAMBIAR REPRE INTERNA 
    const int p = 9973;
    Image tmp(this->get_rows(), this->get_cols());
    for (int r = 0; r < this->get_rows(); r++) {
        int newr = (r * p) % this->get_rows();
        for (int c = 0; c < this->get_cols(); c++) {
            tmp.set_pixel(r, c, get_pixel(newr, c));
        }
    }
    Copy(tmp);
}