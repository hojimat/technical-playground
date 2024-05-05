#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        /*
        put entire vector into a hash set
        loop over all elements of nums
            if num-1 exists, ignore it 
            else start looking for num+1
                while it exists and count
            update largest consecutive length
        */

       // put nums into a set
       std::unordered_set<int> library (nums.begin(), nums.end());
       
       int longest = 0;
       for (const auto& num : nums) {
        // if n-1 exists, ignore this value
        if (library.find(num-1) != library.end()) { continue;}
        // else start looking for num+1 while exists
        int length = 1;
        while (library.find(num+length) != library.end()) {
            length += 1;
        }

        if (length > longest) {
            longest = length;
        }

       }

       return longest;
    }
};


int main() {
    Solution mySol;
    std::vector<int> myNums {0,3,7,2,5,8,4,6,0,1};
    int myResult = mySol.longestConsecutive(myNums);
    std::cout << myResult;
    return myResult;
}