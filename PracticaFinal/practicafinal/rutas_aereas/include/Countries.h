

#ifndef PRACTICAFINAL_COUNTRIES_H
#define PRACTICAFINAL_COUNTRIES_H

#include <set>
#include <fstream>
#include <cassert>
#include "Country.h"

class Countries {
private:
    std::set<Country> countries;

public:
    Countries(const std::set<Country> &_countries = std::set<Country>());
    Countries(const Countries &other);
    Countries & operator=(const Countries &other);

    void insert(const Country &country);
    void erase(const Country &country);

    class const_iterator;
    
    class iterator{
    private:
        std::set<Country>::iterator c;
        iterator(std::set<Country>::iterator orig) : c(orig){}

    public:
        iterator(){}

        iterator(const iterator &other){
            c = other.c;
        }

        iterator& operator=(const iterator &other){
            c = other.c;
            return *this;
        }

        iterator& operator++(){
            ++c;
            return *this;
        }

        iterator operator++(int){
            iterator aux = *this;
            ++(*this);
            return aux;
        }

        iterator& operator--(){
            --c;
            return *this;
        }

        iterator operator--(int){
            iterator aux = *this;
            --(*this);
            return aux;
        }

        bool operator==(const const_iterator& other) const{
            return this->c == other.c;
        }
        bool operator!=(const const_iterator& other) const{
            return !(*this == other);
        }

        const Country& operator*(){
            return *c;
        }

        friend class Countries;
        friend class const_iterator;
    };

    class const_iterator{
    private:
        std::set<Country>::const_iterator c;
        const_iterator(std::set<Country>::const_iterator orig) : c(orig){}

    public:
        const_iterator(){}
        const_iterator(const iterator it){
            c = it.c;
        }
        const_iterator(const const_iterator &other){
            c = other.c;
        }
        const_iterator& operator=(const const_iterator &other){
            c = other.c;
            return *this;
        }

        const_iterator& operator++(){
            ++c;
            return *this;
        }
        const_iterator operator++(int){
            const_iterator aux = *this;
            --(*this);
            return aux;
        }

        const_iterator& operator--(){
            --c;
            return *this;
        }
        const_iterator operator--(int){
            const_iterator aux = *this;
            --(*this);
            return aux;
        }

        bool operator==(const const_iterator& other) const{
            return this->c == other.c;
        }
        bool operator!=(const const_iterator& other) const{
            return !(*this == other);
        }

        const Country& operator*() const{
            return *c;
        }

        friend class Countries;
    };

    iterator begin(){
        Countries::iterator aux;
        aux.c = countries.begin();
        return aux;
    }

    iterator end(){
        Countries::iterator aux;
        aux.c = countries.end();
        return aux;
    }

    const_iterator cbegin() const{
        Countries::const_iterator aux;
        aux.c = countries.cbegin();
        return aux;
    }

    const_iterator cend() const{
        Countries::const_iterator aux;
        aux.c = countries.cend();
        return aux;
    }

    const_iterator find(const Country &country) const;
    const_iterator find(const Coord &point) const;


    friend std::ostream& operator<<(std::ostream& os, const Countries& c);
    friend std::istream& operator>>(std::istream& is, Countries& c);
};




#endif //PRACTICAFINAL_COUNTRIES_H
