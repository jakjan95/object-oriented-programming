#pragma once

#include <string>

#include "time.hpp"

class Cargo : public Observer {
public:
    Cargo() = default;
    Cargo(std::string name, size_t amount, double basePrice);
    virtual ~Cargo() = default;

    virtual double getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual size_t getAmount() const = 0;
    virtual double getBasePrice() const = 0;

    virtual Cargo& operator+=(const size_t& amount) = 0;
    virtual Cargo& operator-=(const size_t& amount) = 0;
    virtual bool operator==(Cargo& cargo) const = 0;

protected:
    std::string name_;
    size_t amount_;
    double basePrice_;
};
