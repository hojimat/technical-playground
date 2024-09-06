#include <iostream>
#include <string>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int n = s.size();
        return 404;
    }
};


int main() {
    Solution mySol;
    std::string myS {"AABABBA"};
    int myK {1};

    int result = mySol.characterReplacement(myS, myK);
    std::cout << "Result is: " << result << std::endl;

    return 0;
}