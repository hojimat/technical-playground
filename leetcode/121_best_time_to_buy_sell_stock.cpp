#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int buy = 0;
        int sell = 1;
        int profit = 0;

        while(sell < prices.size()) {
            if (prices[buy] < prices[sell]) {
                profit = std::max(prices[sell]-prices[buy], profit);
                sell++;
            } else {
                buy = sell;
                sell++;
            }
        }

        return profit;
    }
};


int main() {
    Solution mySol;
    std::vector<int> myPrices {7,6,4,3,1};
    int result = mySol.maxProfit(myPrices);
    std::cout << "Result is: " << result << std::endl;

    return 0;
}



/*
SOLUTION:
basically track buy date and sell date where buy<sell;

if prices[buy] >= prices[sell]:
    either prices[sell+i] will be higher than prices[sell]
    or prices[sell+i] will be even lower;
    in both cases better to buy at prices[sell],
    so, buy = sell; sell=sell+1;
if prices[buy] < prices[sell]:
    update current Maximum;
    then sell++;
    repeat;

if at any point prices[buy] >= prices[sell]: just jump there

*/