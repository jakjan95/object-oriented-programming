#pragma once

#include <cmath>
#include <string>

class Cargo {
public:
    Cargo();
    Cargo(std::string name, size_t ammount, double basePrice);

    virtual double getPrice() const = 0;
    virtual std::string getName() const = 0;
    virtual size_t getAmmount() const = 0;
    virtual double getBasePrice() const = 0;

    Cargo& operator+=(const size_t& ammount);
    Cargo& operator-=(const size_t& ammount);
    bool operator==(const Cargo& freight2);

protected:
    std::string name_;
    size_t ammount_;
    double basePrice_;
};

class Fruit : public Cargo {
    size_t getRottenTime() const { return timeToRotten_; }
    std::string getName() const override { return name_; };
    double getPrice() const override {
        return basePrice_ * (1 / std::exp(timeToRotten_));
    }
    double getBasePrice() const override { return basePrice_; }
    virtual size_t getAmmount() const override { return ammount_; }

    Fruit& operator--() {
        if (timeToRotten_ > 0) {
            timeToRotten_--;
        }
        return *this;
    }

private:
    size_t timeToRotten_;
};

class Alcohol : public Cargo {
    std::string getName() const override { return name_; };
    double getPrice() const override {
        if (volume_ == 0.96) {
            return getBasePrice();
        }
        return getBasePrice() * (0.96 - volume_);
    }

    double getBasePrice() const override { return basePrice_; }
    virtual size_t getAmmount() const override { return ammount_; }

private:
    const double volume_ = 0.96;
};

enum class Rarity {
    common = 1,
    rare = 2,
    epic = 5,
    legendary = 10,
};

class Item : public Cargo {
    std::string getName() const override { return name_; };
    double getPrice() const override { return getBasePrice() * static_cast<int>(rare); }

    double getBasePrice() const override { return basePrice_; }
    virtual size_t getAmmount() const override { return ammount_; }

private:
    Rarity rare;
};

int main() {
    Fruit fruit;
    return 0;
}