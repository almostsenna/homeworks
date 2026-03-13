#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>


class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0);

    // гєттери)
    double getReal() const;
    double getImag() const;

    // оператори
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    // метод)
    void print() const;
    //френд оператори для вводу/виводу)
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};


#endif