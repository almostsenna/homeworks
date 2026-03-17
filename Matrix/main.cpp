#include "Matrix.h"

int main() {
    Matrix<int> A(3, 3);
    Matrix<int> B(3, 3);

    A.fillRandom(1, 10);
    B.fillRandom(1, 10);

    std::cout << "Matrix A:\n";
    A.display();

    std::cout << "Matrix B:\n";
    B.display();

    Matrix<int> C = A + B;
    std::cout << "A + B:\n";
    C.display();

    std::cout << "Max in A: " << A.getMax() << "\n";
    std::cout << "Min in A: " << A.getMin() << "\n";

    return 0;
}