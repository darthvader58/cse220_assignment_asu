#ifndef Truck_hpp
#define Truck_hpp

#include "Vehicle.hpp"

class Truck : public Vehicle {
public:
    Truck(const std::string& n, int cap, double rate);
};

#endif