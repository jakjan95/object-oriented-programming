#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "cargo.hpp"

class Ship {
public:
    Ship();
    Ship(size_t id, std::string name, size_t speed, size_t maxCrew, size_t capacity);
    Ship(size_t id, std::string name, size_t speed);

    int getId() const { return id_; }
    std::string getName() const { return name_; }
    size_t getSpeed() const { return speed_; }
    size_t getMaxCrew() const { return maxCrew_; }
    size_t getCapacity() const { return capacity_; }
    std::vector<std::shared_ptr<Cargo>> getCargo() const { return cargo_; }

    void setName(const std::string& name);

    Ship& operator+=(const size_t& crew);
    Ship& operator-=(const size_t& crew);

    void load(std::shared_ptr<Cargo> cargo) {
        //akumulacja tak zeby tego typu towary byly w jednym miejscu xD
        //np nie 2x po 5 jablek a jablek 10
        cargo_.push_back(cargo);
    }

    void unload(Cargo* cargo) {
        //nazwy znalexc i tez czasy do zepsucia 
        //zeby dobre znalezc
        auto it = std::find(cargo_.begin(), cargo_.end(), cargo);
        if (it != std::end(cargo_)) {
            if (cargo->getAmmount() == 1) {
                cargo_.erase(it);
            } else {
                it--;
            }
        }
    }

private:
    int id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_;
    std::vector<std::shared_ptr<Cargo>> cargo_;
};
