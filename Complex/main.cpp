#include <iostream>
#include "Complex.h"

int main() {
    Complex a, b;

    std::cout << "Input complex number a:" << std::endl;
    std::cin >> a;

    std::cout << "Input complex number b:" << std::endl;
    std::cin >> b;

    Complex sum = a + b;
    Complex diff = a - b;
    Complex prod = a * b;
    Complex quot = a / b;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

    std::cout << "a + b = " << sum << std::endl;
    std::cout << "a - b = " << diff << std::endl;
    std::cout << "a * b = " << prod << std::endl;
    std::cout << "a / b = " << quot << std::endl;

    return 0;
}