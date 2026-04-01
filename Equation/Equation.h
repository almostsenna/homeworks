#pragma once
#ifndef EQUATION_H
#define EQUATION_H

#include <vector>

// Абстрактний базовий клас
class Equation {
public:
    virtual ~Equation() = default;

    // Віртуальна функція для обчислення коренів
    virtual std::vector<double> solve() const = 0; // люблю я вектори, дуже класна штука))
};

#endif 