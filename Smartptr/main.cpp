#include <iostream>
#include <utility>
#include "MyUniquePtr.h"
#include "MySharedPtr.h"
#include "Engine.h"
#include "TelemetryData.h"

using namespace std;

void testUniquePtr() {
    cout << "\n================ UNIQUE PTR TEST ================\n";

    MyUniquePtr<Engine> engine1(new Engine("Ferrari", 1050));

    if (engine1) {
        engine1->start();
        engine1->upgrade(15);
        (*engine1).show();
    }

    cout << "\nMove ownership from engine1 to engine2\n";
    MyUniquePtr<Engine> engine2 = std::move(engine1);

    cout << "engine1 valid? " << (engine1 ? "Yes" : "No") << "\n";
    cout << "engine2 valid? " << (engine2 ? "Yes" : "No") << "\n";

    if (engine2) {
        engine2->show();
    }

    cout << "\nReset engine2 with Mercedes engine\n";
    engine2.reset(new Engine("Mercedes", 1025));
    engine2->show();

    cout << "\nRelease raw pointer from engine2\n";
    Engine* rawEngine = engine2.release();

    cout << "engine2 valid after release? " << (engine2 ? "Yes" : "No") << "\n";

    if (rawEngine) {
        rawEngine->show();
    }

    cout << "Manual delete rawEngine\n";
    delete rawEngine;
}

void testSharedPtr() {
    cout << "\n================ SHARED PTR TEST ================\n";

    MySharedPtr<TelemetryData> telemetry1(
        new TelemetryData("Verstappen", 12, 37.5)
    );

    cout << "telemetry1 use_count = " << telemetry1.use_count() << "\n";
    telemetry1->show();

    {
        cout << "\nCopy telemetry1 to telemetry2\n";
        MySharedPtr<TelemetryData> telemetry2 = telemetry1;

        cout << "telemetry1 use_count = " << telemetry1.use_count() << "\n";
        cout << "telemetry2 use_count = " << telemetry2.use_count() << "\n";

        {
            cout << "\nCopy telemetry2 to telemetry3\n";
            MySharedPtr<TelemetryData> telemetry3 = telemetry2;

            cout << "telemetry1 use_count = " << telemetry1.use_count() << "\n";
            cout << "telemetry2 use_count = " << telemetry2.use_count() << "\n";
            cout << "telemetry3 use_count = " << telemetry3.use_count() << "\n";

            telemetry3->nextLap();
            telemetry3->show();
        }

        cout << "\ntelemetry3 destroyed (left block)\n";
        cout << "telemetry1 use_count = " << telemetry1.use_count() << "\n";
        cout << "telemetry2 use_count = " << telemetry2.use_count() << "\n";
    }

    cout << "\ntelemetry2 destroyed (left block)\n";
    cout << "telemetry1 use_count = " << telemetry1.use_count() << "\n";

    cout << "\nReset telemetry1\n";
    telemetry1.reset();

    cout << "telemetry1 use_count after reset = " << telemetry1.use_count() << "\n";
    cout << "telemetry1 valid? " << (telemetry1 ? "Yes" : "No") << "\n";
}

int main() {
    testUniquePtr();
    testSharedPtr();

    cout << "\nProgram finished successfully.\n";
    return 0;
}