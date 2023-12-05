/**
 * @file RouteRep.cpp
 * @brief Implementation of the RouteRep class
 *
 */

#include "RouteRep.h"


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
    ifs >> *this;
}


map <string, Route> RouteRep::getRoutes() const {
    return this->routes;
}


const Route& RouteRep::getRoute(std::string id) const {
    return this->routes.at(id);
}

istream & operator>>(std::istream &is, RouteRep &_routeRep) {
    string id;
    while(!is.eof()){
        int n_pois;
        double lat, lon;
        list<Coord> pois_route;

        is>>id>>n_pois;
        for(int i = 0; i < n_pois; i++){
            Coord poi;
            is>>poi;
            pois_route.emplace_back(poi);
        }
        // ADD_ROUTE
        _routeRep.routes.insert(pair<string,Route>(id,Route(id,pois_route)));
    }
    return is;
}

ostream & operator<<(RouteRep & _routeRep, std::ostream& os){
    for (RouteRep::iterator it = _routeRep.begin(); it != _routeRep.end(); ++it) {
        os << (*it) << endl; ///> Route::operator<<
    }
}

//Iterator{
    RouteRep::iterator::iterator(const std::map<std::string, Route>::iterator &_it) {this->it = _it;}
    RouteRep::iterator & RouteRep::iterator::operator=(const RouteRep::iterator &other) {
        this->it = other.it;
        return *this;
    }
    RouteRep::iterator & RouteRep::iterator::operator++() {
        ++this->it;
        return *this;
    }
    const RouteRep::iterator RouteRep::iterator::operator++(int) {
        RouteRep::iterator tmp(*this);
        ++this->it;
        return tmp;
    }
    RouteRep::iterator & RouteRep::iterator::operator--() {
        --this->it;
        return *this;
    }
    const RouteRep::iterator RouteRep::iterator::operator--(int) {
        RouteRep::iterator tmp(*this);
        --this->it;
        return tmp;
    }
    bool RouteRep::iterator::operator==(const RouteRep::iterator &other) const {
        return this->it == other.it;
    }
    bool RouteRep::iterator::operator!=(const RouteRep::iterator &other) const {
        return this->it != other.it;
    }
    Route & RouteRep::iterator::operator*() {
        return this->it->second;
    }
//}
// Const_iterator{
    RouteRep::const_iterator::const_iterator(const std::map<std::string, Route>::const_iterator &_it) {this->it = _it;}
    RouteRep::const_iterator::const_iterator(const RouteRep::iterator &other) {this->it = other.it;}
    RouteRep::const_iterator & RouteRep::const_iterator::operator=(const RouteRep::const_iterator &other) {
        this->it = other.it;
        return *this;
    }
    RouteRep::const_iterator & RouteRep::const_iterator::operator++() {
        ++this->it;
        return *this;
    }
    RouteRep::const_iterator RouteRep::const_iterator::operator++(int) {
        RouteRep::const_iterator tmp(*this);
        ++this->it;
        return tmp;
    }
    RouteRep::const_iterator & RouteRep::const_iterator::operator--() {
        --this->it;
        return *this;
    }
    RouteRep::const_iterator RouteRep::const_iterator::operator--(int) {
        RouteRep::const_iterator tmp(*this);
        --this->it;
        return tmp;
    }
    bool RouteRep::const_iterator::operator==(const RouteRep::const_iterator &other) const {
        return this->it == other.it;
    }
    bool RouteRep::const_iterator::operator!=(const RouteRep::const_iterator &other) const {
        return this->it != other.it;
    }
    const Route & RouteRep::const_iterator::operator*() {
        return this->it->second;
    }
//}

//Iterator methods
RouteRep::iterator RouteRep::begin() {
    return RouteRep::iterator(this->routes.begin());
}
RouteRep::iterator RouteRep::end() {
    return RouteRep::iterator(this->routes.end());
}
RouteRep::const_iterator RouteRep::begin() const {
    return RouteRep::const_iterator(this->routes.begin());
}
RouteRep::const_iterator RouteRep::end() const {
    return RouteRep::const_iterator(this->routes.end());
}


