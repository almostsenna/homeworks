#include "LinearEquation.h"
#include <stdexcept>
#include "EquationException.h"

std::vector<double> LinearEquation::solve() const {
    if (a == 0 && b == 0) {
        throw InfiniteSolutionsException();
    }

    if (a == 0 && b != 0) {
        throw NoSolutionException();
    }

    return { -b / a };
}
// трішки дороблений виняток, бо тоді був виняток під час виконання, а нам треба власних класів)