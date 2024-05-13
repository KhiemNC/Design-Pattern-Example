#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Observer;

// Subject
class ShopSubject {
    private:
    vector<class Observer*> observers;
    public:
    virtual void attach(class Observer* observer) = 0;
    virtual void detach(class Observer* observer) = 0;
    virtual void notify(string noti) = 0;
};

// Observer
class Observer {
    public:
    virtual void update(string noti) = 0;
};

// ConcreteSubject
class Shop : public ShopSubject {
    private:
    vector<class Observer*> observers;
    
    public:
    void attach(class Observer* observer) override {
        observers.push_back(observer);
    }
    void detach(class Observer* observer) override {
        for (int i = 0; i < observers.size(); i++) {
            if (observers[i] == observer) {
                observers.erase(observers.begin() + i);
                break;
            }
        }
    }
    void notify(string noti) override {
        for (auto observer : observers) {
            observer->update(noti);
        }
    }
};

// ConcreteObserver
class Customer : public Observer {
    private:
    string name;
    public:
    Customer(string name) : name(name) {}
    void update(string noti) override {
        cout << name << " received notification: " << noti << endl;
    }
};

int main() {
    Shop shop;
    Customer c1("Alice");
    Customer c2("Bob");
    Customer c3("Charlie");

    shop.attach(&c1);
    shop.attach(&c2);
    shop.attach(&c3);

    shop.notify("New product is available!");

    shop.detach(&c2);
    cout << "Bob unsubscribed--------------------------------------\n";

    shop.notify("Discount on all products!");

    return 0;
}

/* Output: */
/*
Alice received notification: New product is available!
Bob received notification: New product is available!
Charlie received notification: New product is available!
Bob unsubscribed--------------------------------------
Alice received notification: Discount on all products!
Charlie received notification: Discount on all products!
*/