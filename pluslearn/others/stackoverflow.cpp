#include <iostream>

void infiniteStack(int x){
    std::cout << x << " ";
    return infiniteStack(x+1);
}

void eatStack() {
    char memory[10];
    std::cout << &memory << std::endl;
    eatStack();
}


int main() {
    //func(1);
    eatStack();
}