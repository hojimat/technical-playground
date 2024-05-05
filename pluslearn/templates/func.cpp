#include <iostream>

template<typename T>
void swap(T& left, T& right)
{
    T buffer = std::move(left);
    left = std::move(right);
    right = std::move(buffer);
}

int main() {
    int a = 5;
    int b = 10;

    std::cout << "Before: (" << a << "," << b << ")\n";
    swap(a,b);
    std::cout << "After: (" << a << "," << b << ")\n";

    return 0;
}