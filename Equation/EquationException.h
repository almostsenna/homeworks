#pragma once
#pragma once
#ifndef EQUATIONEXCEPTION_H
#define EQUATIONEXCEPTION_H

#include <exception>
#include <string>

// Базовий клас для всіх винятків рівнянь
class EquationException : public std::exception {
protected:
    std::string message;

public:
    EquationException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Математичні винятки
class MathException : public EquationException {
public:
    MathException(const std::string& msg) : EquationException(msg) {}
};

// Виняток, якщо у нас некоректне рівняння
class InvalidEquationException : public MathException {
public:
    InvalidEquationException(const std::string& msg)
        : MathException(msg) {
    }
};

// Безліч розв'язків
class InfiniteSolutionsException : public MathException {
public:
    InfiniteSolutionsException()
        : MathException("Equation has infinitely many solutions") {
    }
};

// Немає дійсних коренів
class NoRealRootsException : public MathException {
public:
    NoRealRootsException()
        : MathException("Equation has no real roots") {
    }
};

// Немає розв'язків
class NoSolutionException : public MathException {
public:
    NoSolutionException()
        : MathException("Equation has no solutions") {
    }
};

#endif