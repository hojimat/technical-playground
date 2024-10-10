#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> complements {};
    for(int i=0; i<nums.size(); i++) {
      if (complements.find(nums[i]) == complements.end()) {
          complements[target-nums[i]]=i;
          continue;
      } else {
        return {complements[nums[i]], i};
      }
    }

    return {2,3};
  }
};


int main() {
  Solution mySol;
  std::vector<int> myNums {-3, 4, 3, 90};
  int myTarget {0};

  std::vector<int> result = mySol.twoSum(myNums, myTarget);
  for(int& res: result) {std::cout << res << " ";}
  return 0;
}
