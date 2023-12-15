//
// Created by uwu on 27/11/23.
//

#ifndef PRACTICAFINAL_COUNTRY_H
#define PRACTICAFINAL_COUNTRY_H

#include <string>
#include <fstream>
#include "Coord.h"
class Country {
private:
    std::string name;
    Coord location;
    std::string flag_path;
public:
    explicit Country(const std::string &country = "", const Coord &loc = Coord(), const std::string path = "");
    Country(const Country &other);
    Country& operator=(const Country &other);

    ///< Getters
    const std::string &getName() const;
    const Coord &getLocation() const;
    const std::string &getFlagPath() const;

    ///< Setters
    void setName(const std::string &_name);
    void setLocation(const Coord &_location);
    void setFlagPath(const std::string &_path);

    bool operator<(const Country &C) const;
    bool operator==(const Country &C) const;
    bool operator==(const Coord &point) const;

    friend std::istream & operator>>(std::istream & is, Country & P);
    friend std::ostream & operator<<(std::ostream & os, const Country &P);
};


#endif //PRACTICAFINAL_COUNTRY_H
