#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while (low <= high) {
            int mid = (low + high)/2;
            if (nums[mid] < target) {
                low = mid+1;
            } else if (nums[mid] > target) {
                high = mid-1;
            } else {
                return mid;
            }
        }


        return -1;
    }
};



int main() {
    Solution mySol;
    std::vector<int> myNums {-1,0,3,5,9,12};
    int myTarget {9};

    int result = mySol.search(myNums, myTarget);
    std::cout << "Result it: " << result << std::endl;

    return 0;
}