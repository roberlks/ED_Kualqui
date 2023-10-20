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

    // Calcular constantes
    // M = (max-min)/(b-a)
    // TODO Peligro con los tipos de las constantes.
    const double M1 = (double)(out1)/(double)(in1);
    const double M2 = (double)(out2-out1)/(double)(in2-in1);
    const double M3 = (double)(255-out2)/(double)(255-in2);

    for (int i=0; i<this->size(); i++){
        byte z = this->get_pixel(i);
        double M;
        byte min, a;
        if (z <= in1){
            M = M1;
            min = 0;
            a = 0;
        }
        else if (z <= in2){
            M = M2;
            min = out1;
            a = in1;
        }
        else{
            M = M3;
            min = out2;
            a = in2;
        }
        this->set_pixel(i, (byte)((round(min + (M*(z-a))))));
    }



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

    byte **tmp_pixels_dir;

    for (int r = 0; r < this->get_rows(); r++) {
        int newr = (r * p) % this->get_rows();
        tmp_pixels_dir[r] = this->get_dir_row(newr);
    }
    this->get_img() = tmp_pixels_dir;
}