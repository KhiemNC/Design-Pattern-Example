#include<iostream>
#include<string>
#include<vector>

using namespace std;

// Memento
class WebsitesMemento {
    private:
    vector<string> websites;

    public:
    WebsitesMemento(const vector<string>& websites) : websites(websites) {}
    vector<string> getWebsites() const { return websites; }
};

// Originator
class Browser {
    private:
    vector<string> websites;
    
    public:
    void openWebsite(const string& website) {
        websites.push_back(website);
    }
    WebsitesMemento save() {
        return WebsitesMemento(websites);
    }
    void restore(const WebsitesMemento& memento) {
        websites = memento.getWebsites();
    }
    void showWebsites() {
        for (const auto& website : websites) {
            cout << website << endl;
        }
    }
};

// Caretaker
class BrowserHistory {
    private:
    vector<WebsitesMemento> mementos;
    
    public:
    void saveState(const WebsitesMemento& memento) {
        mementos.push_back(memento);
    }

    WebsitesMemento restoreState(int index) {
        return mementos[index];
    }
};

int main() {
    Browser browser;
    BrowserHistory history;

    browser.openWebsite("google.com");
    browser.openWebsite("facebook.com");
    history.saveState(browser.save());
    browser.showWebsites();
    cout << "----------------\n";

    browser.openWebsite("youtube.com");
    history.saveState(browser.save());
    browser.showWebsites();
    cout << "----------------\n";

    browser.openWebsite("apple.com");
    browser.showWebsites();
    cout << "----------------\n";

    browser.restore(history.restoreState(1));
    browser.showWebsites();
    cout << "----------------\n";

    return 0;
}

/* Output: */
/*
google.com
facebook.com
----------------
google.com
facebook.com
youtube.com
----------------
google.com
facebook.com
youtube.com
apple.com
----------------
google.com
facebook.com
youtube.com
----------------
*/