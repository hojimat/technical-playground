#include <iostream>

class Rectangle {
    private:
        int length;
        int width;
    public:
        Rectangle() {
            std::cout << "done...\n";
        }
};


void fun() {
    Rectangle* a = new Rectangle();
}

int main() {
    
    while(1) {
        fun();
    }

    return 0;
}
