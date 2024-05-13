#include <iostream>
#include <string>

using namespace std;

// Product
class Transport {
    public:
    virtual void deliver() = 0;
};

// ConcreteProduct
class Truck : public Transport {
    public:
    void deliver() override {
        cout << "Deliver by truck\n";
    }
};
class Ship : public Transport {
    public:
    void deliver() override {
        cout << "Deliver by ship\n";
    }
};

// Creator
class TransportFactory {
    public:
    virtual Transport* createTransport() = 0; // FactoryMethod
};

// ConcreteCreator
class TruckFactory : public TransportFactory {
    public:
    Transport* createTransport() override {
        return new Truck();
    }
};
class ShipFactory : public TransportFactory {
    public:
    Transport* createTransport() override {
        return new Ship();
    }
};

int main(int argc, char* argv[]) {
    TransportFactory* factory1 = new TruckFactory();
    Transport* transport1 = factory1->createTransport();
    transport1->deliver();
    TransportFactory* factory2 = new ShipFactory();
    Transport* transport2 = factory2->createTransport();
    transport2->deliver();

    delete factory1;
    delete transport1;
    delete factory2;
    delete transport2;
    return 0;
}

/* Output: */
/*
Deliver by truck
Deliver by ship
*/