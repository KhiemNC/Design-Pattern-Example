#include<iostream>
#include<string>

using namespace std;

// Colleague
class Airplane {
    protected:
    string name;
    
    public:
    Airplane(string name) { this->name = name; }
    virtual void send(string message) = 0;
    virtual void receive(string message) = 0;
};

// ConcreteColleague
class Airplane1 : public Airplane {
    public:
    Airplane1(string name) : Airplane(name) {}
    
    void send(string message) override {
        cout << name << " send: " << message << endl;
    }
    void receive(string message) override {
        cout << name << " receive: " << message << endl;
    }
};
class Airplane2 : public Airplane {
    public:
    Airplane2(string name) : Airplane(name) {}
    
    void send(string message) override {
        cout << name << " send: " << message << endl;
    }
    void receive(string message) override {
        cout << name << " receive: " << message << endl;
    }
};

// Mediator
class AirTrafficControl {
    public:
    virtual void send(string message, Airplane* airplane) = 0;
};

// ConcreteMediator
class AirTrafficControlCenter : public AirTrafficControl {
    private:
    Airplane1* airplane1;
    Airplane2* airplane2;
    
    public:
    void setAirplane1(Airplane1* airplane1) { this->airplane1 = airplane1; }
    void setAirplane2(Airplane2* airplane2) { this->airplane2 = airplane2; }
    
    void send(string message, Airplane* airplane) override {
        if (airplane == airplane1) {
            airplane1->send(message);
            airplane2->receive(message);
        } else {
            airplane2->send(message);
            airplane1->receive(message);
        }
    }
};

int main(int argc, char* argv[]) {
    Airplane1* airplane1 = new Airplane1("Airplane1");
    Airplane2* airplane2 = new Airplane2("Airplane2");
    
    AirTrafficControlCenter* atc = new AirTrafficControlCenter();
    atc->setAirplane1(airplane1);
    atc->setAirplane2(airplane2);
    
    atc->send("Hello", airplane1);
    atc->send("Hi", airplane2);
    
    delete airplane1;
    delete airplane2;
    delete atc;
    return 0;
}

/* Output: */
/*
Airplane1 send: Hello
Airplane2 receive: Hello
Airplane2 send: Hi
Airplane1 receive: Hi
*/