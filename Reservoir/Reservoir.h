#pragma once
#include <iostream>

class Reservoir {
private:
    char* name;
    char* type;
    double width;
    double length;
    double maxDepth;

    void copyString(char*& destination, const char* source);

public:
    Reservoir();
    explicit Reservoir(const char* name);
    Reservoir(const char* name, const char* type, double width, double length, double maxDepth);
    Reservoir(const Reservoir& other);
    Reservoir& operator=(const Reservoir& other);
    ~Reservoir();

    void setName(const char* name);
    void setType(const char* type);
    void setWidth(double width);
    void setLength(double length);
    void setMaxDepth(double maxDepth);

    const char* getName() const;
    const char* getType() const;
    double getWidth() const;
    double getLength() const;
    double getMaxDepth() const;

    double getVolume() const;
    double getSurfaceArea() const;

    bool isSameType(const Reservoir& other) const;
    int compareSurfaceArea(const Reservoir& other) const;

    void print() const;
};