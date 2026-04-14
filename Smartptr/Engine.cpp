#include "Engine.h"
#include <iostream>

using namespace std;

Engine::Engine() : manufacturer("Unknown"), horsePower(0) {
    cout << "Engine created: " << manufacturer
        << ", " << horsePower << " HP\n";
}

Engine::Engine(const string& manufacturer, int horsePower)
    : manufacturer(manufacturer), horsePower(horsePower) {
    cout << "Engine created: " << manufacturer
        << ", " << horsePower << " HP\n";
}

Engine::~Engine() {
    cout << "Engine destroyed: " << manufacturer << "\n";
}

void Engine::start() const {
    cout << manufacturer << " engine starts! Power: "
        << horsePower << " HP\n";
}

void Engine::upgrade(int extraHP) {
    horsePower += extraHP;
}

void Engine::show() const {
    cout << "Engine: " << manufacturer
        << ", HP: " << horsePower << "\n";
}