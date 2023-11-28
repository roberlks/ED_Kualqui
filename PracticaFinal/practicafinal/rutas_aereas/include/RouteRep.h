/**
 * @file RouteRep.h
 * @brief Representation of an storage of routes.
 *
 */
#ifndef PRACTICAFINAL_ROUTEREP_H
#define PRACTICAFINAL_ROUTEREP_H

#include"Route.h"
#include <map>
#include <list>
#include <fstream>
#include <iostream>

class RouteRep {
private:
    std::map<std::string,Route> routes;
public:
    /**
     * @brief Constructor with parameters
     * @note Acts as default constructor if no parameters are given
     *
     */
    explicit RouteRep(std::map<std::string,Route> routes = std::map<std::string,Route>());

    /**
     * @brief Constructor from list
     *
     */
    explicit RouteRep(const std::list<Route>& _routes);

    /**
     * @brief Constructor from file
     * @note File format must be:
     * R1 5 (34.5204,69.2008) (52.5079,13.4261) (7.40665,12.3446)
     *      (-0.186596,-78.4305) (40.4005,-3.59165)
     * R2 8 (58.6954,-96) (35.0869,-103.723) (-12.0553,-77.0452)
     *      (40.4005,-3.59165) (37.9438,104.136) (-27.7871,133.281)
     *      (35.6735,139.71) (62.8865,61.5512)
     * [...]
     *
     */
    explicit RouteRep(char* file);

    /**
     * @brief Get the Routes object
     *
     * @return std::map<std::string,Route>
     */
    std::map<std::string,Route> getRoutes() const;

    /**
     * @brief Input operator, reads from ifstream
     * @param ifs ifstream from which to read
     * @return Reference to ifstream
     * @post The RouteRep object has been filled with the data from the ifstream
     * @note If the route object already has data, it will be appended to the end.
     */
    std::ifstream  & operator<<(std::ifstream& ifs);
};


#endif //PRACTICAFINAL_ROUTEREP_H
