#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Matrix {
private:
    int rows;
    int cols;
    T** data;

    void allocateMemory();
    void freeMemory();

public:
    Matrix(int r, int c);
    ~Matrix();

    void fillFromKeyboard();
    void fillRandom(T minVal, T maxVal);
    void display() const;

    T getMax() const;
    T getMin() const;

    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator-(const Matrix<T>& other) const;
    Matrix<T> operator*(const Matrix<T>& other) const;
    Matrix<T> operator/(const Matrix<T>& other) const;
};

#endif