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

void Route::addPoi(const Coord & poi){
    this->pois.push_back(poi);
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

istream & operator>>(istream & is, Route & R){
    is >> R.id;
    int n_pois;
    is >> n_pois;

    Coord poi;
    for (int i = 0; i < n_pois; i++){
        is >> poi;

        R.addPoi(poi);
    }

    return is;
}



//Iterator{
    Route::iterator::iterator(const std::list<Coord>::iterator &_it) {this->it = _it;}
    Route::iterator & Route::iterator::operator=(const Route::iterator &other) {
        this->it = other.it;
        return *this;
    }
    Route::iterator & Route::iterator::operator++() {
        ++this->it;
        return *this;
    }
    const Route::iterator Route::iterator::operator++(int) {
        Route::iterator tmp(*this);
        ++this->it;
        return tmp;
    }
    Route::iterator & Route::iterator::operator--() {
        --this->it;
        return *this;
    }
    const Route::iterator Route::iterator::operator--(int) {
        Route::iterator tmp(*this);
        --this->it;
        return tmp;
    }
    bool Route::iterator::operator==(const Route::iterator &other) const {
        return this->it == other.it;
    }
    bool Route::iterator::operator!=(const Route::iterator &other) const {
        return this->it != other.it;
    }
    Coord & Route::iterator::operator*() {
        return *this->it;
    }
//}
// Const_iterator{
    Route::const_iterator::const_iterator(const std::list<Coord>::const_iterator &_it) {this->it = _it;}
    Route::const_iterator & Route::const_iterator::operator=(const Route::const_iterator &other) = default;

    Route::const_iterator & Route::const_iterator::operator++() {
        ++this->it;
        return *this;
    }
    Route::const_iterator Route::const_iterator::operator++(int) {
        Route::const_iterator tmp(*this);
        ++this->it;
        return tmp;
    }
    Route::const_iterator & Route::const_iterator::operator--() {
        --this->it;
        return *this;
    }
    Route::const_iterator Route::const_iterator::operator--(int) {
        Route::const_iterator tmp(*this);
        --this->it;
        return tmp;
    }
    bool Route::const_iterator::operator==(const Route::const_iterator &other) const {
        return this->it == other.it;
    }
    bool Route::const_iterator::operator!=(const Route::const_iterator &other) const {
        return this->it != other.it;
    }

    const Coord &Route::const_iterator::operator*() const {
        return *this->it;
    }
//}

//Iterator methods
Route::iterator Route::begin() {
    return Route::iterator(this->pois.begin());
}
Route::iterator Route::end(){
    return Route::iterator(this->pois.end());
}
Route::const_iterator Route::begin() const {
    return Route::const_iterator(this->pois.begin());
}
Route::const_iterator Route::end() const {
    return Route::const_iterator(this->pois.end());
}