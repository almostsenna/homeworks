#include "House.h"
#include <iostream>
using namespace std;

House::House(int c) {
    count = c;
    if (count > 0)
        apartments = new Apartment[count];
    else
        apartments = nullptr;
}

House& House::operator=(const House& other) {
    if (this == &other) return *this;
    delete[] apartments;
    count = other.count;
    if (count > 0) {
        apartments = new Apartment[count];
        for (int i = 0; i < count; i++)
            apartments[i] = other.apartments[i]; // викликається Apartment::operator=
    }
    else {
        apartments = nullptr;
    }
    return *this;
}


House::~House() {
    delete[] apartments;
}

void House::setApartment(int index, const Apartment& a) {
    if (index >= 0 && index < count)
        apartments[index] = a;
}

void House::print() const {
    cout << "House, apartments: " << count << endl;
    for (int i = 0; i < count; i++) {
        cout << "Apartment #" << i + 1 << ":" << endl;
        apartments[i].print();
    }
}