#include <iostream>
#include <vector>
#include <stack>
#include <utility>


class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        // Pass through each entry once
        // push each entry to the stack if not larger than stack top()
        // else, pop the stack and put i-top().index to the results
        int n = temperatures.size();
        std::vector<int> result (n, 0);
        std::stack<std::pair<int, int>> orphans {};

        for (int i=0; i<n; i++) {
            while (!orphans.empty() && orphans.top().first < temperatures[i]) {
                result[orphans.top().second] = i - orphans.top().second;
                orphans.pop();
            }

            orphans.push(std::make_pair(temperatures[i], i));
    
        }
        
        return result;
    }
};



int main() {
    Solution mySol;
    std::vector<int> myTemperatures {73,74,75,71,69,72,76,73};
    std::vector<int> result = mySol.dailyTemperatures(myTemperatures);

    for(int res: result) {std::cout << res << " ";}
    std::cout << std::endl;


    return 0;
}