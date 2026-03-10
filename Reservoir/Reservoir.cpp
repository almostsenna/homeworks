#include "Reservoir.h"
#include <cstring>

using namespace std;

void Reservoir::copyString(char*& destination, const char* source) {
    if (source == nullptr) {
        destination = new char[1];
        destination[0] = '\0';
        return;
    }

    size_t len = strlen(source);
    destination = new char[len + 1];
    strcpy_s(destination, len + 1, source);
}

Reservoir::Reservoir()
    : name(nullptr), type(nullptr), width(0), length(0), maxDepth(0) {
    copyString(name, "Unknown");
    copyString(type, "Unknown");
}

Reservoir::Reservoir(const char* name)
    : name(nullptr), type(nullptr), width(0), length(0), maxDepth(0) {
    copyString(this->name, name);
    copyString(type, "Unknown");
}

Reservoir::Reservoir(const char* name, const char* type, double width, double length, double maxDepth)
    : name(nullptr), type(nullptr), width(width), length(length), maxDepth(maxDepth) {
    copyString(this->name, name);
    copyString(this->type, type);
}

Reservoir::Reservoir(const Reservoir& other)
    : name(nullptr), type(nullptr), width(other.width), length(other.length), maxDepth(other.maxDepth) {
    copyString(name, other.name);
    copyString(type, other.type);
}

Reservoir& Reservoir::operator=(const Reservoir& other) {
    if (this != &other) {
        delete[] name;
        delete[] type;

        copyString(name, other.name);
        copyString(type, other.type);
        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;
    }
    return *this;
}

Reservoir::~Reservoir() {
    delete[] name;
    delete[] type;
}

void Reservoir::setName(const char* name) {
    delete[] this->name;
    copyString(this->name, name);
}

void Reservoir::setType(const char* type) {
    delete[] this->type;
    copyString(this->type, type);
}

void Reservoir::setWidth(double width) {
    if (width > 0)
        this->width = width;
}

void Reservoir::setLength(double length) {
    if (length > 0)
        this->length = length;
}

void Reservoir::setMaxDepth(double maxDepth) {
    if (maxDepth > 0)
        this->maxDepth = maxDepth;
}

const char* Reservoir::getName() const {
    return name;
}

const char* Reservoir::getType() const {
    return type;
}

double Reservoir::getWidth() const {
    return width;
}

double Reservoir::getLength() const {
    return length;
}

double Reservoir::getMaxDepth() const {
    return maxDepth;
}

double Reservoir::getVolume() const {
    return width * length * maxDepth;
}

double Reservoir::getSurfaceArea() const {
    return width * length;
}

bool Reservoir::isSameType(const Reservoir& other) const {
    return strcmp(type, other.type) == 0;
}

int Reservoir::compareSurfaceArea(const Reservoir& other) const {
    if (!isSameType(other)) {
        return 2; // різні типи
    }

    double thisArea = getSurfaceArea();
    double otherArea = other.getSurfaceArea();

    if (thisArea > otherArea)
        return 1;
    if (thisArea < otherArea)
        return -1;
    return 0;
}

void Reservoir::print() const {
    cout << "Name: " << name << endl;
    cout << "Type: " << type << endl;
    cout << "Width: " << width << endl;
    cout << "Length: " << length << endl;
    cout << "Max depth: " << maxDepth << endl;
    cout << "Surface area: " << getSurfaceArea() << endl;
    cout << "Volume: " << getVolume() << endl;
}