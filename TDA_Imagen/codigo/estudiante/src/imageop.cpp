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

//! Ver si lo siguiente esta decente asi
// Las precondiciones las he comprobado de la siguiente manera:
// Si el inicio de la recortada se salia de la original devuelvo una imagen vacia
// Si esta dentro pero se sale por la anchura o altura, la recorto con el mismo inicio 
// pero acabando en los filos de la imagen, aunque la altura o anchura ps es 
// mas pequeña de lo que te pide pero al menos no hay valores extraños
Image Image::Crop(int nrow, int ncol, int height, int width) const{
    Image cropped;
    if (nrow > this->get_rows() || ncol > this->get_cols()){
        return cropped;
    }

    height = ((this->get_rows() - nrow) > height) ? height : (this->get_rows() - nrow);
    width = ((this->get_cols() - ncol) > width) ? width : (this->get_cols() - ncol);
    cropped = Image(height, width);
    
    for (int i = 0; i < height; ++i){
        for (int j = 0; j < width; ++j){
            cropped.set_pixel(i, j, this->get_pixel(i+nrow, j+ncol));
        }
    }

    return cropped;
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