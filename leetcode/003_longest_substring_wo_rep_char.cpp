#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.size();
        if (n < 2) {return n;}

        int maxLength = 0;

        int i=0;
        int j=0;
        std::unordered_set<char> chars;
        while (j < n) {
            if (chars.find(s[j]) == chars.end()) {
                maxLength = std::max(maxLength, j-i+1);
                chars.insert(s[j]);
                j++;
            } else {
                chars.erase(s[i]);
                i++;
            }
        }

        return maxLength;
    }
};



int main() {
    Solution mySol;
    std::string myS {"abcabcbb"};
    
    int result = mySol.lengthOfLongestSubstring(myS);
    std::cout << "Result is: " << result << std::endl;


    return 0;
}


/*
SOLUTION:
iterate through chars; set two pointers left and right;
increment right while char[right]!=char[left]; increment current length;
set maxlength = max(maxlength, currentlength);

*/