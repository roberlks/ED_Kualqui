//
// Created by alquitran on 27/11/23.
//

#ifndef PRACTICAFINAL_ROUTEREP_H
#define PRACTICAFINAL_ROUTEREP_H

#include"Route.h"
#include <map>
#include <iostream>

class RouteRep {
private:
    std::map<std::string,Route> routes;
public:
    /**
     * @brief Default constructor
     *
     */
    RouteRep();

    /**
     * @brief Constructor with parameters
     *
     */
    RouteRep(std::map<std::string,Route> routes);

    /**
     * @brief Constructor from list
     *
     */
    RouteRep(std::list<Route> routes);

    /**
     * @brief Constructor from file
     *
     */
    RouteRep(char* file);

    /**
     * @brief Get the Routes object
     *
     * @return std::map<std::string,Route>
     */
    std::map<std::string,Route> getRoutes() const;
};


#endif //PRACTICAFINAL_ROUTEREP_H
