/**
 * @file Image.h
 * @brief Header file for the Image class.
 *
 * This file declares the Image class, designed for image manipulation and handling.
 * The class provides functionalities for creating, copying, reading, writing, and editing
 * images represented as a 2D array of pixels. It includes operations like overlaying images,
 * extracting sub-images, and modifying individual pixels.
 *
 * @authors Roberto González, Irina Kuzyshyn
 */
#ifndef PRACTICAFINAL_IMAGE_H
#define PRACTICAFINAL_IMAGE_H

#include <iostream>
#include <string>

/**
 * @enum Tipo_Pegado
 * @brief Enumeration for image blending types.
 *
 * Defines the types of blending used when overlaying images.
 */
enum Tipo_Pegado { OPACO, BLENDING };

/**
 * @struct Pixel
 * @brief Structure representing a pixel in an image.
 *
 * Represents a single pixel with red (r), green (g), blue (b) color channels and a transparency channel (transp).
 */
struct Pixel {
    unsigned char r, g, b; ///< Color components: red, green, blue.
    unsigned char transp; ///< Transparency (0 for none, 255 for full).
};

/**
 * @class Image
 * @brief Class representing an image as a 2D array of pixels.
 *
 * This class provides functionalities for image manipulation including reading, writing, and editing individual pixels.
 */
class Image {
private:
    Pixel **data; ///< 2D dynamic array of Pixel structures representing the image.
    int nf, nc; ///< Dimensions of the image: number of rows (nf) and columns (nc).

    /**
     * @brief Deletes the dynamic memory allocated for the image.
     */
    void Borrar();

    /**
     * @brief Copies the content from another Image object.
     * @param I Reference to the Image object to copy from.
     */
    void Copiar(const Image &I);

public:
    /**
     * @brief Constructor to create an image with specified dimensions.
     * @param f Number of rows.
     * @param c Number of columns.
     */
    explicit Image(int f = 0, int c = 0);

    /**
     * @brief Copy constructor.
     * @param I Reference to the Image object to copy.
     */
    Image(const Image &I);

    /**
     * @brief Assignment operator.
     * @param I Reference to the Image object to assign from.
     * @return Reference to the current Image object.
     */
    Image &operator=(const Image &I);

    /**
     * @brief Destructor to free dynamic memory.
     */
    ~Image();

    /**
     * @brief Access operator to get or set a pixel at a specific position.
     * @param i Row index.
     * @param j Column index.
     * @return Reference to the Pixel at the specified position.
     */
    Pixel &operator()(int i, int j);

    /**
     * @brief Constant access operator to read a pixel at a specific position.
     * @param i Row index.
     * @param j Column index.
     * @return Constant reference to the Pixel at the specified position.
     */
    const Pixel &operator()(int i, int j) const;

    /**
     * @brief Writes the image to a file.
     * @param nombre File name to write the image to.
     */
    void EscribirImagen(const char *nombre);

    /**
     * @brief Reads an image from a file, optionally with a mask.
     * @param nombre File name of the image to read.
     * @param nombremascara File name of the mask image (optional).
     */
    void LeerImagen(const char *nombre, const std::string &nombremascara = "");

    /**
     * @brief Clears the transparency of all pixels in the image.
     */
    void LimpiarTransp();

    /**
     * @brief Returns the number of rows in the image.
     * @return Number of rows.
     */
    int num_filas() const { return nf; }

    /**
     * @brief Returns the number of columns in the image.
     * @return Number of columns.
     */
    int num_cols() const { return nc; }

    /**
     * @brief Overlays another image onto this image at a specified position.
     * @param posi Row position to start overlay.
     * @param posj Column position to start overlay.
     * @param I Image to overlay.
     * @param tippegado Type of blending to use.
     */
    void PutImagen(int posi, int posj, const Image &I, Tipo_Pegado tippegado = OPACO);

    /**
     * @brief Extracts a sub-image from this image.
     * @param posi Row position to start extraction.
     * @param posj Column position to start extraction.
     * @param dimi Number of rows to extract.
     * @param dimj Number of columns to extract.
     * @return Extracted sub-image.
     */
    Image ExtraeImagen(int posi, int posj, int dimi, int dimj);
    /**
     * @brief Rotates the image by a specified angle.
     *
     * This function rotates the current image by a given angle (in radians), first calculating the new dimensions
     * of the resulting image to avoid information loss. The rotation is performed around the image's coordinate origin,
     * and the image content is adjusted to keep all pixels within the bounds of the new image.
     *
     * @param angulo The angle of rotation in radians. Positive values indicate counterclockwise rotation.
     * @return A new image that is the rotated version of the original image.
     */
    Image Rota(double angulo) const;
};

#endif //PRACTICAFINAL_IMAGE_H
