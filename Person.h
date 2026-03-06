#pragma once
#ifndef PERSON_H
#define PERSON_H

class Person {
    char* name;
    int age;
public:
    Person(const char* n = "NoName", int a = 0);
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    void print() const;
};

#endif