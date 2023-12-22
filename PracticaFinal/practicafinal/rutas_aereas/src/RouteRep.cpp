/**
 * @file RouteRep.cpp
 * @brief Implementation of the RouteRep class.
 *
 * This file contains the implementation of the RouteRep class, which is used to store and manage multiple routes.
 * It includes methods for constructing route repositories from different sources (such as maps, lists, or files),
 * accessing and modifying route data, and providing iterator functionalities for traversing through the routes.
 *
 * @author Roberto González, Irina Kuzyshyn
 */

#include "RouteRep.h"

using namespace std;
RouteRep::RouteRep(map<string, Route> _routes)
{
    this->routes = std::move(_routes);
}

RouteRep::RouteRep(const list<Route> &_routes)
{
    for (const Route &route : _routes)
    {
        this->routes.insert(pair<string, Route>(route.getId(), route));
    }
}
RouteRep::RouteRep(char *file)
{
    ifstream ifs;
    ifs.open(file);
    ifs >> *this;
}

map<string, Route> RouteRep::getRoutes() const
{
    return this->routes;
}

const Route &RouteRep::getRoute(std::string id) const
{
    return this->routes.at(id);
}

istream &operator>>(std::istream &is, RouteRep &_routeRep)
{

    //We dont do it using the >> from routes cause it causes inestability when checking for EOF
    
    string id, aux;
    is >> aux;
    Route r;
    while (!is.eof())
    {
        string s;
        is >> s;
        r.setId(s);
        int n_pois;
        is >> n_pois;

        Coord poi;
        for (int i = 0; i < n_pois; i++)
        {
            is >> poi;
            r.addPoi(poi);
        }
        _routeRep.routes.insert(make_pair(r.getId(), r));
    }
    return is;
}

ostream &operator<<(std::ostream &os, RouteRep &_routeRep)
{
    for (RouteRep::iterator it = _routeRep.begin(); it != _routeRep.end(); ++it)
    {
        os << (*it) << endl; ///> Route::operator<<
    }

    return os;
}

// Iterator{
RouteRep::iterator::iterator(const std::map<std::string, Route>::iterator &_it) { this->it = _it; }
RouteRep::iterator &RouteRep::iterator::operator=(const RouteRep::iterator &other) = default;
RouteRep::iterator &RouteRep::iterator::operator++()
{
    ++this->it;
    return *this;
}
const RouteRep::iterator RouteRep::iterator::operator++(int)
{
    RouteRep::iterator tmp(*this);
    ++this->it;
    return tmp;
}
RouteRep::iterator &RouteRep::iterator::operator--()
{
    --this->it;
    return *this;
}
const RouteRep::iterator RouteRep::iterator::operator--(int)
{
    RouteRep::iterator tmp(*this);
    --this->it;
    return tmp;
}
bool RouteRep::iterator::operator==(const RouteRep::iterator &other) const
{
    return this->it == other.it;
}
bool RouteRep::iterator::operator!=(const RouteRep::iterator &other) const
{
    return this->it != other.it;
}
Route &RouteRep::iterator::operator*()
{
    return this->it->second;
}
//}
// Const_iterator{
RouteRep::const_iterator::const_iterator(const std::map<std::string, Route>::const_iterator &_it) { this->it = _it; }
RouteRep::const_iterator::const_iterator(const RouteRep::iterator &other) { this->it = other.it; }
RouteRep::const_iterator &RouteRep::const_iterator::operator=(const RouteRep::const_iterator &other)
{
    this->it = other.it;
    return *this;
}

RouteRep::const_iterator &RouteRep::const_iterator::operator++()
{
    ++this->it;
    return *this;
}
RouteRep::const_iterator RouteRep::const_iterator::operator++(int)
{
    RouteRep::const_iterator tmp(*this);
    ++this->it;
    return tmp;
}
RouteRep::const_iterator &RouteRep::const_iterator::operator--()
{
    --this->it;
    return *this;
}
RouteRep::const_iterator RouteRep::const_iterator::operator--(int)
{
    RouteRep::const_iterator tmp(*this);
    --this->it;
    return tmp;
}
bool RouteRep::const_iterator::operator==(const RouteRep::const_iterator &other) const
{
    return this->it == other.it;
}
bool RouteRep::const_iterator::operator!=(const RouteRep::const_iterator &other) const
{
    return this->it != other.it;
}
const Route &RouteRep::const_iterator::operator*()
{
    return this->it->second;
}
//}

// Iterator methods
RouteRep::iterator RouteRep::begin()
{
    return RouteRep::iterator(this->routes.begin());
}
RouteRep::iterator RouteRep::end()
{
    return RouteRep::iterator(this->routes.end());
}
RouteRep::const_iterator RouteRep::begin() const
{
    return RouteRep::const_iterator(this->routes.begin());
}
RouteRep::const_iterator RouteRep::end() const
{
    return RouteRep::const_iterator(this->routes.end());
}
