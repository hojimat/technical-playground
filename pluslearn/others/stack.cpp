#include <iostream>
#include <vector>

int main() {
    int n;

    std::cout << "Enter an array size:";

    std::cin >> n;

    std::vector<int> myArray;
    for(int i=0; i<n; i++){
        myArray.push_back(0);
    }

    std::cout << myArray[4];
    
    return 0;

}
