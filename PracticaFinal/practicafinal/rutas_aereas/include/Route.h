//
// Created by alquitran on 27/11/23.
//

#ifndef PRACTICAFINAL_ROUTE_H
#define PRACTICAFINAL_ROUTE_H

#include"Coord.h"
#include <iostream>
#include <list>



class Route {
private:
    std::string id;
    std::list<Coord> coords;
public:
    /**
     * @brief Default constructor
     *
     */
    Route();
    /**
     * @brief Constructor with parameters
     *
     * @param id
     * @param coords
     */
    Route(std::string id, std::list<Coord> coords);

    /**
     * @brief Get the Id object
     *
     * @return std::string
     */
    std::string getId() const;

    /**
     * @brief Get the Coords object
     *
     * @return std::list<Coord>
     */
    std::list<Coord> getCoords() const;

    /**
     * @brief Set the Id object
     *
     * @param id
     */
    void setId(std::string id);

    /**
     * @brief Set the Coords object
     *
     * @param coords
     */
    void setCoords(std::list<Coord> coords);

    /**
     * @brief Add coords to the route
     *
     * @param coord coord to add.
     * @return true if coords were added, false otherwise.
     *
     */
    bool addCoords(Coord coord);

    /**
     * @brief Overload method addCoords
     *
     * @param coords list of coords to add.
     * @return true if coords were added, false otherwise.
     */
    bool addCoords(std::list<Coord> coords);

    /**
     * @brief Remove coords from the route
     *
     * @param coord coord to remove.
     * @return true if coords were removed, false otherwise.
     */
    bool removeCoords(Coord coord);

    /**
     * @brief Overload method removeCoords
     *
     * @param coords list of coords to remove.
     * @return true if coords were removed, false otherwise.
     */
    bool removeCoords(std::list<Coord> coords);


};


#endif //PRACTICAFINAL_ROUTE_H
