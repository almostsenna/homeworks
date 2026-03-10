#include <iostream>
#include "ReservoirArray.h"

using namespace std;

void showMenu() {
    cout << "\nMenu: \n";
    cout << "1. Add reservoir\n";
    cout << "2. Remove reservoir\n";
    cout << "3. Show all reservoirs\n";
    cout << "4. Compare two reservoirs by area\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
}

int main() {
    ReservoirArray arr;
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            char name[100];
            char type[100];
            double width, length, depth;

            cout << "Enter name: ";
            cin.getline(name, 100);

            cout << "Enter type: ";
            cin.getline(type, 100);

            cout << "Enter width: ";
            cin >> width;

            cout << "Enter length: ";
            cin >> length;

            cout << "Enter max depth: ";
            cin >> depth;
            cin.ignore();

            Reservoir r(name, type, width, length, depth);
            arr.add(r);
        }
        else if (choice == 2) {
            int index;
            cout << "Enter index to remove: ";
            cin >> index;
            cin.ignore();

            arr.removeAt(index - 1);
        }
        else if (choice == 3) {
            arr.printAll();
        }
        else if (choice == 4) {
            cout << "Comparison can be added similarly.\n";
        }

    } while (choice != 0);

    return 0;
}