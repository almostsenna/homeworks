#pragma once
#include <string>

class TelemetryData {
private:
    std::string driverName;
    int lap;
    double tyreWear;

public:
    TelemetryData();
    TelemetryData(const std::string& driverName, int lap, double tyreWear);
    ~TelemetryData();

    void nextLap();
    void show() const;
};