/**
 * @file RouteRep.cpp
 * @brief Implementation of the RouteRep class
 *
 */

#include "RouteRep.h"

#include <utility>
#include <fstream>

using namespace std;
RouteRep::RouteRep(map<string, Route>_routes) {
    this->routes = std::move(_routes);
}

RouteRep::RouteRep(const list<Route>& _routes){
    for(const Route& route : _routes){
        this->routes.insert(pair<string,Route>(route.getId(),route));
    }
}
RouteRep::RouteRep(char* file) {
    ifstream ifs;
    ifs.open(file);
    *this<<ifs;
}


map <string, Route> RouteRep::getRoutes() const {
    return this->routes;
}


ifstream & RouteRep::operator<<(std::ifstream &ifs) {
    string id;
    while(!ifs.eof()){
        int n_pois;
        double lat, lon;
        list<Coord> pois_route;

        ifs>>id>>n_pois;
        for(int i = 0; i < n_pois; i++){
            ifs>>lat>>lon;
            pois_route.emplace_back(lat,lon);
        }
        this->routes.insert(pair<string,Route>(id,Route(id,pois_route)));
    }
    return ifs;
}
