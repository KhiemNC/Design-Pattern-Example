#include <iostream>
#include <string>

using namespace std;

// Target interface
class Customer {
    public:
    virtual void request(string product) = 0;
};

// Adaptee interface
class Developer {
    public:
    void develop(string product, string deadline) { // Specific request
        cout << "Developing " << product << " until " << deadline << endl;
    }
};

// Adapter (role of an Customer Service)
class DeveloperAdapter : public Customer {
    private:
    Developer* developer;
    
    public:
    DeveloperAdapter(Developer* developer) { this->developer = developer; }
    
    void request(string product) override {
        developer->develop(product, "tomorrow");
    }
};

int main(int argc, char* argv[]) {
    Developer* developer = new Developer();
    Customer* customer = new DeveloperAdapter(developer);
    customer->request("Mobile App");
    
    delete developer;
    delete customer;
    return 0;
}

/* Output: */
/*
Developing Mobile App until tomorrow
*/