#include "Fraction.h"

// Конструктор
Fraction::Fraction(int num, int den) {
    if (den == 0) {
        std::cout << "Error: the denominator cannot be zero!( \n";
        denominator = 1;
        numerator = num;
    }
    else {
        numerator = num;
        denominator = den;
        simplify();
    }
}

// Алгоритм Евкліда для НСД
void Fraction::simplify() {
    int a = numerator;
    int b = denominator;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = (a == 0) ? 1 : a;
    numerator /= gcd;
    denominator /= gcd;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Оператори)
Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(numerator * other.denominator + other.numerator * denominator,
        denominator * other.denominator);
}

Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(numerator * other.denominator - other.numerator * denominator,
        denominator * other.denominator);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator,
        denominator * other.denominator);
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        std::cout << "Error: division by zero!( \n";
        return Fraction(0, 1);
    }
    return Fraction(numerator * other.denominator,
        denominator * other.numerator);
}

// Вивід
std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    out << f.numerator << "/" << f.denominator;
    return out;
}

// Ввід
std::istream& operator>>(std::istream& in, Fraction& f) {
    std::cout << "Enter the numerator: ";
    in >> f.numerator;
    std::cout << "Enter the denominator: ";
    in >> f.denominator;

    if (f.denominator == 0) {
        std::cout << "Error: the denominator cannot be zero!( Changed to 1. \n";
        f.denominator = 1;
    }
    f.simplify();
    return in;
}