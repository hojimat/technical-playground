#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Solution {
public:
    int findRadius(std::vector<int>& houses, std::vector<int>& heaters) {
        // Sort houses and heaters
        std::sort(houses.begin(), houses.end());
        std::sort(heaters.begin(), heaters.end());
        
        // Set initial values
        int nHeaters = heaters.size();
        int i = 0;
        int radius = 0;

        // We need to pass through each house once
        // We also need to pass through each heater just once meanwhile
        for(int& house : houses) {
            // Go to the latest closest heater
            while ( i < nHeaters-1 && abs(heaters[i]-house) >= abs(heaters[i+1]-house) ) {
                i++;
            }
            radius = std::max(radius, abs(heaters[i] - house));
        }

        return radius;       
    }
};



int main() {
    std::unique_ptr<Solution> mSolution = std::make_unique<Solution>();
    std::vector<int> mHouses {1,5};
    std::vector<int> mHeaters {2};

    int ans = mSolution->findRadius(mHouses, mHeaters);

    std::cout << "Minimum radius: " << ans << std::endl;

    return 0;
}
