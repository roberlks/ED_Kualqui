//
// Created by uwu on 27/11/23.
//

#ifndef PRACTICAFINAL_COORD_H
#define PRACTICAFINAL_COORD_H

#include <fstream>

class Coord{
private:
    double latitude; ///< Latitude
    double longitude;

public:
    explicit Coord(double lat = 0, double lon = 0);

    Coord(const Coord &other);

    Coord& operator=(const Coord &other);

    const double& Longitude() const;

    const double& Latitude() const;

    double& Longitude();

    double& Latitude();

    Coord midpoint(const Coord &other) const;

    //! Ver como hacer esto bien
    double orientation(const Coord &other) const;

    friend std::istream & operator>>(std::istream & is, Coord & point);
    friend std::ostream & operator<<(std::ostream & is, const Coord & point);
};


#endif //PRACTICAFINAL_COORD_H
