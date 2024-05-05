#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int trap(std::vector<int>& height) {
        /*
        There is water in bar i if and only if:
            - there exists some bar j<i such that height[j] > height[i] AND
            - there exists some bar k>i such that height[k] > height[i]
        Moreover, the amount of trapped water will be:
            - water[i] = max( min(height[j] - height[i] , height[k] - height[i]), 0);
        Finally, the result will be the sum of water[i] for i=0 to vector.size()-1

        Challenges:
            - for each i, we need to compare it with each j != i -> O(n^2)
            - j and k and not just random values, they need to be close (>)
                - how close?
                
        Algorithm:
            - start from leftmost bar and rightmost bar and 
                set waters vector all to minimum of the two
            - pick the lower one, in(de) crement it towards center
            - if the new minimum increases:
                - set water levels to it for all i between current left and right
            - go back to in(de)crementing
            - Subtract height vector from waters vectors

        Complexity: O(n^2)
        */
        int n = height.size();
        int left = 0; // leftmost
        int right = n-1; // rightmost

        // track two borders; not water level etc.
        std::vector<int> waters(n, 0);
        int borderLeft = height[left];
        int borderRight = height[right];

        int result=0;
        while(left < right) {

            if (borderLeft < borderRight) {
                left++;
                borderLeft = std::max(borderLeft, height[left]);
                result += borderLeft - height[left];
                } else {
                right--;
                borderRight = std::max(borderRight, height[right]);
                result += borderRight - height[right];
            }

        }

        return result;
    }
};


int main() {
    Solution mySol;
    std::vector<int> myHeight {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = mySol.trap(myHeight);
    std::cout << "Result is: " << result;

    return 0;
}