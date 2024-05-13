#include<iostream>

using namespace std;

// Pre-define
class CharacterFactory; // AbstractFactory
class ChienBinhFactory; // ConcreteFactory1
class PhapSuFactory; // ConcreteFactory2

// AbstractProduct
class Character { // AbstractProductA
    public:
    virtual void tanCong() = 0;
    virtual void diChuyen() = 0;
};
class NPC { // AbstractProductB
    public:
    virtual void tanCong() = 0;
    virtual void diChuyen() = 0;
};

// ConcreteProduct
class ChienBinh : public Character { // ProductA1
    public:
    void tanCong() override {
        cout << "ChienBinh tan cong" << endl;
    }
    void diChuyen() override {
        cout << "ChienBinh di chuyen" << endl;
    }
};
class PhapSu : public Character { // ProductA2
    public:
    void tanCong() override {
        cout << "PhapSu tan cong" << endl;
    }
    void diChuyen() override {
        cout << "PhapSu di chuyen" << endl;
    }
};
class ChienBinhNPC : public NPC { // ProductB1
    public:
    void tanCong() override {
        cout << "ChienBinhNPC tan cong" << endl;
    }
    void diChuyen() override {
        cout << "ChienBinhNPC di chuyen" << endl;
    }
};
class PhapSuNPC : public NPC { // ProductB2
    public:
    void tanCong() override {
        cout << "PhapSuNPC tan cong" << endl;
    }
    void diChuyen() override {
        cout << "PhapSuNPC di chuyen" << endl;
    }
};

// AbstractFactory
class CharacterFactory {
    public:
    virtual Character* createCharacter() = 0;
    virtual NPC* createNPC() = 0;
};

// ConcreteFactory
class ChienBinhFactory : public CharacterFactory { // ConcreteFactory1
    public:
    Character* createCharacter() override {
        return new ChienBinh();
    }
    NPC* createNPC() override {
        return new ChienBinhNPC();
    }
};
class PhapSuFactory : public CharacterFactory { // ConcreteFactory2
    public:
    Character* createCharacter() override {
        return new PhapSu();
    }
    NPC* createNPC() override {
        return new PhapSuNPC();
    }
};

// Client
void clientTest(CharacterFactory* factory) {
    Character* character = factory->createCharacter();
    NPC* npc = factory->createNPC();

    character->tanCong();
    character->diChuyen();
    npc->tanCong();
    npc->diChuyen();

    delete character;
    delete npc;
}

int main() {
    // Use AbstractFactory to create objects
    CharacterFactory* factory;

    factory = new ChienBinhFactory();
    clientTest(factory);
    delete factory;

    factory = new PhapSuFactory();
    clientTest(factory);
    delete factory;

    return 0;
}

/* Output */
/*
ChienBinh tan cong
ChienBinh di chuyen
ChienBinhNPC tan cong
ChienBinhNPC di chuyen
PhapSu tan cong
PhapSu di chuyen
PhapSuNPC tan cong
PhapSuNPC di chuyen
*/