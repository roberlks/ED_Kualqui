//
// Created by uwu on 27/11/23.
//

#include "Coord.h"


Coord::Coord(double lat, double lon) : latitude(lat), longitude(lon){}

Coord::Coord(const Coord &other){
    *this = other;
}



Coord& Coord::operator=(const Coord &other){
    this->latitude = other.Latitude();
    this->longitude = other.Longitude();

    return *this;
}

const double& Coord::Latitude() const{
    return latitude;
}

const double& Coord::Longitude() const{
    return longitude;
}

double& Coord::Latitude(){
    return latitude;
}

double& Coord::Longitude(){
    return longitude;
}

Coord Coord::midpoint(const Coord &other) const{
    return Coord((this->Latitude() + other.Latitude())/2, (this->Longitude() + other.Longitude())/2);
}

bool Coord::operator==(const Coord &other) const{
    return (this->Latitude() == other.Latitude() && this->Longitude() == other.Longitude());
}



