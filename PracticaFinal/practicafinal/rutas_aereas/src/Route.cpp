/**
 * @file Route.cpp
 * @brief Implementation of the Route class.
 *
 * This file contains the implementation of the Route class, which is used for representing
 * a travel route. It includes functionalities for managing a route's identification and
 * points of interest, as well as operations for adding, removing, and outputting route information.
 *
 * @author Roberto González, Irina Kuzyshyn
 */

#include "Route.h"

#include <utility>
using namespace std;
Route::Route(string _id, const list<Coord>& _pois):
        id(std::move(_id)),
        pois(_pois)
{}

std::string Route::getId() const {
    return this->id;
}

std::list<Coord> Route::getPois() const {
    return this->pois;
}

void Route::setId(std::string _id) {
    this->id = std::move(_id);
}

void Route::setPois(const std::list<Coord>& _pois) {
    this->pois = _pois;
}

void Route::addPois(const std::list<Coord>& _pois) {
    this->pois.insert(this->pois.end(), _pois.begin(), _pois.end());
}

void Route::removePois(const std::list<Coord>& _pois) {
    for (const Coord& poi : _pois) {
        this->pois.remove(poi);
    }
}

std::ostream & operator<<(std::ostream & os, const Route &R){
    os << R.id << " " << R.pois.size() << " ";
    for (const Coord& poi : R.pois) {
        os << poi << " ";
    }
    return os;
}

