#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include <iostream>
#include <cstring>

using namespace std;

Person::Person(const char* n, int a) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    age = a;
}

Person& Person::operator=(const Person& other) {
    if (this == &other) return *this; // перевірка самоприсвоєння
    delete[] name;
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    age = other.age;
    return *this;
}


Person::~Person() {
    delete[] name;
}

void Person::print() const {
    cout << "Name: " << name << ", Age: " << age << endl;
}