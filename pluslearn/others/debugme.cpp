#include <iostream>
#include <vector>
#include <array>
#include <map>


int main() {
    int a = 100;
    int* pa = &a;
    
    std::cout << a << std::endl << pa << std::endl << *pa;

    return 0;
}
