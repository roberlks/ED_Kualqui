/**
 * @file Countries.cpp
 * @brief Implementation of the Countries class.
 *
 * This file contains the implementation of the Countries class, which manages a collection of Country objects.
 * It includes methods for adding and removing countries, finding countries by their attributes,
 * and overloading input/output operators to interact with streams.
 * The file also implements iterator functionalities to traverse through the collection.
 *
 * @authors Roberto González, Irina Kuzyshyn
 */


#include <string>
#include "Countries.h"


using namespace std;

Countries::Countries(const std::set<Country> &_countries) : countries(_countries){}

Countries::Countries(const Countries &other){   
    *this = other;
}

Countries & Countries::operator=(const Countries &other)= default;

void Countries::insert(const Country &country){
    countries.insert(country);
}

void Countries::erase(const Country &country){
    countries.erase(country);
}

Countries::const_iterator Countries::find(const Country &country) const{
    Countries::const_iterator it;
    for (it = cbegin(); it != cend(); ++it)
        if (*it == country) return it;

    return it;
}

Countries::const_iterator Countries::find(const Coord& point) const{
    Countries::const_iterator it;
    for (it = cbegin(); it != cend(); ++it)
        if ((*it).getLocation() == point) return it;

    return it;
}


std::ostream& operator<<(std::ostream& os, const Countries& c){
    for (Countries::const_iterator it = c.cbegin(); it != c.cend(); ++it){
        os << *it << endl;
    }

    return os;
}

std::istream& operator>>(std::istream& is, Countries& c){
    Countries local;
    //leemos el comentario
    if (is.peek()=='#'){
        string a;
        getline(is,a);
    }

    Country country;

    while (is >> country){
        local.insert(country);
    }

    c = local;
    return is;
}