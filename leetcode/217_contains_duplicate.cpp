#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> visited;
        for (auto& num : nums) {
            if (visited.find(num) != visited.end()) {
                return true;
            }
            visited.insert(num);
        }
        return false;
    }
};

int main() {
    Solution mySol;
    std::vector<int> myNums {1,1,1,3,3,4,3,2,4,2};
    bool result = mySol.containsDuplicate(myNums);

    std::cout << result;
    return 0;
}