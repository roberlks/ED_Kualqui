/**
 * @file RouteRep.h
 * @brief Header file for the RouteRep class.
 *
 * This file declares the RouteRep class, which is used for storing and managing multiple routes.
 * The class facilitates operations like constructing routes from different sources (such as lists or files),
 * iterating over routes, and managing route data. It includes nested iterator and const_iterator classes
 * for iterating through the routes.
 *
 * @authors Roberto González, Irina Kuzyshyn
 */

#ifndef PRACTICAFINAL_ROUTEREP_H
#define PRACTICAFINAL_ROUTEREP_H

#include <map>
#include <list>
#include <fstream>
#include <iostream>
#include"Route.h"


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

    const Route& getRoute(std::string id) const;


    /**
     * @brief Input operator, reads from ifstream
     * @param ifs ifstream from which to read
     * @return Reference to ifstream
     * @post The RouteRep object has been filled with the data from the ifstream
     * @note If the route object already has data, it will be appended to the end.
     */
    friend std::istream & operator>>(std::istream& is, RouteRep& _routeRep);
    friend std::ostream & operator <<(RouteRep& _routeRep, std::ostream& os);

    /**
     * @brief iterator class
     * @note iterator class for RouteRep
     *
     */
    class iterator {
    private:
        std::map<std::string, Route>::iterator it;

    public:
        /**
         * @brief Construct a new iterator object
         */
        iterator() = default;

        /**
         * @brief Copy constructor
         * @param _it iterator to copy
         */
        explicit iterator(const std::map<std::string, Route>::iterator& _it);

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
        Route& operator*();

        friend class RouteRep;
        friend class const_iterator;
    };

    /**
     * @brief const_iterator class
     * @note const_iterator class for RouteRep
     *
     */
    class const_iterator {
    private:
        std::map<std::string, Route>::const_iterator it;

    public:
        /**
         * @brief Default constructor for const_iterator
         */
        const_iterator() = default;

        /**
         * @brief Explicit constructor from a const_iterator of the underlying map
         * @param _it Const_iterator of the underlying map to copy
         */
        explicit const_iterator(const std::map<std::string, Route>::const_iterator& _it);

        /**
         * @brief Explicit constructor from an iterator
         * @param other Iterator to copy
         */
        explicit const_iterator(const iterator& other);

        /**
         * @brief Copy assignment operator for const_iterator
         * @param other Another const_iterator to copy
         * @return Reference to the assigned const_iterator
         */
        const_iterator& operator=(const const_iterator& other);

        /**
         * @brief Prefix increment operator for const_iterator
         * @return Reference to the incremented const_iterator
         */
        const_iterator& operator++();

        /**
         * @brief Postfix increment operator for const_iterator
         * @return Copy of the const_iterator before incrementing
         */
        const_iterator operator++(int);

        /**
         * @brief Prefix decrement operator for const_iterator
         * @return Reference to the decremented const_iterator
         */
        const_iterator& operator--();

        /**
         * @brief Postfix decrement operator for const_iterator
         * @return Copy of the const_iterator before decrementing
         */
        const_iterator operator--(int);

        /**
         * @brief Equality comparison operator for const_iterator
         * @param other Another const_iterator to compare
         * @return True if both const_iterators are equal, false otherwise
         */
        bool operator==(const const_iterator& other) const;

        /**
         * @brief Inequality comparison operator for const_iterator
         * @param other Another const_iterator to compare
         * @return True if const_iterators are not equal, false otherwise
         */
        bool operator!=(const const_iterator& other) const;

        /**
         * @brief Dereference operator for const_iterator
         * @return Const reference to the Route object pointed by the const_iterator
         */
        const Route& operator*();
    };

    /**
     * @brief Get the iterator pointing to the beginning of the routes
     * @return Iterator pointing to the beginning
     */
    iterator begin();

    /**
     * @brief Get the iterator pointing to the end of the routes
     * @return Iterator pointing to the end
     */
    iterator end();

    /**
     * @brief Get the const_iterator pointing to the beginning of the routes
     * @return Const_iterator pointing to the beginning
     */
    const_iterator begin() const;

    /**
     * @brief Get the const_iterator pointing to the end of the routes
     * @return Const_iterator pointing to the end
     */
    const_iterator end() const;
}; // Class RouteRep


#endif //PRACTICAFINAL_ROUTEREP_H
