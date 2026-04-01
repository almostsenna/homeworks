#include "LinearEquation.h"
#include <stdexcept>

std::vector<double> LinearEquation::solve() const {
    if (a == 0) {
        throw std::runtime_error("No solution or infinite solutions"); //виняток під час виконання)
    }
    return { -b / a }; 
}