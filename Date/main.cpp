#include <iostream>
#include "Date.h"
using namespace std;

int main() {
    Date d1(28, 2, 2024); // leap year
    cout << "Initial date: " << d1 << endl;

    ++d1;
    cout << "After ++: " << d1 << endl;

    Date d2(1, 3, 2024);
    cout << "d1 == d2 ? " << (d1 == d2 ? "Yes" : "No") << endl;

    d1 += 10;
    cout << "After +=10: " << d1 << endl;

    d1 -= 5;
    cout << "After -=5: " << d1 << endl;

    return 0;
}