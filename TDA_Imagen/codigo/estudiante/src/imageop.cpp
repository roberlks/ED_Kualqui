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
     * Rangos == 0-e1 -> 0-s1u
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
            zoomed.set_pixel(i,j, round(this->Mean(i/2, j/2, i%2+1, j%2+1)));
        }
    }

    return zoomed;
}

void Image::ShuffleRows() {
    const int p = 9973;
    

    byte **tmp_pixels_dir;

    for (int r = 0; r < this->get_rows(); r++) {
        int newr = (r * p) % this->get_rows();
        tmp_pixels_dir[r] = this->img[newr];
    }

    this->img = tmp_pixels_dir;

}

Image Image::Subsample(int factor) const {
    // Verificar si el factor de reducción es válido
    if (factor <= 0) {
        std::cerr<< "Error: Factor de reducción inválido." << std::endl;
        return *this;
    }

    // Calcular las dimensiones de la nueva imagen reducida
    int newRows = rows / factor;
    int newCols = cols / factor;

    // Crear una nueva instancia de la clase Image con las dimensiones calculadas
    Image reducedImage(newRows, newCols);

    // Iterar sobre la nueva imagen y calcular el valor de cada píxel
    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
            // Calcular la posición en la imagen original
            int startRow = i * factor;
            int startCol = j * factor;
            int endRow = startRow + factor;
            int endCol = startCol + factor;

            // Calcular la media de los píxeles en el fragmento utilizando el método Mean
            double meanValue = Mean(startRow, startCol, factor, factor);

            // Redondear la media al entero más cercano
            byte average = static_cast<byte>(std::round(meanValue));
            reducedImage.set_pixel(i, j, average);
        }
    }

    return reducedImage;
}


bool operator==(const Image& i1, const Image& i2){
    int rows1 = i1.get_rows(), rows2 = i2.get_rows(), cols1 = i1.get_cols(), cols2 = i2.get_cols();
    if (rows1 != rows2 || cols1 != cols2) return false;
    for (int i = 0; i < rows1; ++i){
        for (int j = 0; j < cols1; ++j){
            if(i1.get_pixel(i,j) != i2.get_pixel(i,j)) return false;
        }
    } 

    return true;

}