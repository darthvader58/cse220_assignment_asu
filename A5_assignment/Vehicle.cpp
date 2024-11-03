#include "Vehicle.hpp"

Vehicle::Vehicle(const std::string& n, int cap, double rate)
: name(n), capacity(cap), currentLoad(0), dollarRatePerPound(rate) {}

void Vehicle::setCurrentLoad(int load) {
    currentLoad = load;
}

double Vehicle::calculateLoss() const {
    return (capacity - currentLoad) * dollarRatePerPound;
}

std::string Vehicle::getName() const {
    return name;
}