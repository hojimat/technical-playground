#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;

        while(i < j) {
            std::cout << s[i] << " " << s[j] << "\n";
            while (!std::isalnum(s[i]) && i < j) {
                i++;
            }

            while (!std::isalnum(s[j]) && i < j) {
                j--;
            }

            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};


int main() {
    Solution mySol;
    std::string myS {"0P"};
    bool result = mySol.isPalindrome(myS);

    std::cout << result << std::endl;
    return 0;
}