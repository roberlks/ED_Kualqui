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


void Image::AdjustContrast(byte in1, byte in2, byte out1, byte out2) {

}

void Image::ShuffleRows() {
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