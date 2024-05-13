#include <iostream>

using namespace std;

class MySingleton {
    private:
    static MySingleton* instance;
    MySingleton() { 
        cout << "Singleton instance created\n";
    }

    public:
    static MySingleton* getInstance() {
        if (instance == nullptr) {
            instance = new MySingleton();
        }
        return instance;
    }

    void printMessage() { cout << "Hello from Singleton!\n"; }
};

MySingleton* MySingleton::instance = nullptr;

int main(int argc, char* argv[]) {
    MySingleton* uniqueInstance = MySingleton::getInstance();
    uniqueInstance->printMessage();
    return 0;
}

/* Output: */
/*
Singleton instance created
Hello from Singleton!
*/