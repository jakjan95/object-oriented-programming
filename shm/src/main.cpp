#include <iostream>

#include "cargo.hpp"
#include "fruit.hpp"
#include "map.hpp"
#include "ship.hpp"

int main() {
    std::cout << "Hello world";
    Cargo* cargo = nullptr;
    Fruit fruit("apple", 10, 2.3, 30);
    std::cout << fruit.getTimeToRotten();
    --fruit;
    std::cout << fruit.getTimeToRotten();
    fruit.nextDay();
    std::cout << fruit.getTimeToRotten() << '\n';
    auto fruitPtr = std::make_shared<Fruit>(fruit);
    Ship ship(01, "sheeeep", 40, 50, 50);
    ship.load(fruitPtr);
    Fruit fruit2("peer", 10, 2.3, 30);
    fruitPtr = std::make_shared<Fruit>(fruit2);
    ship.load(fruitPtr);
    ship.printCargo();

    return 0;
}
