#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // for each row, col, and box store an unordered set
        std::vector<std::unordered_set<char>> rows(9), cols(9), boxes(9);

        for(int i=0; i<9; i++) { // for each row i
            for(int j=0; j<9; j++) { // for each row j
                int ij = (i/3) * 3 + (j/3); // box index
                char val = board[i][j];
                if(val=='.'){
                    continue;
                }
            
                if(rows[i].count(val) || cols[j].count(val) || boxes[ij].count(val)) {
                    return false;
                }

                rows[i].insert(val);
                cols[j].insert(val);
                boxes[ij].insert(val);
            }
        }
        return true;
    }
};


int main() {
    Solution mySol;
    std::vector<std::vector<char>> myBoard {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };
    bool myResult = mySol.isValidSudoku(myBoard);
    std::cout << myResult << std::endl;
    return 0;
}















                /* 0,0,0,1,1,1,2,2,2,
                   0,0,0,1,1,1,2,2,2,
                   0,0,0,1,1,1,2,2,2,
                   3,3,3,4,4,4,5,5,5,
                   3,3,3,4,4,4,5,5,5,
                   3,3,3,4,4,4,5,5,5,
                   6,6,6,7,7,7,8,8,8,
                   6,6,6,7,7,7,8,8,8,
                   6,6,6,7,7,7,8,8,8,
               
               row doesn't matter, row/3 matters
               col doesn't matter, col/3 matters

               box_index = f(row/3, col/3) = ceil(row/3) * 3 + ceil(col/3)

               row=1, col=2 -> 0*a + 0*b -> 0
               row=5, col=6 -> 1*a + 2*b -> a=3, b=1 or a=1, b=4
               row=7, col=4 -> 2*a + 1*b = 7 -> a=3, b=1 
                */


/* 

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        
        1. check cols
        2. check rows
        3. check cells (skip if empty)
        size if guaranteed 9x9
        

        // Check rows
        for(int row=0; row<9; row++) {
            if (hasDuplicates(board[row])) { return false;}
        }
        std::cout << "Passed row check\n";
        // Check cols
        for(int col=0; col<9; col++) {
            std::vector<char> myCol {};
            for(int row=0; row<9; row++) {
                myCol.push_back(board[row][col]);
            }

            if (hasDuplicates(myCol)) { return false; }
        }
        std::cout << "Passed col check\n";


        // Check cells
        for (int row=0; row<9; row+=3) {
            for (int col=0; col<9; col+=3) {
                if (hasDuplicatesInCell(board, row, col)) {
                    return false;
                    std::cout << "Passed cell check";
                }
            }
        }

        return true;
    }
private:
    bool hasDuplicates(std::vector<char> vektor) {
        std::unordered_set<char> basket {};
        for(const char& el : vektor) {
            if (el == '.') {continue;}
            auto existed = !basket.insert(el).second;
            if(existed) {return true;}
            
        }
        return false;
    }

    bool hasDuplicatesInCell(std::vector<std::vector<char>>& matrix, int startRow, int startCol) {
        std::unordered_set<char> basket {};
        for(int i=startRow; i<startRow+3; i++) {
            for(int j=startCol; j<startCol+3; j++) {
                char value = matrix[i][j];
                if (value != '.') {
                    if (!basket.insert(value).second) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
*/