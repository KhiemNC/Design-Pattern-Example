#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

// Flyweight
class Character {
    public:
    virtual void display(int fontSize) const  = 0;
};

// ConcreteFlyweight
class ConcreteCharacter : public Character {
    private:
    char character;
    
    public:
    ConcreteCharacter(char character) { this->character = character; }
    
    void display(int fontSize) const override {
        cout << character << "(" << fontSize << ") ";
    }
};

// FlyweightFactory
class CharacterFactory {
    private:
    map<char, Character*> characters;
    
    public:
    Character* getCharacter(char character) {
        if (characters.find(character) == characters.end()) {
            cout << "Creating new character: " << character << endl;
            characters[character] = new ConcreteCharacter(character);
        }
        return characters[character];
    }
};

int main(int argc, char* argv[]) {
    CharacterFactory factory;
    vector<Character*> document;
    document.push_back(factory.getCharacter('A'));
    document.push_back(factory.getCharacter('B'));
    document.push_back(factory.getCharacter('A'));
    document.push_back(factory.getCharacter('C'));
    document.push_back(factory.getCharacter('B'));
    document.push_back(factory.getCharacter('A'));
    for (auto character : document) { character->display(12); }
    return 0;
}

/* Output: */
/*
Creating new character: A
Creating new character: B
Creating new character: C
A(12) B(12) A(12) C(12) B(12) A(12) 
*/