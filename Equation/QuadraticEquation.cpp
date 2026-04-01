#include "QuadraticEquation.h"
#include <cmath>
#include <stdexcept>

std::vector<double> QuadraticEquation::solve() const {
    if (a == 0) {
        throw std::runtime_error("Not a quadratic equation");
    }

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return {}; // немає дійсних коренів
    }
    else if (discriminant == 0) {
        return { -b / (2 * a) };
    }
    else {
        double sqrtD = std::sqrt(discriminant);
        return { (-b + sqrtD) / (2 * a), (-b - sqrtD) / (2 * a) };
    }
}