#include <iostream>
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0; 
        int right = m*n-1;

        while (left <= right) {
            int mid = (left + right)/2;
            int row = mid / n;
            int col = mid % n;
            if(matrix[row][col] > target) {
                right = mid - 1;
            } else if (matrix[row][col] < target) {
                left = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};



int main() {
    Solution mySol;
    std::vector<std::vector<int>> myMatrix {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int myTarget {60};

    bool result = mySol.searchMatrix(myMatrix, myTarget);
    std::cout << "Result is: " << result << std::endl;

    return 0;
}



/*

10 20 30 40
50 60 70 80
90 100 110 120

*/