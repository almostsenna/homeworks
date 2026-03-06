#include "House.h"
#include "Apartment.h"
#include "Person.h"

int main() {
    Person p1("Oleg", 30);
    Person p2("Maria", 28);
    Person p3("Ivan", 45);

    Apartment a1(2);
    a1.setPerson(0, p1);
    a1.setPerson(1, p2);

    Apartment a2(1);
    a2.setPerson(0, p3);

    House h(2);
    h.setApartment(0, a1);
    h.setApartment(1, a2);

    h.print();

    return 0;
}