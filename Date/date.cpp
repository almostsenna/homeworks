#include "Date.h"

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

int Date::daysInMonth(int m, int y) const {
    switch (m) {
    case 2: return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) ? 29 : 28;
    case 4: case 6: case 9: case 11: return 30;
    default: return 31;
    }
}

void Date::nextDay() {
    day++;
    if (day > daysInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

// оператори ++ and --
Date& Date::operator++() { nextDay(); return *this; }
Date Date::operator++(int) { Date temp = *this; nextDay(); return temp; }

Date& Date::operator--() {
    day--;
    if (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day = daysInMonth(month, year);
    }
    return *this;
}
Date Date::operator--(int) { Date temp = *this; --(*this); return temp; }

// порівняння
bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}
bool Date::operator!=(const Date& other) const { return !(*this == other); }
bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}
bool Date::operator>(const Date& other) const { return other < *this; }

Date& Date::operator=(const Date& other) {
    if (this != &other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}

// оператори += and -=
Date& Date::operator+=(int n) {
    for (int i = 0; i < n; i++) nextDay();
    return *this;
}
Date& Date::operator-=(int n) {
    for (int i = 0; i < n; i++) --(*this);
    return *this;
}
//введення і виведення
std::ostream& operator<<(std::ostream& os, const Date& d) {
    os << d.day << "." << d.month << "." << d.year;
    return os;
}
std::istream& operator>>(std::istream& is, Date& d) {
    is >> d.day >> d.month >> d.year;
    return is;
}