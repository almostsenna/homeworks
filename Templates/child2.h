#pragma once
#ifndef CHILD2_H
#define CHILD2_H

#include "child.h"

template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Child<T1, T2, T3, T4> {
protected:
    T5 value5;
    T6 value6;

public:
    Child2(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6)
        : Child<T1, T2, T3, T4>(v1, v2, v3, v4), value5(v5), value6(v6) {}

    ~Child2() {}

    void show() const override {
        Child<T1, T2, T3, T4>::show();
        std::cout << "Child2 values: " << value5 << ", " << value6 << std::endl;
    }
};

#endif