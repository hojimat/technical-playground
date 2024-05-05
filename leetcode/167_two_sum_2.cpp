#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n-1;
        
        while (i < j) {
            if (numbers[i] + numbers[j] > target) {
                j--;
                continue;
            } else if (numbers[i] + numbers[j] < target) {
                i++;
                continue;
            } else {
                return {i+1, j+1};
            }
        }

        return {100,200};
    }
};



int main() {
    Solution mySol;
    std::vector<int> myNumbers {2,7,11,15};
    int myTarget {9};
    std::vector<int> result = mySol.twoSum(myNumbers, myTarget);
    for(int num: result) {std::cout << num << " ";}
    return 0;
}