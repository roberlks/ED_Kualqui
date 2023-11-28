/**
 * @file Route.cpp
 * @brief Implementación de la clase Route
 *
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
