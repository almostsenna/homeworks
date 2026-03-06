#pragma once
#ifndef APARTMENT_H
#define APARTMENT_H
#include "Person.h"

class Apartment {
    Person* people;
    int count;
public:
    Apartment(int c = 0);
    Apartment(const Apartment& other);
    Apartment& operator=(const Apartment& other);
    ~Apartment();

    void setPerson(int index, const Person& p);
    void print() const;
};

#endif