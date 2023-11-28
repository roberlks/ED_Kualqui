//
// Created by uwu on 27/11/23.
//

#ifndef PRACTICAFINAL_COORD_H
#define PRACTICAFINAL_COORD_H


class Coord{
private:
    double latitude; ///< Latitude
    double longitude;

public:
    Coord(double lat = 0, double lon = 0);

    Coord(const Coord &other);

    ~Coord() = default;

    Coord& operator=(const Coord &other);

    const double& Longitude() const;

    const double& Latitude() const;

    double& Longitude();

    double& Latitude();

    Coord midpoint(const Coord &other) const;

    //! Ver como hacer esto bien
    double orientation(const Coord &other) const;

    bool operator==(const Coord &other) const;
};


#endif //PRACTICAFINAL_COORD_H
