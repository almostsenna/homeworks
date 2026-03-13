#include <iostream>
#include "Fraction.h"
using namespace std;

int main() {
    Fraction a, b;

    cout << "Entering the first fraction:\n";
    cin >> a;

    cout << "Entering the second fraction:\n";
    cin >> b;

    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n";

    cout << "a + b = " << (a + b) << "\n";
    cout << "a - b = " << (a - b) << "\n";
    cout << "a * b = " << (a * b) << "\n";
    cout << "a / b = " << (a / b) << "\n";

    return 0;
}