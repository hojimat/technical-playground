#include <iostream>


class Entity {
private:
    int x;
    int y;
public:
    Entity(int a, int b) {
        x = a;
        y = b;
    }
    
    int getX() {
        return x;
    }

};



int main() {
    Entity e(12,23);
    std::cout << e.getX();
}
