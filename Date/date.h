#pragma once
#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
    int day, month, year;
    int daysInMonth(int m, int y) const;

public:
    // конструктор))
    Date(int d = 1, int m = 1, int y = 2000);

    // Member function
    void nextDay();

    // оператори
    Date& operator++();        // prefix ++
    Date operator++(int);      // postfix ++
    Date& operator--();        // prefix --
    Date operator--(int);      // postfix --

    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;

    Date& operator=(const Date& other);
    Date& operator+=(int n);
    Date& operator-=(int n);

    // оператори для введення і виведення
    friend std::ostream& operator<<(std::ostream& os, const Date& d);
    friend std::istream& operator>>(std::istream& is, Date& d);
};

#endif