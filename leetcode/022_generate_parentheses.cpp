#include <iostream>
#include <string>
#include <vector>


class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> allStrings {};
        backtracking(0, 0, n, "", allStrings);

        return allStrings;
    }

private:
    void backtracking(int open, int close, int limit, std::string current, std::vector<std::string>& collector) {
        if (open==limit && close==limit) {
            collector.push_back(current);
            return;
        }

        if (open < limit) {
            backtracking(open+1, close, limit, current+"(", collector);
        }

        if (close < open) {
            backtracking(open, close+1, limit, current+")", collector);
        }
    }
};


int main() {
    Solution mySol;
    int myN = 3;
    std::vector<std::string> result = mySol.generateParenthesis(myN);

    for(std::string res : result) {
        std::cout << res << std::endl;
    }

    return 0;
}

