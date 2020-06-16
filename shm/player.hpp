#pragma once
#include <memory>

#include "ship.hpp"

class Player {
public:
    Player(std::shared_ptr<Ship>, size_t, size_t);

    std::shared_ptr<Ship> getShip() const { return ship_; }
    size_t getMoeny() const { return money_; }
    size_t getAvailableSpeed() const { return availableSpace_; }
    size_t getSpeed() const { return ship_->getSpeed(); }
    //Cargo* getCargo(size_t index) const{;}

    void setShip(const std::shared_ptr<Ship>& ship);
    void addMoney(const size_t& money);
    void setAvailableSpace(const size_t& space);

private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
};
