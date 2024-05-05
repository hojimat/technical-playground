#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

class Solution {
public:
    std::unordered_map<char, char> pairOf {
        {'(', ')'}, {'[', ']'}, {'{', '}'}
    };

    bool isValid(std::string s) {
        std::stack<char> stack {};
        for(const char& c : s) {
            if (pairOf.find(c) != pairOf.end()) {
                stack.push(pairOf[c]);
            } else if (stack.size() && c == stack.top()) {
                stack.pop();
            } else {
                return false;
            }

        }
        
        return (stack.empty());
    }
};



int main() {
    Solution mySol;
    std::string myS {"[]"};
    bool result = mySol.isValid(myS);

    std::cout << "Result is " << result << std::endl;

    return 0;
}