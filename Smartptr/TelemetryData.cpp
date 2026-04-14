#include "TelemetryData.h"
#include <iostream>

using namespace std;

TelemetryData::TelemetryData()
    : driverName("Unknown"), lap(0), tyreWear(0.0) {
    cout << "Telemetry created for " << driverName << "\n";
}

TelemetryData::TelemetryData(const string& driverName, int lap, double tyreWear)
    : driverName(driverName), lap(lap), tyreWear(tyreWear) {
    cout << "Telemetry created for " << driverName << "\n";
}

TelemetryData::~TelemetryData() {
    cout << "Telemetry destroyed for " << driverName << "\n";
}

void TelemetryData::nextLap() {
    lap++;
    tyreWear += 4.5;
}

void TelemetryData::show() const {
    cout << "Telemetry -> Driver: " << driverName
        << ", Lap: " << lap
        << ", Tyre wear: " << tyreWear << "%\n";
}