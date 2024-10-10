#include <algorithm>
#include <iostream>
#include <vector>


class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int n = piles.size();
        int maxPile = *std::max_element(piles.begin(), piles.end());
        // no time to eat all is given
        if (h<n) {
            return -1;
        }
        
        // if k=maxPile, the time will be n, and since n<=h, we eat all
        // can we do find smaller speed?
        // binary search speeds from 1 to maxPile
        long left = 1;
        long right = maxPile;
        long result = right;
        while (left <= right) { // O(log(maxPile))
            long mid = (left+right)/2;
            if (hours(piles, mid) <= h) {
                result = std::min(result, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;

    }

private:
    long hours(std::vector<int>& piles, int speed) { // O(n)
        long res = 0;
        for(const int& pile : piles) {
            res += (pile+speed-1)/speed;
        }
        return res;
    }
};


int main() {
    Solution solx;
    std::vector<int> pilesx {805306368,805306368,805306368};
    int hx {1000000000};

    int ans = solx.minEatingSpeed(pilesx, hx);

    std::cout << "Min eating speed: " << ans << std::endl;
}
