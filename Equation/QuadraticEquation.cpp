#include "QuadraticEquation.h"
#include "EquationException.h"
#include <cmath>

std::vector<double> QuadraticEquation::solve() const {
    if (a == 0) {
        throw InvalidEquationException("Coefficient a = 0, so this is not a quadratic equation");
    }

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        throw NoRealRootsException();
    }
    else if (discriminant == 0) {
        return { -b / (2 * a) };
    }
    else {
        double sqrtD = std::sqrt(discriminant);
        return { (-b + sqrtD) / (2 * a), (-b - sqrtD) / (2 * a) };
    }
}