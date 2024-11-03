#ifndef ContainerShip_hpp
#define ContainerShip_hpp 

#include "Vehicle.hpp"

class ContainerShip : public Vehicle {
public:
    ContainerShip(const std::string& n, int cap, double rate);
};

#endif 
