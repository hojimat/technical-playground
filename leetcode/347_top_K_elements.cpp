#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // If K is equal to set size just return it
        if(nums.size()<=k) {
            return nums;
        }
        /* Algorithm should be better than n*log n,
        i.e. do not use sorting of the main N vector;
        nums = {5,5,5,3,3,1,2,2}, K=7 -> ans={5,2,3}
        */
        std::unordered_map<int, int> numCount = countNumbers(nums);
        // {5:3, 3:2, 1:1, 2:2}

        std::map<int, std::vector<int>> freqSets {};
        for(const auto& [key, value] : numCount) {
            freqSets[value].push_back(key);
        }// {3:[5], 2:[3,2], 1:[1]}

        std::vector<int> topK {};
        int count = 0;
        for(auto it = freqSets.rbegin(); it != freqSets.rend() && count < k; ++it) {
            for(const int& val : it->second) {
                topK.push_back(val);
                }
            count += it->second.size();
        }
    
        return topK;
    }
private:
    std::unordered_map<int, int> countNumbers(std::vector<int>& nums) {
        /*
        pass through each value;
        for each value:
            add it to map as a key and increment its value;
        */
        std::unordered_map<int, int> result {};
        for (int& num : nums) {
            result[num] += 1;
        }
        return result;
    }
};

int main() {
    Solution mySol;
    std::vector<int> myNums {1,2};
    int myK {2};

    std::vector<int> result = mySol.topKFrequent(myNums, myK);
    for(int& res : result) {std::cout << res << " ";}
    return 0;
}