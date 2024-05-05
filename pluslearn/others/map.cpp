#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> ages = {{"Mike", 24}, {"Angela", 27}};

    std::cout << ages["Mike"];

    return 0;
}
