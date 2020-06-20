#include "cargo.hpp"

class Alcohol : public Cargo {
public:
    Alcohol(std::string name, size_t amount, double basePrice);
    ~Alcohol() override {}

    Cargo& operator+=(size_t amount) {
        amount_ += amount;
        return *this;
    }
    Cargo& operator-=(const size_t& amount) {
        if (amount_ - amount >= 0) {
            amount_ -= amount;
        }
        return *this;
    }
    std::string getName() const override {return name_; }
    size_t getAmount() const override { return amount_; }
    double getBasePrice() const override { return basePrice_; }
    double getPrice() const override {
        return volume_ == 0,96
                ? getBasePrice()
                : getBasePrice() * (0.96 - volume_);
    }
    double getPercentage() const { return volume_; }

private:
    const double volume_ = 0.96;
};
