/**
 * @file Route.h
 * @brief Header file for the Route class.
 *
 * This file declares the Route class, which is used for representing a travel route.
 * The class contains functionalities for managing a route, including its identification and
 * points of interest (represented as Coord objects). It supports operations like
 * adding and removing points of interest, setting and getting route details, and
 * outputting route information.
 *
 * @authors Roberto González, Irina Kuzyshyn
 */

#ifndef PRACTICAFINAL_ROUTE_H
#define PRACTICAFINAL_ROUTE_H

#include <list> // Include the header file for std::list
#include <iostream>
#include <fstream>
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

    //!Comentar

    void addPoi(const Coord & poi);

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

    /**
     * @brief iterator class
     * @note iterator class for Route
     *
     */
    class iterator{
    private:
        std::list<Coord>::iterator it;
    public:
        /**
         * @brief Construct a new iterator object
         */
        iterator() = default;

        /**
         * @brief Copy constructor
         * @param _it iterator to copy
         */
        explicit iterator(const std::list<Coord>::iterator& _it);

        /**
         * @brief Copy assignment operator
         * @param other Another iterator to copy
         * @return Reference to the assigned iterator
         */
        iterator& operator=(const iterator& other);

        /**
         * @brief Prefix increment operator
         * @return Reference to the incremented iterator
         */
        iterator& operator++();

        /**
         * @brief Postfix increment operator
         * @return Copy of the iterator before incrementing
         */
        const iterator operator++(int);

        /**
         * @brief Prefix decrement operator
         * @return Reference to the decremented iterator
         */
        iterator& operator--();

        /**
         * @brief Postfix decrement operator
         * @return Copy of the iterator before decrementing
         */
        const iterator operator--(int);

        /**
         * @brief Equality comparison operator
         * @param other Another iterator to compare
         * @return True if both iterators are equal, false otherwise
         */
        bool operator==(const iterator& other) const;

        /**
         * @brief Inequality comparison operator
         * @param other Another iterator to compare
         * @return True if iterators are not equal, false otherwise
         */
        bool operator!=(const iterator& other) const;

        /**
         * @brief Dereference operator
         * @return Reference to the Route object pointed by the iterator
         */
        Coord& operator*();

        friend class Route;
        friend class const_iterator;

    };
    class const_iterator{
    private:
        std::list<Coord>::const_iterator it;
    public:
        /**
         * @brief Construct a new const iterator object
         */
        const_iterator() = default;

        /**
         * @brief Copy constructor
         * @param _it iterator to copy
         */
        explicit const_iterator(const std::list<Coord>::const_iterator& _it);

        /**
         * @brief Copy assignment operator
         * @param other Another iterator to copy
         * @return Reference to the assigned iterator
         */
        const_iterator& operator=(const const_iterator& other);

        /**
         * @brief Prefix increment operator
         * @return Reference to the incremented iterator
         */
        const_iterator& operator++();

        /**
         * @brief Postfix increment operator
         * @return Copy of the iterator before incrementing
         */
        const_iterator operator++(int);

        /**
         * @brief Prefix decrement operator
         * @return Reference to the decremented iterator
         */
        const_iterator& operator--();

        /**
         * @brief Postfix decrement operator
         * @return Copy of the iterator before decrementing
         */
        const_iterator operator--(int);

        /**
         * @brief Equality comparison operator
         * @param other Another iterator to compare
         * @return True if both iterators are equal, false otherwise
         */
        bool operator==(const const_iterator& other) const;

        /**
         * @brief Inequality comparison operator
         * @param other Another iterator to compare
         * @return True if iterators are not equal, false otherwise
         */
        bool operator!=(const const_iterator& other) const;

        /**
         * @brief Dereference operator
         * @return Reference to the Route object pointed by the iterator
         */
        const Coord & operator*() const;

        friend class Route;
    };

    /*
     * @brief Get an iterator to the beginning of the list of points of interest
     * @return iterator
     */
    iterator begin();

    /*
     * @brief Get an iterator to the end of the list of points of interest
     * @return iterator
     */
    iterator end();

    /*
     * @brief Get a const_iterator to the beginning of the list of points of interest
     * @return const_iterator
     */
    const_iterator begin() const;

    /*
     * @brief Get a const_iterator to the end of the list of points of interest
     * @return const_iterator
     */
    const_iterator end() const;

    friend std::ostream & operator<<(std::ostream & os, const Route &R);
    friend std::istream & operator>>(std::istream & is, Route &R);
};

#endif //PRACTICAFINAL_ROUTE_H
