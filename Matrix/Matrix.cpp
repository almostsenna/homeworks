#include "Matrix.h"

template <typename T>
void Matrix<T>::allocateMemory() {
    data = new T * [rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new T[cols];
    }
}

template <typename T>
void Matrix<T>::freeMemory() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

template <typename T>
Matrix<T>::Matrix(int r, int c) : rows(r), cols(c) {
    allocateMemory();
}

template <typename T>
Matrix<T>::~Matrix() {
    freeMemory();
}

template <typename T>
void Matrix<T>::fillFromKeyboard() {
    std::cout << "Enter elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> data[i][j];
        }
    }
}

template <typename T>
void Matrix<T>::fillRandom(T minVal, T maxVal) {
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = minVal + rand() % (maxVal - minVal + 1);
        }
    }
}

template <typename T>
void Matrix<T>::display() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << "\n";
    }
}

template <typename T>
T Matrix<T>::getMax() const {
    T maxVal = data[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (data[i][j] > maxVal) maxVal = data[i][j];
        }
    }
    return maxVal;
}

template <typename T>
T Matrix<T>::getMin() const {
    T minVal = data[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (data[i][j] < minVal) minVal = data[i][j];
        }
    }
    return minVal;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const {
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const {
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] * other.data[i][j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const Matrix<T>& other) const {
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] / other.data[i][j];
        }
    }
    return result;
}
template class Matrix<int>;