#include "Apartment.h"
#include <iostream>
using namespace std;

Apartment::Apartment(int c) {
    count = c;
    if (count > 0)
        people = new Person[count];
    else
        people = nullptr;
}

Apartment& Apartment::operator=(const Apartment& other) {
    if (this == &other) return *this;
    delete[] people;
    count = other.count;
    if (count > 0) {
        people = new Person[count];
        for (int i = 0; i < count; i++)
            people[i] = other.people[i]; 
    } else {
        people = nullptr;
    }
    return *this;
}


Apartment::~Apartment() {
    delete[] people;
}

void Apartment::setPerson(int index, const Person& p) {
    if (index >= 0 && index < count)
        people[index] = p;
}

void Apartment::print() const {
    cout << "Apartment, residents: " << count << endl;
    for (int i = 0; i < count; i++) {
        cout << "  ";
        people[i].print();
    }
}