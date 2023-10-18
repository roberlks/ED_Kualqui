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
    /*
     * e1, e2 = in1, in2 = a,b
     * s1, s2 = out1, out2 = min,max
     *
     * Rangos == 0-e1 -> 0-s1
     *           e1-e2 -> s1,s2
     *           e2-255 -> s2-255
     */


}

double Image::Mean(int i, int j, int height, int width) const{
    double sum = 0;
    for (int x = i; x < i+height; ++x){
        for (int y = j; y < j+width; ++y){
            sum += this->get_pixel(x,y);
        }
    }
    return sum / (height*width);
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

Image Image::Zoom2X() const{
    int rowsz = this->get_rows()*2-1, colsz = this->get_cols()*2-1;
    Image zoomed(this->get_rows()*2-1, this->get_cols()*2-1);

    for (int i = 0; i < rowsz; ++i){
        for (int j = 0; j < colsz; ++j){
            if (i%2 == 0 && j%2 == 0){
                zoomed.set_pixel(i, j, this->get_pixel(i/2, j/2));
            }
            else{
                zoomed.set_pixel(i,j, round(this->Mean(i/2, j/2, i%2, j%2)));
            }
        }
    }

    return zoomed;
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