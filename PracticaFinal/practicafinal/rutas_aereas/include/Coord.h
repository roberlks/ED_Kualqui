//
// Created by uwu on 27/11/23.
//

#ifndef PRACTICAFINAL_COORD_H
#define PRACTICAFINAL_COORD_H

#include <fstream>

class Coord{
private:
    double latitude; ///< Latitude
    double longitude; ///< Longitude

public:
    /**
     * @brief Constructor (by default or with @a latitude and @a longitude)
     * @param lat Latitude
     * @param lon Longitude
     */
    //! Buscar que hace esto
    explicit Coord(double lat = 0, double lon = 0);

    /**
     * @brief Assign content
     * @param other  
     */
    Coord& operator=(const Coord &other);

    //Getters

    double getLatitude() const;
    double getLongitude() const;

    // Setters

    void setLatitude(double lat);
    void setLongitude(double lon);

    Coord midpoint(const Coord &other) const;

    double orientation(const Coord &other) const;

    bool operator==(const Coord &other) const;
    friend std::istream & operator>>(std::istream & is, Coord & point);
    friend std::ostream & operator<<(std::ostream & is, const Coord & point);
};


#endif //PRACTICAFINAL_COORD_H
