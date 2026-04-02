#include <iostream>
#include "LinearEquation.h"
#include "QuadraticEquation.h"
#include "EquationException.h"

void solveEquation(const Equation& eq) {
    auto roots = eq.solve();

    if (roots.empty()) {
        std::cout << "No roots\n";
        return;
    }

    std::cout << "Roots: ";
    for (double r : roots) {
        std::cout << r << " ";
    }
    std::cout << "\n";
}

int main() {
    // 1. Нормальне лінійне рівняння
    try {
        std::cout << "Linear equation 2x - 4 = 0\n";
        LinearEquation lin(2, -4);
        solveEquation(lin);
    }
    catch (const EquationException& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    std::cout << "------------------------\n";

    // 2. Лінійне рівняння без розв'язків
    try {
        std::cout << "Linear equation 0x + 5 = 0\n";
        LinearEquation lin(0, 5);
        solveEquation(lin);
    }
    catch (const NoSolutionException& e) {
        std::cerr << "NoSolutionException: " << e.what() << "\n";
    }
    catch (const EquationException& e) {
        std::cerr << "EquationException: " << e.what() << "\n";
    }

    std::cout << "------------------------\n";

    // 3. Лінійне рівняння з безліччю розв'язків
    try {
        std::cout << "Linear equation 0x + 0 = 0\n";
        LinearEquation lin(0, 0);
        solveEquation(lin);
    }
    catch (const InfiniteSolutionsException& e) {
        std::cerr << "InfiniteSolutionsException: " << e.what() << "\n";
    }
    catch (const EquationException& e) {
        std::cerr << "EquationException: " << e.what() << "\n";
    }

    std::cout << "------------------------\n";

    // 4. Нормальне квадратне рівняння
    try {
        std::cout << "Quadratic equation x^2 - 3x + 2 = 0\n";
        QuadraticEquation quad(1, -3, 2);
        solveEquation(quad);
    }
    catch (const EquationException& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    std::cout << "------------------------\n";

    // 5. Квадратне рівняння без дійсних коренів
    try {
        std::cout << "Quadratic equation x^2 + x + 1 = 0\n";
        QuadraticEquation quad(1, 1, 1);
        solveEquation(quad);
    }
    catch (const NoRealRootsException& e) {
        std::cerr << "NoRealRootsException: " << e.what() << "\n";
    }
    catch (const MathException& e) {
        std::cerr << "MathException: " << e.what() << "\n";
    }

    std::cout << "------------------------\n";

    // 6. Некоректне квадратне рівняння
    try {
        std::cout << "Quadratic equation 0x^2 + 2x + 1 = 0\n";
        QuadraticEquation quad(0, 2, 1);
        solveEquation(quad);
    }
    catch (const InvalidEquationException& e) {
        std::cerr << "InvalidEquationException: " << e.what() << "\n";
    }
    catch (const EquationException& e) {
        std::cerr << "EquationException: " << e.what() << "\n";
    }

    return 0;
}