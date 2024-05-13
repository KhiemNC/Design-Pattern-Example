#include<iostream>
#include<string>

using namespace std;

// Strategy interface
class Strategy {
public:
    virtual void sendNotification(string message) = 0;
};

// Concrete strategy
class EmailNotification : public Strategy {
public:
    void sendNotification(string message) {
        cout << "Email notification: " << message << endl;
    }
};
class SMSNotification : public Strategy {
public:
    void sendNotification(string message) {
        cout << "SMS notification: " << message << endl;
    }
};

// Context
class NotificationService {
private:
    Strategy *strategy;
public:
    NotificationService(Strategy *strategy) {
        this->strategy = strategy;
    }
    void setStrategy(Strategy *strategy) {
        this->strategy = strategy;
    }
    void sendNotification(string message) {
        strategy->sendNotification(message);
    }
};

int main() {
    NotificationService *notificationService = new NotificationService(new EmailNotification());
    notificationService->sendNotification("Hello, this is an email notification.");
    notificationService->setStrategy(new SMSNotification());
    notificationService->sendNotification("Hello, this is an SMS notification.");
    return 0;
}

/* Output: */
/*
Email notification: Hello, this is an email notification.
SMS notification: Hello, this is an SMS notification.
*/