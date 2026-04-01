#pragma once
#ifndef LINEAREQUATION_H
#define LINEAREQUATION_H

#include "Equation.h"

// Клас для лінійних рівнянь: ax + b = 0
class LinearEquation : public Equation {
private:
    double a, b;

public:
    LinearEquation(double a_, double b_) : a(a_), b(b_) {}

    std::vector<double> solve() const override;
};

#endif 