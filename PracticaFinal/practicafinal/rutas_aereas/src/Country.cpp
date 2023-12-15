//
// Created by uwu on 27/11/23.
//

#include "Country.h"
using namespace std;

explicit Country::Country(const std::string &_name = "", const Coord &loc = Coord(), const std::string path = "") : name(_name), location(loc), flag_path(path) {}

Country::Country(const Country &other){
    *this = other;
}

Country& Country::operator=(const Country &other){
    this->name = other.getName();
    this->location = other.getLocation();
    this->flag_path = other.getFlagPath();

    return *this;
}

const std::string& Country::getName() const{
    return this->name;
}

const Coord& Country::getLocation() const{
    return this->location;
}

const std::string& Country::getFlagPath() const{
    return this->flag_path;
}

void Country::setName(const std::string &_name){
    this->name = _name;
}

void Country::setLocation(const Coord &_location){
    this->location = _location;
}

void Country::setFlagPath(const std::string &_path){
    this->flag_path = _path;
}

bool Country::operator<(const Country &C) const{
    return this->getName() < C.getName();
}

bool Country::operator==(const Country &C) const{
    return *this == C;
}

bool Country::operator==(const Coord &point) const{
    return this->getLocation() == point;
}

std::istream & operator>>(std::istream & is, Country & P){
    double lat, lon;
    is >> lat  >> lon;
    P.setLocation(Coord(lat,lon));

    is >> P.name >> P.flag_path;

    return is;
}

std::ostream & operator<<(std::ostream & os, const Country &P){
    os << P.getLocation().getLatitude() << " " << P.getLocation().getLongitude() 
    << " " << P.name << " " << P.flag_path << endl;

    return os; 
}