#include <iostream>

int f(int x) {
    return f(x);
}

int main() {
    f(10);

    return 0;
}