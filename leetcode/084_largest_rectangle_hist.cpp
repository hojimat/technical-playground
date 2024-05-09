#include <iostream>
#include <vector>
#include <stack>
#include <utility>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int n = heights.size();
        int maxArea {0};
        std::stack<std::pair<int, int>> ghostHeights {};

        for(int i=0; i<n; i++) {
            // Push if empty or higher
            int k = i;
            // calculate and pop until lower
            while (!ghostHeights.empty() && ghostHeights.top().first > heights[i]) {
                int j = ghostHeights.top().second;
                int currentArea = (i-j) * ghostHeights.top().first;
                if (currentArea > maxArea) { maxArea = currentArea;  }
                k = j;
                ghostHeights.pop();
            }

            // if equal lenghts, don't do anything; just continue;
            ghostHeights.push({heights[i], k});
        }
        
        // Now we are left with the stack. Calculate and pop

        while(!ghostHeights.empty()) {
            int j = ghostHeights.top().second;
            int currentArea = (n-j) * ghostHeights.top().first;
            if (currentArea > maxArea) {maxArea = currentArea;}
            ghostHeights.pop();
        }


        return maxArea;
    }
};



int main() {
    Solution mySol;
    std::vector<int> myHeights {1,2,2};
    int result = mySol.largestRectangleArea(myHeights);
    std::cout << "Result is: " << result << std::endl;

    return 0;
}


/*

2 1 5 6 2 3

if we brute forced, we would have:

2
21
215
2156
21562
215623
1
15
156
15623
5
56
562         
5623
6
62
623
2
23
3

brute force can solve such problems as this:

Imagine this array:
5 6 7 2

567: 15
67: 12

so including 5 is great, but what if:
5 6 7 7 7 7 7 7 

56777777 = 40
6777777 = 42

so, excluding 5 is great.

and at point 6 or 7 we would never know what is coming next.

so, either brute force or some other algorithm.

Solution:

for each height we look at all possible rectangles of that height!

i=0:
    h=2, x=0, w=1
i=1:
    h=1, x=0,1,2,3,4,5, w=6
i=2:
    h=5, x=2,3, w=2
i=3:
    h=6, x=3, w=1
i=4:
    h=2, x=2,3,4,5, w=4
i=5:
    h=3, x=5, w=1

this is half the values, but stil need to keep track of indices

BUT!!! We only need a starting index and an ending index.
Also, as long as we record maximum area in some place,
it is ok to look at new combinations!!! We thus never climb down.

if h[i+1] < h[i], then the reign of height h[i] ends here,
we can check the accumulated width (currentIndex - startingindex + 1)
and calc the area.
Basically, if we have:
2 5 6 5 5 6 6 6 6 5 7 7 and next is -> 2,
we no longer enjoy the benefit of the 5 at the beginning,
2 becomes relevant again, though.

but as soon as the next value is increasing, the current height remains relevant.

2 5 6 8 10 -> 2 is not relevant. because we shift to 5 and enjoy... unless 2 comes up again.
so, we keep 2 until it becomes relevant in a stack.
then we go to 5 and push it etc.
If all always increase, then we have a full stack.
just check its area with index starting at i and ending at n and pop it until empty.

If at some point we have a smaller value

1 3 5 6 8 10 2
then 5,6,8,10 become kind of irrelevant because of 2 limit, so we pop them all,
BUT we keep track of their rectangles because 56810=20 might be the maximum that we ever get.
so we calculate the area of rectangle with that height and pop it until reach 2. 

what if 2 5 6 8 10 3 -> still pop everything until 2.
calculate the entire area 2*(6-0+1) = 14 and add to maximum if applicable.
then pop.

so, if we have:
5 3 3 3 3 3 3 3 
look at 5, push it
look at 3, calculate 5*1, pop it, push 3;



2 1 2

push 2, idx=0
calculate 2*1, pop 2, push 1, idx=0
push 2, idx=2

stack = {1_0 and 2_2} current_time=2
calculate 2*1 pop
calcualte 1*3 pop
done


*/