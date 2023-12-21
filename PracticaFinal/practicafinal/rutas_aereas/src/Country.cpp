/**
 * @file Country.cpp
 * @brief Implementation of the Country class.
 *
 * This file contains the implementation of the Country class, which represents a country
 * with its name, geographic location, and a path to its flag image. It includes methods
 * for setting and getting country attributes, comparing countries, and overloading
 * input/output operators for stream interactions.
 *
 * @authors Roberto González, Irina Kuzyshyn
 */

#include "Country.h"

#include <utility>
using namespace std;

Country::Country(std::string _name, const Coord &loc, std::string  path) : name(std::move(_name)), location(loc), flag_path(std::move(path)) {}

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
    bool equal = true;
    equal &= this->getName() == C.getName();
    equal &= this->getLocation() == C.getLocation();
    equal &= this->getFlagPath() == C.getFlagPath();
    return equal;
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