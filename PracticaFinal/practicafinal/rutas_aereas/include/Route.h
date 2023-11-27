/**
 * @file Route.h
 * @brief Fichero con definiciones para la clase Route
 *
 */



#ifndef PRACTICAFINAL_ROUTE_H
#define PRACTICAFINAL_ROUTE_H

#include "Countries.h"
#include "Countries.h" // Include the header file for the Countries class
#include <iostream>

class Route {
private:
    std::string id;
    Countries countries; // Use Countries object instead of std::list<Countries>
public:
    /**
     * @brief Constructor with parameters
     * @note Acts as default constructor if no parameters are given
     * @param id
     * @param countries
     */
    explicit Route(std::string _id = "", const Countries& _countries = Countries());

    /**
     * @brief Get the Id object
     * @return std::string
     */
    std::string getId() const;

    /**
     * @brief Get the Countries object
     * @return Countries
     */
    Countries getCountries() const;

    /**
     * @brief Set the Id object
     * @param id
     */
    void setId(std::string id);

    /**
     * @brief Set the Countries object
     * @param countries
     */
    void setCountries(const Countries& countries);

    /**
     * @brief Add countries to the route
     * @param countries Countries object to add.
     */
    void addCountries(const Countries& countries);


    /**
     * @brief Remove countries from the route
     * @param countries Countries object containing the countries to remove.
     */
    void removeCountries(const Countries& countries);
};

#endif //PRACTICAFINAL_ROUTE_H
