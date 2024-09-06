#include <iostream>
#include <string>
#include <memory>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        return true;
    }
};


int main() {
    std::unique_ptr<Solution> mySol = std::make_unique<Solution>();
    std::string myS1 = "ab";
    std::string myS2 = "eidbaooo";
    
    bool result = mySol->checkInclusion(myS1, myS2);
    std::cout << "Result is: " << result << std::endl;
    
    return 0;
}