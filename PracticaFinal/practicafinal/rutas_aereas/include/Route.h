#ifndef PRACTICAFINAL_ROUTE_H
#define PRACTICAFINAL_ROUTE_H

#include <list> // Include the header file for std::list
#include <iostream>
#include "Coord.h" // Include the header file for the Coord class

class Route {
private:
    std::string id;
    std::list<Coord> pois; // Use std::list<Coord> instead of Countries
public:
    /**
     * @brief Constructor with parameters
     * @note Acts as default constructor if no parameters are given
     * @param _id The ID of the route
     * @param _pois The list of points of interest (Coord objects)
     */
    explicit Route(std::string _id = "", const std::list<Coord>& _pois = std::list<Coord>());

    /**
     * @brief Get the ID of the route
     * @return std::string
     */
    std::string getId() const;

    /**
     * @brief Get the list of points of interest (Coord objects) in the route
     * @return std::list<Coord>
     */
    std::list<Coord> getPois() const;

    /**
     * @brief Set the ID of the route
     * @param id The ID to set
     */
    void setId(std::string id);

    /**
     * @brief Set the list of points of interest (Coord objects) in the route
     * @param pois The list of points of interest to set
     */
    void setPois(const std::list<Coord>& pois);

    /**
     * @brief Add points of interest (Coord objects) to the route
     * @param pois The list of points of interest to add
     */
    void addPois(const std::list<Coord>& pois);

    /**
     * @brief Remove points of interest (Coord objects) from the route
     * @param pois The list of points of interest to remove
     */
    void removePois(const std::list<Coord>& _pois);
};

#endif //PRACTICAFINAL_ROUTE_H
