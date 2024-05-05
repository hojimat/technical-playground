#include <iostream>

int a = 2;

int & f(int x) {
    a = a + x;
    return a;
}


int main(void) {
    int t=2;
    std::cout << f(t) << std::endl;
    f(t) = 10;
    std::cout << f(t) << std::endl;
    t = f(t);
    std::cout << f(t) << std::endl;
}