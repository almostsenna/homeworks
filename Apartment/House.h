#pragma once
#ifndef HOUSE_H
#define HOUSE_H
#include "Apartment.h"

class House {
    Apartment* apartments;
    int count;
public:
    House(int c = 0);
    House(const House& other);
    House& operator=(const House& other);
    ~House();

    void setApartment(int index, const Apartment& a);
    void print() const;
};

#endif
