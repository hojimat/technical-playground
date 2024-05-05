#include <iostream>

// Include your libraries here:

// Define a logger
#define LOG(x) std::cout << "Result: " << x << std::endl

class Solution {
public:

    // Copy a member function from LeetCode here:
    bool works(int x) {}
    
};


int main() {
    Solution mySol; // instantiate Solution

    int testCase; // sample input test case
    bool result = mySol.works(testCase); // save the result

    LOG(result); // output the result
    return 0;
}
