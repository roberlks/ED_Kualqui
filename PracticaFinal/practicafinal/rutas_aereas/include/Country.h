/**
 * @file Country.h
 * @brief Header file for the Country class.
 *
 * This file declares the Country class, which represents a country with its name,
 * geographic location (latitude and longitude), and a path to its flag image.
 * It provides functionalities for setting and getting country attributes,
 * comparing countries, and overloading input/output operators.
 *
 * @authors Roberto González, Irina Kuzyshyn
 */

#ifndef PRACTICAFINAL_COUNTRY_H
#define PRACTICAFINAL_COUNTRY_H

#include <string>
#include <fstream>
#include "Coord.h"

/**
 * @class Country
 * @brief Class representing a country with a name, geographic location, and a flag path.
 *
 * This class encapsulates details about a country, including its name, geographic coordinates (latitude and longitude), and the path to its flag image.
 */
class Country {
private:
    std::string name; ///< Name of the country.
    Coord location; ///< Geographic location of the country.
    std::string flag_path; ///< Path to the country's flag image.

public:
    /**
     * @brief Constructor with optional parameters for name, location, and flag path.
     * @param _name Name of the country.d
     * @param loc Location of the country as a Coord object.
     * @param path Path to the flag image.
     */
    explicit Country(std::string _name = "", const Coord &loc = Coord(), std::string path = "");

    /**
     * @brief Copy constructor.
     * @param other Another Country object to copy.
     */
    Country(const Country &other);

    /**
     * @brief Assignment operator.
     * @param other Another Country object to assign from.
     * @return Reference to the assigned Country object.
     */
    Country& operator=(const Country &other);

    // Getters

    /**
     * @brief Get the name of the country.
     * @return Constant reference to the country's name.
     */
    const std::string &getName() const;

    /**
     * @brief Get the location of the country.
     * @return Constant reference to the Coord object representing the location.
     */
    const Coord &getLocation() const;

    /**
     * @brief Get the path to the country's flag image.
     * @return Constant reference to the string representing the flag path.
     */
    const std::string &getFlagPath() const;

    // Setters

    /**
     * @brief Set the name of the country.
     * @param _name New name of the country.
     */
    void setName(const std::string &_name);

    /**
     * @brief Set the location of the country.
     * @param _location New location of the country as a Coord object.
     */
    void setLocation(const Coord &_location);

    /**
     * @brief Set the path to the country's flag image.
     * @param _path New path to the flag image.
     */
    void setFlagPath(const std::string &_path);

    /**
     * @brief Comparison operator for sorting.
     * @param C Another Country object to compare with.
     * @return True if this country is less than the other, based on name comparison.
     */
    bool operator<(const Country &C) const;

    /**
     * @brief Equality operator.
     * @param C Another Country object to compare with.
     * @return True if this country is equal to the other.
     */
    bool operator==(const Country &C) const;

    /**
     * @brief Equality operator with a Coord object.
     * @param point A Coord object to compare the country's location with.
     * @return True if the country's location is equal to the Coord object.
     */
    bool operator==(const Coord &point) const;

    /**
     * @brief Input stream operator for reading country details.
     * @param is Input stream.
     * @param P Country object to read into.
     * @return Reference to the input stream.
     */
    friend std::istream & operator>>(std::istream & is, Country & P);

    /**
     * @brief Output stream operator for printing country details.
     * @param os Output stream.
     * @param P Country object to print.
     * @return Reference to the output stream.
     */
    friend std::ostream & operator<<(std::ostream & os, const Country &P);
};

#endif //PRACTICAFINAL_COUNTRY_H
