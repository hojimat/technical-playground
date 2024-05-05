#include <iostream>

class Character {
public:
    virtual void attack() {
        std::cout << "Character attacks!\n";
    }
};

class Warrior : public Character {
public:
    void attack() override {
        std::cout << "Warrior attacks!\n";
    }
};

class Archer : public Character {
public:
    void attack() override {
        std::cout << "Archer attacks!\n";
    }
};

void performAttack(Character *character) {
    character->attack();
}

int main() {
    Warrior *warrior = new Warrior();
    Archer *archer = new Archer();

    performAttack(warrior);
    performAttack(archer);

    delete warrior;
    delete archer;
    
    return 0;
}