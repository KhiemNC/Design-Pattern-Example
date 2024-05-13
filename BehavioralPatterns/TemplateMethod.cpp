#include<iostream>

using namespace std;

// Abstract class
class WebPageTemplate {
public:
    void render() {
        createHeader();
        createBody();
        createFooter();
    }
    virtual void createHeader() {
        cout << "Default header" << endl;
    }
    virtual void createBody() = 0;
    virtual void createFooter() {
        cout << "Default footer" << endl;
    }
};

// Concrete class
class HomePage : public WebPageTemplate {
public:
    void createBody() {
        cout << "Home page body" << endl;
    }
};
class ContactPage : public WebPageTemplate {
public:
    void createBody() {
        cout << "Contact page body" << endl;
    }
};


int main() {
    WebPageTemplate *homePage = new HomePage();
    homePage->render();
    cout << endl;

    WebPageTemplate *contactPage = new ContactPage();
    contactPage->render();

    delete homePage, contactPage;
    return 0;
}

/* Output: */
/*
Default header
Home page body
Default footer

Default header
Contact page body
Default footer
*/