#include <iostream>
#include <memory>


class Rectangle {
private:
    int length;
    int width;
};


void fun() {
    //Rectangle* p = new Rectangle();
    std::shared_ptr<Rectangle> p(new Rectangle());
}


int main() {
    while(1) {
        fun();
        std::cout << "hello";
    }
}
