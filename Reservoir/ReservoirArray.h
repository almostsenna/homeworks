#pragma once
#pragma once
#include "Reservoir.h"

class ReservoirArray {
private:
    Reservoir* data;
    int size;

public:
    ReservoirArray();
    ~ReservoirArray();

    int getSize() const;
    void add(const Reservoir& reservoir);
    void removeAt(int index);
    void printAll() const;
};