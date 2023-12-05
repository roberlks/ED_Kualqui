//
// Created by uwu on 27/11/23.
//

#include <cmath>
#include "Coord.h"


Coord::Coord(double lat, double lon) : latitude(lat), longitude(lon){}

Coord::Coord(const Coord &other){
    *this = other;
}



Coord& Coord::operator=(const Coord &other){
    this->latitude = other.getLatitude();
    this->longitude = other.getLongitude();

    return *this;
}

double Coord::getLatitude() const{
    return latitude;
}

double Coord::getLongitude() const{
    return longitude;
}

void Coord::setLatitude(double lat){
    this->latitude = lat;
}

void Coord::setLongitude(double lon){
    this->longitude = lon;
}


Coord Coord::midpoint(const Coord &other) const{
    return Coord((this->getLatitude() + other.getLatitude())/2, (this->getLongitude() + other.getLongitude())/2);
}

double Coord::orientation(const Coord &other) const{
    return atan2(other.getLongitude()-this->getLongitude(), other.getLatitude()-this->getLatitude());
}

bool Coord::operator==(const Coord &other) const{
    return (this->getLatitude() == other.getLatitude() && this->getLongitude() == other.getLongitude());
}



//? Te dan los puntos distintos en la ruta y en el pais
std::istream & operator>>(std::istream & is, Coord & point){
    char separator;
    is >> separator;
    is >> point.latitude >> separator >> point.longitude >> separator;
    return is;
}

std::ostream & operator<<(std::ostream & is, const Coord & point){
    
}
