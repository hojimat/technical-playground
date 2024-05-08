#include <iostream>
#include <vector>
#include <stack>
#include <map>


class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();
        // we don't need speed, we can compare position+time
        // because we were guaranteed no duplicate positions;
        // this is already O(n*log n) because of sorting
        std::map<int, double> cars {}; 
        for (int i=0; i<n; i++) {//O(n)
            // int toCeiling = (target-position[i]) % speed[i] != 0;
            double timeToFinish = (double)(target-position[i])/ (double)speed[i];
            //cars.insert({position[i], timeToFinish});
            cars[position[i]] = timeToFinish;
        }


        std::stack<std::pair<int, double>> uniqueFinishes {};
        // Now we have a sorted map of cars {position: timeToFinish}
        // we start from the closest car to the finish
        // add it to stack; next add only if different finish time
        for (auto it=cars.rbegin(); it != cars.rend(); ++it) {
            if (uniqueFinishes.empty()) {
                uniqueFinishes.push({it->first, it->second});
                continue;
            }

            double topTtf = uniqueFinishes.top().second;
            double curTtf = it->second;
            // by design, we know that topPos > curPos
            // so, only need to check ttf

            if (curTtf > topTtf) {// doesn't catch up on time
                uniqueFinishes.push({it->first, it->second});
                continue;
            }
        }
        
        return uniqueFinishes.size();
    }
};


int main() {
    Solution mySol;
    int myTarget {10};
    std::vector<int> myPosition {8,3,7,4,6,5};
    std::vector<int> mySpeed {4,4,4,4,4,4};

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



UTILS:

pos[i] = 8
spd[i] = 4
in 2 periods it reaches target 15

(15-8)/4 = 2


let A = B*k + r, where k,r=0,1,2,3,... and r<B

ceil(A/B) = ceil((Bk+r)/B) = ceil(k + r/B) = 
            k + ceil(r/B)
if r==0: ceil(r/B) = 0;
else:   ceil(r/B) = 1
basically, it is  (A%B)==0

*/