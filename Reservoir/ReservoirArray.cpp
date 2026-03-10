#include "ReservoirArray.h"
#include <iostream>

using namespace std;

ReservoirArray::ReservoirArray() : data(nullptr), size(0) {}

ReservoirArray::~ReservoirArray() {
    delete[] data;
}

int ReservoirArray::getSize() const {
    return size;
}

void ReservoirArray::add(const Reservoir& reservoir) {
    Reservoir* newData = new Reservoir[size + 1];

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    newData[size] = reservoir;

    delete[] data;
    data = newData;
    size++;
}

void ReservoirArray::removeAt(int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index!\n";
        return;
    }

    Reservoir* newData = nullptr;

    if (size - 1 > 0) {
        newData = new Reservoir[size - 1];
    }

    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            newData[j++] = data[i];
        }
    }

    delete[] data;
    data = newData;
    size--;
}

void ReservoirArray::printAll() const {
    if (size == 0) {
        cout << "Array is empty:(\n";
        return;
    }

    for (int i = 0; i < size; i++) {
        cout << "\nReservoir #" << i + 1 << ":\n";
        data[i].print();
        cout << "----------------------\n";
    }
}