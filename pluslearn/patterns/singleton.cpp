/* 
Category:
- creational Design Pattern

Implementation:
- make constructor private, create a static creation method instead

Caveats:
- violates Single Responsibility Principle from SOLID
- is good for Files or Databases
- whenever you create a new object, you get just the first one
- normal constructors cannot do it
*/

#include <iostream>

class Singleton {
private:
    static Singleton* instance;
    Singleton() {
        std::cout << "created a singleton!\n";
    }; // private constructor

    Singleton(Singleton &other) = delete; // delete copy constructor
    void operator=(const Singleton &) = delete; // delete assignment

public:
    static Singleton *getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    std::cout << s1 << "\n" << s2;

    return 0;
}