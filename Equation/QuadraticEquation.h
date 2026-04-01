#pragma once
#ifndef QUADRATICEQUATION_H
#define QUADRATICEQUATION_H

#include "Equation.h"

// Клас для квадратних рівнянь: ax^2 + bx + c = 0
class QuadraticEquation : public Equation {
private:
    double a, b, c;

public:
    QuadraticEquation(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {}

    std::vector<double> solve() const override;
};

#endif // QUADRATICEQUATION_H