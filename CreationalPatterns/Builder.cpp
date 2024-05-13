#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Product
class Order {
    private:
    vector<string> items;
    string clientInfo;
    string shippingInfo;
    string paymentInfo;
    public:
    void addItem(string item) {
        items.push_back(item);
    }
    void setClientInfo(string clientInfo) {
        this->clientInfo = clientInfo;
    }
    void setShippingInfo(string shippingInfo) {
        this->shippingInfo = shippingInfo;
    }
    void setPaymentInfo(string paymentInfo) {
        this->paymentInfo = paymentInfo;
    }
    void showOrder() {
        cout << "Client: " << clientInfo << endl;
        cout << "Shipping: " << shippingInfo << endl;
        cout << "Payment: " << paymentInfo << endl;
        cout << "Items: ";
        for (auto item : items) {
            cout << item << ", ";
        }
        cout << endl;
    }
};

// Builder
class OrderBuilder {
    private:
    Order* order;
    public:
    OrderBuilder() { order = new Order(); }
    virtual void buildClientInfo() = 0;
    virtual void buildShippingInfo() = 0;
    virtual void buildPaymentInfo() = 0;
    virtual void buildItems() = 0;
    Order* getOrder() { return order; }
};

// ConcreteBuilder
class OrderBuilder1 : public OrderBuilder { // ConcreteBuilder1
    public:
    void buildClientInfo() override { getOrder()->setClientInfo("Client1"); }
    void buildShippingInfo() override { getOrder()->setShippingInfo("Shipping1"); }
    void buildPaymentInfo() override { getOrder()->setPaymentInfo("Payment1"); }
    void buildItems() override {
        getOrder()->addItem("Item1");
        getOrder()->addItem("Item2");
    }
};

class OrderBuilder2 : public OrderBuilder {}; // ConcreteBuilder2

// Director
class OrderDirector {
    private:
    OrderBuilder* orderBuilder;
    public:
    OrderDirector(OrderBuilder* orderBuilder) {
        this->orderBuilder = orderBuilder;
    }
    Order* construct() {
        orderBuilder->buildClientInfo();
        orderBuilder->buildShippingInfo();
        orderBuilder->buildPaymentInfo();
        orderBuilder->buildItems();
        return orderBuilder->getOrder();
    }
};

int main() {
    OrderBuilder1* orderBuilder1 = new OrderBuilder1();
    OrderDirector* orderDirector = new OrderDirector(orderBuilder1);
    Order* order1 = orderDirector->construct();
    order1->showOrder();

    delete order1;
    delete orderDirector;
    delete orderBuilder1;
    return 0;
}

/* Output: */
/*
Client: Client1
Shipping: Shipping1
Payment: Payment1
Items: Item1, Item2,
*/