#pragma once
#ifndef BASE_H
#define BASE_H

#include <iostream>

template<typename T1, typename T2>
class Base {
protected:
    T1 value1;
    T2 value2;

public:
    Base(T1 v1, T2 v2) : value1(v1), value2(v2) {}
    virtual ~Base() {}

    virtual void show() const {
        std::cout << "Base values: " << value1 << ", " << value2 << std::endl;
    }
};

#endif