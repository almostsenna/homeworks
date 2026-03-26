#include "child2.h"

int main() {
    // можна уявити, що ми змоделювали машину для перегонів: (я люблю перегони, що я пороблю))
    // value1 - назва машини
    // value2 – максимальна швидкість
    // value3 – потужність двигуна
    // value4 – вага
    // value5 – тип пального
    // value6 – рік випуску

    Child2<std::string, int, int, double, std::string, int> raceCar(
        "Ferrari F1", 350, 1000, 750.5, "Petrol", 2025
    );

    raceCar.show();

    return 0;
}