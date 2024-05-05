#include <iostream>
#define uint32 unsigned int

template<uint32 N>
struct Factorial {
    static constexpr uint32 value = N * Factorial<N-1>::value;
};

template<>
struct Factorial<0> {
    static constexpr uint32 value = 1;
};


int main() {
    std::cout << Factorial<5>::value;
    return 0;
}