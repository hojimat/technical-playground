#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int n = height.size();
        int i=0;
        int j=n-1;

        int currentMax = 0;
        while(i < j) {
            int w = j-i;
            int h = std::min(height[i], height[j]);
            if (w*h > currentMax) {
                currentMax = w*h;
            }

            // update info ^ and move on
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }

        }
        
        return currentMax;
    }
};


int main() {
    Solution mySol;
    std::vector<int> myHeight {1,8,6,2,5,4,8,3,7};
    int result = mySol.maxArea(myHeight);

    std::cout << "Result is: " << result << std::endl;

    return 0;
}