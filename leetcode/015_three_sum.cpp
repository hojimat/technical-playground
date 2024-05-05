#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        /*
        for loop over elements; call twoSum for each
        */
        std::vector<std::vector<int>> result {};
        int n = nums.size();
        // sort the array (O(log(n)))
        std::sort(nums.begin(), nums.end());
        // Iterate and run 2Sum
        for(int i=0; i<n-2; i++) {
            if(i>0 && nums[i] == nums[i-1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    while (left < right && nums[right] == nums[right -1]) {
                        right--;
                    }

                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }    
};


int main() {
    Solution mySol;
    std::vector<int> myNums {-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> result = mySol.threeSum(myNums);

    for(auto const& res : result) {
        for(auto const& val: res) {
            std::cout << val << " ";
        }

        std::cout << std::endl;
    }
}