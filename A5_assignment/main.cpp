#include <iostream>
#include <list>
#include "Truck.hpp"
#include "ContainerShip.hpp"

int main() {
    int numTrucks, numShips;
    std::cout << "Enter the number of trucks: ";
    std::cin >> numTrucks;

    std::list<Vehicle*> vehicles;

    for (int i = 0; i <= numTrucks-1; ++i) {
        std::string type;
        int capacity, load;
        double cost;
        std::cout << "Enter details for truck " << i + 1 << " (type capacity load cost): ";
        std::cin >> type >> capacity >> load >> cost;
        vehicles.push_back(new Truck(type, capacity, cost));
        vehicles.back()->setCurrentLoad(load);
    }

    std::cout << "Enter the number of container ships: ";
    std::cin >> numShips;

    for (int i = 0; i <= numShips-1; ++i) {
        std::string type;
        int capacity, load;
        double cost;
        std::cout << "Enter details for container ship " << i + 1 << " (type, capacity, load, cost): ";
        std::cin >> type >> capacity >> load >> cost;
        vehicles.push_back(new ContainerShip(type, capacity, cost));
        vehicles.back()->setCurrentLoad(load);
    }

    double totalLoss = 0;

    for (auto v : vehicles) {
        double loss = v->calculateLoss();
        std::cout << v->getName() << " Loss: $" << loss << std::endl;
        totalLoss += loss;
    }

    std::cout << "Total loss = $" << (-1*totalLoss) << std::endl;

    return 0;
}
