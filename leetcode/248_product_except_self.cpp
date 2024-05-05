#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n, 1);
        
        int prefix = 1;
        for(int i=0; i<n; i++) {
            answer[i] *= prefix;
            prefix *= nums[i];
        }

        int postfix = 1;
        for(int i=n-1; i>=0; --i) {
            answer[i] *= postfix;
            postfix *= nums[i];
        }

        return answer;
    }
};


int main() {
    Solution mySol;
    std::vector<int> myNums {-1,1,0,-3,3};
    std::vector<int> result {};
    result = mySol.productExceptSelf(myNums);

    for(auto& res : result) {std::cout << res << " ";}

    return 0;
}