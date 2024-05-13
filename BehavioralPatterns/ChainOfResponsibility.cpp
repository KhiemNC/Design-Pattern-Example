#include<iostream>
#include<string>
#include<vector>

using namespace std;

// Handler
class CardHandler {
    protected:
    CardHandler* successor;
    
    public:
    CardHandler() { this->successor = nullptr; }
    void setSuccessor(CardHandler* successor) { this->successor = successor; }
    virtual void handleRequest(string request) = 0;
};

// ConcreteHandler
class CardNumberHandler : public CardHandler {
    public:
    void handleRequest(string request) override {
        if (request == "Card Number") {
            cout << "Card Number Handler\n";
        } else if (successor != nullptr) {
            successor->handleRequest(request);
        }
    }
};
class CardPinHandler : public CardHandler {
    public:
    void handleRequest(string request) override {
        if (request == "Card Pin") {
            cout << "Card Pin Handler\n";
        } else if (successor != nullptr) {
            successor->handleRequest(request);
        }
    }
};
class CvvHandler : public CardHandler {
    public:
    void handleRequest(string request) override {
        if (request == "CVV") {
            cout << "CVV Handler\n";
        } else if (successor != nullptr) {
            successor->handleRequest(request);
        }
    }
};

int main(int argc, char* argv[]) {
    // Create chain of handlers
    CardHandler* cardNumberHandler = new CardNumberHandler();
    CardHandler* cardPinHandler = new CardPinHandler();
    CardHandler* cvvHandler = new CvvHandler();
    cardNumberHandler->setSuccessor(cardPinHandler);
    cardPinHandler->setSuccessor(cvvHandler);
    
    // Handle requests
    vector<string> requests = {"Card Number", "Card Pin", "CVV"};
    for (auto request : requests) {
        cardNumberHandler->handleRequest(request);
    }
    
    delete cardNumberHandler;
    delete cardPinHandler;
    delete cvvHandler;
    return 0;
}

/* Output: */
/*
Card Number Handler
Card Pin Handler
CVV Handler
*/