#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <map>


class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();

        std::map<int, int> speeds {};
        for(int i=0; i<n; i++) {
            speeds.insert({position[i], speed[i]});
        }


        std::stack<std::pair<int,int>> fleets {};

        for (auto it = speeds.rbegin(); it != speeds.rend(); ++it) {
            if (fleets.empty()) {
                fleets.push({it->first, it->second});
                std::cout << "Fleet was empty. Pushing " << it->first << ":" << it->second << std::endl;
                continue;
            }

            bool inFleetWithTop = isFleet(target, it->first, it->second, fleets.top().first, fleets.top().second);
            if(!inFleetWithTop) {
                fleets.push({it->first, it->second});
                std::cout << "Fleet top was" << fleets.top().first << ":" << fleets.top().second << ". Pushing " << it->first << ":" << it->second << std::endl;
                continue;
            }

            std::cout << "Fleet top was" << fleets.top().first << ":" << fleets.top().second << 
                         ". Same fleet as " << it->first << ":" << it->second << ". Continue" << std::endl;
        }

        // while(!fleets.empty()) {
        //     std::cout << fleets.top().first << " " << fleets.top().second << "\n";
        //     fleets.pop();
        // }

        return fleets.size();
    }

private:
    bool isFleet(int target, int pos0, int spd0, int pos1, int spd1) {
        int posL, posF, spdL, spdF;
        if (pos0 > pos1) {
            posL = pos0;
            spdL = spd0;
            posF = pos1;
            spdF = spd1;
        } else {
            posL = pos1;
            spdL = spd1;
            posF = pos0;
            spdF = spd0;
        }

        if (spdL >= spdF) {
            return false;
        } else {
            int timeToCatch = std::ceil(  (float)((posL-posF)) /  (float)((spdF-spdL)) );
            if (posL + timeToCatch*spdL > target) {
                //std::cout << posL << "," << spdL << "; " << posF << "," << spdF << "; " << timeToCatch << "; " << target << "------";
                return false;
            } else {
                std::cout << posL << "," << spdL << "; " << posF << "," << spdF << "; " << timeToCatch << "------";
                return true;
            }
        }
        
    }
};


int main() {
    Solution mySol;
    int myTarget {21};
    std::vector<int> myPosition {1,15,6,8,18,14,16,2,19,17,3,20,5};
    std::vector<int> mySpeed {8,5,5,7,10,10,7,9,3,4,4,10,2};

    int result = mySol.carFleet(myTarget, myPosition, mySpeed);
    std::cout << "Result is: " << result << std::endl; 

    return 0;

}



/*

SOLUTION:

you are a fleet, if at any point before reaching a target,
someone catches you up.
This only happens if the later position is slower!!!
otherwise no fleet!


posL + t*spdL <= posF + t*spdF; and then compare this to target:
posL-posF <= t(spdF - spdL); guaranteed no-division by zero; and positive
ttt = ceil ( (posL-posF)/(spdF-spdL) );
posF +  ttt*spdF <= target then catches up; else no


ALGORITHM:
we don't care where we intersect the closest car to us -
we care about the leader of the fleet (the one who started first)
we have to sort it first by pos;

for i in range(n, 1):
    stack fleets;
    int countFleets;
    if fleets is empty OR fleets.top not a fleet with (pos_i, spd_i):
        fleets.push(pos_i, spd_i)
    else:
        fleets.pop()

size of fleets return

*/