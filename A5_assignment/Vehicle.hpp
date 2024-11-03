#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <string>

class Vehicle {
protected:
    std::string name;
    int capacity;
    int currentLoad;
    double dollarRatePerPound;

public:
    Vehicle(const std::string& n, int cap, double rate);
    virtual ~Vehicle() = default;
    void setCurrentLoad(int load);
    virtual double calculateLoss() const;
    std::string getName() const;
};

#endif