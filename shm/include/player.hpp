#pragma once
#include <memory>

#include "ship.hpp"
#include "time.hpp"

class Player : public Ship::Delegate {
public:
    Player(size_t money, std::shared_ptr<Time> time);
    virtual ~Player();

    std::shared_ptr<Ship> generateShip(std::shared_ptr<Time> time);
    std::shared_ptr<Ship> getShip() const { return ship_; }
    size_t getMoney() const { return money_; }
    size_t getSpeed() const { return ship_->getSpeed(); }
    cargoPtr getCargo(size_t index) const { return ship_->getCargo()[index]; }
    size_t getAvailableSpace() const;
    void setShip(const std::shared_ptr<Ship>& ship);
    void addMoney(const size_t& money);
    void payCrew(size_t money) override;
    void subtractMoney(const size_t& money);
    void printCargo() const;

private:
    std::shared_ptr<Ship> ship_;
    size_t money_;
    size_t availableSpace_;
};
