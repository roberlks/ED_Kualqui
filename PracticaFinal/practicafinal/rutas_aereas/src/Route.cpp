/**
 * @file Route.cpp
 * @brief Implementación de la clase Route
 *
 */

#include "Route.h"

#include <utility>



Route::Route(std::string _id, const Countries& _countries):
    id(std::move(_id)),
    countries(_countries)
{}

std::string Route::getId() const {
    return this->id;
}

Countries Route::getCountries() const {
    return this->countries;
}

void Route::setId(std::string _id) {
    this->id = std::move(_id);
}

void Route::setCountries(const Countries& _countries) {
    this->countries = _countries;
}

void Route::addCountries(const Countries& _countries) {
    this->countries += _countries;
}

void Route::removeCountries(const Countries &_countries) {
    this->countries -= _countries;
}



