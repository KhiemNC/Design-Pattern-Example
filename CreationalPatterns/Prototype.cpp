#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Prototype
class Character {
    public:
    virtual Character* clone() = 0;
    virtual void print() = 0;
};

// ConcretePrototype
class ChienBinh : public Character {
    public:
    Character* clone() override {
        cout << "Clone ChienBinh\n";
        return new ChienBinh(*this);
    }
    void print() override {
        cout << "ChienBinh\n";
    }
};
class PhapSu : public Character {
    public:
    Character* clone() override {
        cout << "Clone PhapSu\n";
        return new PhapSu(*this);
    }
    void print() override {
        cout << "PhapSu\n";
    }
};

int main(int argc, char* argv[]) {
    vector<Character*> characters;
    characters.push_back(new ChienBinh());
    characters.push_back(new PhapSu());
    for (auto character : characters) {
        Character* clone = character->clone();
        clone->print();
        delete clone;
    }
    for (auto character : characters) {
        delete character;
    }
    return 0;
}