#pragma once
#include <string>

class Engine {
private:
    std::string manufacturer;
    int horsePower;

public:
    Engine();
    Engine(const std::string& manufacturer, int horsePower);
    ~Engine();

    void start() const;
    void upgrade(int extraHP);
    void show() const;
};