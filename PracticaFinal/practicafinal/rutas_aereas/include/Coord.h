/**
 * @file Coord.h
 * @brief Header file for the Coord class.
 *
 * This file declares the Coord class, which is used to represent and manipulate
 * geographic coordinates (latitude and longitude). It includes methods for setting
 * and getting the coordinates, calculating midpoints and orientations, and overloading
 * operators for comparison and I/O operations.
 *
 * @authors Roberto González, Irina Kuzyshyn
 */


#ifndef PRACTICAFINAL_COORD_H
#define PRACTICAFINAL_COORD_H
#include <fstream>

/**
 * @class Coord
 * @brief Class to represent geographic coordinates.
 *
 * This class represents a geographic coordinate with latitude and longitude.
 */
class Coord {
private:
    double latitude; ///< Latitude of the coordinate.
    double longitude; ///< Longitude of the coordinate.

public:
    /**
     * @brief Default constructor or with latitude and longitude.
     * @param lat Latitude.
     * @param lon Longitude.
     */
    explicit Coord(double lat = 0, double lon = 0);

    /**
     * @brief Assignment operator.
     * @param other Coord object to assign.
     * @return Reference to the assigned object.
     */
    Coord& operator=(const Coord &other);

    // Getters

    /**
     * @brief Get the latitude.
     * @return Latitude of the coordinate.
     */
    double getLatitude() const;

    /**
     * @brief Get the longitude.
     * @return Longitude of the coordinate.
     */
    double getLongitude() const;

    // Setters

    /**
     * @brief Set the latitude.
     * @param lat New latitude.
     */
    void setLatitude(double lat);

    /**
     * @brief Set the longitude.
     * @param lon New longitude.
     */
    void setLongitude(double lon);

    /**
     * @brief Calculate the midpoint between this coordinate and another.
     * @param other Another coordinate.
     * @return Coordinate that is the midpoint.
     */
    Coord midpoint(const Coord &other) const;

    /**
     * @brief Calculate the orientation from this coordinate to another.
     * @param other Another coordinate.
     * @return Orientation in radians.
     */
    double orientation(const Coord &other) const;

    /**
     * @brief Compare this coordinate with another.
     * @param other Another coordinate.
     * @return True if they are equal, false otherwise.
     */
    bool operator==(const Coord &other) const;

    /**
     * @brief Input operator to read coordinates.
     * @param is Input stream.
     * @param point Coordinate to read.
     * @return Reference to the input stream.
     */
    friend std::istream & operator>>(std::istream & is, Coord & point);

    /**
     * @brief Output operator to print coordinates.
     * @param os Output stream.
     * @param point Coordinate to print.
     * @return Reference to the output stream.
     */
    friend std::ostream & operator<<(std::ostream & os, const Coord & point);
};

#endif //PRACTICAFINAL_COORD_H
