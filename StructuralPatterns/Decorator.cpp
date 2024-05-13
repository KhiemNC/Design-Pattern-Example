#include<iostream>
#include<string>

using namespace std;

// Component
class Login {
    public:
    virtual void authenticate(string username, string password) = 0;
};

// ConcreteComponent
class SimpleLogin : public Login {
    public:
    void authenticate(string username, string password) override {
        cout << "SimpleLogin: " << username << " " << password << endl;
    }
};

// Decorator
class LoginDecorator : public Login {
    private:
    Login* login;
    
    public:
    LoginDecorator(Login* login) { this->login = login; }
    
    void authenticate(string username, string password) override {
        login->authenticate(username, password);
    }
};

// ConcreteDecorator
class TwoFactorLogin : public LoginDecorator {
    public:
    TwoFactorLogin(Login* login) : LoginDecorator(login) {}
    
    void authenticate(string username, string password) override {
        LoginDecorator::authenticate(username, password);
        cout << "TwoFactorLogin: " << username << " " << password << endl;
    }
};
class RememberMeLogin : public LoginDecorator {
    public:
    RememberMeLogin(Login* login) : LoginDecorator(login) {}
    
    void authenticate(string username, string password) override {
        LoginDecorator::authenticate(username, password);
        cout << "RememberMeLogin: " << username << " " << password << endl;
    }
};

int main(int argc, char* argv[]) {
    Login* slogin = new SimpleLogin();
    slogin->authenticate("simple", "admin");

    Login* twofactor = new TwoFactorLogin(slogin);
    twofactor->authenticate("twofactor", "admin");

    Login* rememberme = new RememberMeLogin(twofactor);
    rememberme->authenticate("rememberme", "admin");

    delete slogin;
    delete twofactor;
    delete rememberme;
    return 0;
}

/* Output: */
/*
SimpleLogin: simple admin
SimpleLogin: twofactor admin
TwoFactorLogin: twofactor admin
SimpleLogin: rememberme admin
TwoFactorLogin: rememberme admin
RememberMeLogin: rememberme admin
*/