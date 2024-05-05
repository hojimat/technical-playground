/* 
Category:
- creational design pattern

Implementation:
- abstract class Creator with factory method
- concrete Creator that implements factory method
- abstract example class
- concrete example class

Caveats:
- violates Single Responsibility Principle from SOLID
- is good for Files or Databases
- whenever you create a new object, you get just the first one
- normal constructors cannot do it
*/

#include <iostream>

// Abstract product
class Transport {
public:
    virtual void deliver() = 0;
};

// Concrete products
class Truck : public Transport {
public:
    void deliver() override {
        std::cout << "Deliver via truck\n";
    }
};

class Ship : public Transport {
public:
    void deliver() override {
        std::cout << "Deliver via Ship\n";
    }
};

// Abstract creator
class Logistics {
public:
    virtual Transport* createTransport() = 0;

    void planDelivery() {
        Transport* transport = createTransport();
        transport->deliver();
        delete transport;
    }

};

// Concrete creator
class RoadLogistics : public Logistics {
public:
    Transport* createTransport() override {
        return new Truck();
    }
};

class SeaLogistics : public Logistics {
public:
    Transport* createTransport() override {
        return new Ship();
    }
};


int main() {
    Logistics* roadLogistics = new RoadLogistics();
    Logistics* seaLogistics = new SeaLogistics();

    roadLogistics->planDelivery();
    seaLogistics->planDelivery();

    delete roadLogistics;
    delete seaLogistics;

    return 0;
}