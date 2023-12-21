/**
 * @file Countries.h
 * @brief Header file for the Countries class.
 *
 * This file declares the Countries class, which manages a collection of Country objects.
 * It supports operations like insertion, deletion, and searching within a set of countries.
 * The file also includes the definition of iterator and const_iterator classes for
 * iterating over the countries.
 *
 * @authors Roberto González, Irina Kuzyshyn
 */


#ifndef PRACTICAFINAL_COUNTRIES_H
#define PRACTICAFINAL_COUNTRIES_H

#include <set>
#include <fstream>
#include <cassert>
#include "Country.h"

/**
 * @class Countries
 * @brief Class representing a collection of Country objects.
 *
 * This class manages a collection of countries, allowing for operations such as insertion, deletion, and searching within the set of countries.
 */
class Countries {
private:
    std::set<Country> countries; ///< Set of Country objects.

public:
    /**
     * @brief Constructor with an optional set of Country objects.
     * @param _countries Initial set of Country objects.
     */
    explicit Countries(const std::set<Country> &_countries = std::set<Country>());

    /**
     * @brief Copy constructor.
     * @param other Another Countries object to copy.
     */
    Countries(const Countries &other);

    /**
     * @brief Assignment operator.
     * @param other Another Countries object to assign from.
     * @return Reference to the assigned Countries object.
     */
    Countries & operator=(const Countries &other);

    /**
     * @brief Insert a new Country object into the collection.
     * @param country Country object to insert.
     */
    void insert(const Country &country);

    /**
     * @brief Erase a Country object from the collection.
     * @param country Country object to erase.
     */
    void erase(const Country &country);

    /**
     * @class iterator
     * @brief Iterator for Countries class.
     *
     * This iterator allows for read-write access to the countries in the collection.
     */
    class iterator {
    private:
        std::set<Country>::iterator c; ///< Internal iterator for the set of Country objects.

        // Allow Countries class to access private members of iterator
        friend class Countries;

        // Constructor is private, used only within the Countries class
        explicit iterator(std::set<Country>::iterator orig) : c(orig) {}

    public:
        // Default constructor
        iterator() = default;

        // Copy constructor
        iterator(const iterator &other) : c(other.c) {}

        // Default assignment operator
        iterator& operator=(const iterator &other) = default;

        // Increment operators (prefix and postfix)
        iterator& operator++() { ++c; return *this; }
        iterator operator++(int) { iterator aux = *this; ++(*this); return aux; }

        // Decrement operators (prefix and postfix)
        iterator& operator--() { --c; return *this; }
        iterator operator--(int) { iterator aux = *this; --(*this); return aux; }

        // Equality comparison operators
        bool operator==(const iterator& other) const { return c == other.c; }
        bool operator!=(const iterator& other) const { return c != other.c; }

        // Dereference operator
        Country& operator*() { return const_cast<Country &>(*c); }
    };

    /**
     * @class const_iterator
     * @brief Constant iterator for Countries class.
     *
     * This iterator allows for read-only access to the countries in the collection.
     */
    class const_iterator {
    private:
        std::set<Country>::const_iterator c; ///< Internal constant iterator for the set of Country objects.

        // Allow Countries class to access private members of const_iterator
        friend class Countries;

        // Constructor is private, used only within the Countries class
        explicit const_iterator(std::set<Country>::const_iterator orig) : c(orig) {}

    public:
        // Default constructor
        const_iterator() = default;

        // Conversion constructor from non-const iterator
        explicit const_iterator(const iterator &it) : c(it.c) {}

        // Copy constructor
        const_iterator(const const_iterator &other) : c(other.c) {}

        // Assignment operator
        const_iterator& operator=(const const_iterator &other) { c = other.c; return *this; }

        // Increment operators (prefix and postfix)
        const_iterator& operator++() { ++c; return *this; }
        const_iterator operator++(int) { const_iterator aux = *this; ++(*this); return aux; }

        // Decrement operators (prefix and postfix)
        const_iterator& operator--() { --c; return *this; }
        const_iterator operator--(int) { const_iterator aux = *this; --(*this); return aux; }

        // Equality comparison operators
        bool operator==(const const_iterator& other) const { return c == other.c; }
        bool operator!=(const const_iterator& other) const { return c != other.c; }

        // Dereference operator
        const Country& operator*() const { return *c; }
    };

    // Iterator access methods
    iterator begin() { return iterator(countries.begin()); }
    iterator end() { return iterator(countries.end()); }
    const_iterator cbegin() const { return const_iterator(countries.cbegin()); }
    const_iterator cend() const { return const_iterator(countries.cend()); }

    // Country search methods
    const_iterator find(const Country &country) const;
    const_iterator find(const Coord &point) const;

    // Stream operators
    friend std::ostream& operator<<(std::ostream& os, const Countries& c);
    friend std::istream& operator>>(std::istream& is, Countries& c);
};

#endif //PRACTICAFINAL_COUNTRIES_H
