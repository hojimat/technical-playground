#include <iostream>

class Parent {
public:
    virtual void greet() {
        std::cout << "Greetings from a parent!\n";
    }
private:
    int name;
    void kill() {
        std::cout << "You killed a parent!\n";
    }
};


class Child : public Parent {
public:
    void greet() override {
        std::cout << "Hey dude, it's me, child.\n";
    }
};

int main() {
    Parent *john = new Parent();
    Child *paul = new Child();
    Parent *george = new Child(); // now this uses an overriden method
    //Child *ringo = new Parent(); this raises an error
    
    john->greet();
    paul->greet();
    george->greet();

    delete john;
    delete paul;
    delete george;

    return 0;
}

