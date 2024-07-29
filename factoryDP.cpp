// 1
#include <iostream>

// Transport Interface
class Transport {
public:
    virtual void deliver() = 0; // Pure virtual function
    virtual ~Transport() {}
};

//--------------------------------------------------------------
// 2: Concrete Transport Products
// -------------------------------------------------------------

// Concrete Product: Truck
class Truck : public Transport {
public:
    void deliver() override {
        std::cout << "Deliver by land in a box." << std::endl;
    }
};

// Concrete Product: Ship
class Ship : public Transport {
public:
    void deliver() override {
        std::cout << "Deliver by sea in a container." << std::endl;
    }
};

//--------------------------------------------------------------
// 3:  Abstract Factory Interface
// -------------------------------------------------------------

// Abstract Factory Interface
class TransportFactory {
public:
    virtual Transport* createTransport() = 0; // Pure virtual function
    virtual ~TransportFactory() {}
};

//--------------------------------------------------------------
// 4: Concrete Factory Classes
// -------------------------------------------------------------

// Concrete Factory for Truck
class TruckFactory : public TransportFactory {
public:
    Transport* createTransport() override {
        return new Truck();
    }
};

// Concrete Factory for Ship
class ShipFactory : public TransportFactory {
public:
    Transport* createTransport() override {
        return new Ship();
    }
};

//////////////////////////////////////////////////////////////
// 5
//////////////////////////////////////////////////////////////
// Client Code

int main() {
    TransportFactory* factory;
    Transport* transport;

    // Create Truck using TruckFactory
    factory = new TruckFactory();
    transport = factory->createTransport();
    if (transport) {
        transport->deliver();
        delete transport;
    }
    delete factory;

    // Create Ship using ShipFactory
    factory = new ShipFactory();
    transport = factory->createTransport();
    if (transport) {
        transport->deliver();
        delete transport;
    }
    delete factory;



    return 0;
}

