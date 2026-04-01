#include <iostream>
#include "LinearEquation.h"
#include "QuadraticEquation.h"

int main() {
    try {
        LinearEquation lin(2, -4); // 2x - 4 = 0 → x = 2
        auto rootsLin = lin.solve();
        std::cout << "Linear equation root: " << rootsLin[0] << "\n";

        QuadraticEquation quad(1, -3, 2); // x^2 - 3x + 2 = 0 → x=1,2
        auto rootsQuad = quad.solve();
        std::cout << "Quadratic equation roots: ";
        for (double r : rootsQuad) {
            std::cout << r << "  ";
        }
        std::cout << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}