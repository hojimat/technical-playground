#include <iostream>
#include <array>
#include <string>
#include <random>
#include <map>

using std::cout, std::endl, std::cin;
using std::array, std::string, std::map;
using std::random_device, std::mt19937, std::uniform_int_distribution;


/*
 * EXTENSIONS AND REQUIRED EDITS:
 * - add Cell class and Ship class instead of simple index vectors:
 *       class Cell will represent a single cell in the grid
 *       class Ship will be a collection of k cells.
 * 
 * - ships are currently not overlapping but touching, so 5-cell ship and 1-cell ship may be mistaken for a 6-cell ship;
 *      next task is to remove touching
 *
 * - code for 1-, 3-, and 5-cell ships is now simply repeated: of course, I have to refactor it and put it inside a loop;
 *
 * - currently, user's ship placement is random --- manual placement option must be available
 *
 * - currently, computer is not as smart as it can be --- e.g. it doesn't make strategic considerations, such as 
 *      the number of ships left, must make it smarter
 *
 * - currently, the letter-to-index map is stored in instances, it should be a static attribute
 *
 * - currently, game goes on forever until you break it, must have a clear winner and loser
*/

class Grid {
    private:
        //int ownGrid[10][10] = {0};
        //int opponentGrid[10][10] = {0};
        array<array<int, 10>, 10> ownGrid = {0};
        array<array<int, 10>, 10> opponentGrid = {0};


    public:

        int getCell(int xx, int yy) {
            return ownGrid[xx][yy];
        }

        void setOwnCell (int xx, int yy, int val) {
            ownGrid[xx][yy] = val ;
        }
        
        void setOpponentCell (int xx, int yy, int val) {
            opponentGrid[xx][yy] = val ;
        }

        void generate_ships(int n1, int n3, int n5) { // takes arguments of # of 1-, 3-, 5-cell ships
            // Set up random integer generators
            random_device rand_dev;
            mt19937 generator(rand_dev());
            uniform_int_distribution<int> distr1(0,1), distr5(0,5), distr7(0,7), distr9(0,9);

            bool vertical; // direction
            int randX, randY; // starting cell index
            
            
            // Generate 5-cell ships
            for (int m=0; m<n5; m++) {
                bool overlap;
                array<array<int, 10>, 10> tempGrid;

                do {
                    overlap = false;
                    auto tempGrid = ownGrid; // copy current grid for checking purposes
                    vertical = distr1(generator);
                    randX = distr5(generator);
                    randY = distr9(generator);
                    if (vertical) {
                        for (int k=0; k<5; k++) {
                            tempGrid[randX+k][randY] ++;
                            if (tempGrid[randX+k][randY]>1) {
                                overlap = true;
                            }
                        }

                    } else {
                        for (int k=0; k<5; k++) {
                            tempGrid[randY][randX+k] ++;
                            if (tempGrid[randY][randX+k]>1) {
                                overlap = true;
                            }
                        }
                    }
                } while (overlap);

                ownGrid = tempGrid;
            }


            // Generate 3-cell ships
            for (int m=0; m<n3; m++) {
                bool overlap;
                array<array<int, 10>, 10> tempGrid;

                do {
                    overlap = false;
                    auto tempGrid = ownGrid; // copy current grid for checking purposes
                    vertical = distr1(generator);
                    randX = distr7(generator);
                    randY = distr9(generator);
                    if (vertical) {
                        for (int k=0; k<3; k++) {
                            tempGrid[randX+k][randY] ++;
                            if (tempGrid[randX+k][randY]>1) {
                                overlap = true;
                            }
                        }

                    } else {
                        for (int k=0; k<3; k++) {
                            tempGrid[randY][randX+k] ++;
                            if (tempGrid[randY][randX+k]>1) {
                                overlap = true;
                            }
                        }
                    }
                } while (overlap);

                ownGrid = tempGrid;
            }


            // Generate 1-cell ships
            for (int m=0; m<n1; m++) {
                bool overlap;
                array<array<int, 10>, 10> tempGrid;

                do {
                    overlap = false;
                    auto tempGrid = ownGrid; // copy current grid for checking purposes
                    randX = distr9(generator);
                    randY = distr9(generator);
                    tempGrid[randX][randY] ++;
                    if (tempGrid[randX][randY]>1) {
                        overlap = true;
                    }
                } while (overlap);

                ownGrid = tempGrid;
            }

        }

        void print_grid() {
            cout << endl;
            cout << "   A B C D E F G H I J\t\t\t   A B C D E F G H I J" << endl;
            cout << "   -------------------\t\t\t   -------------------" << endl;
            for(int i=0; i<10; i++) {
                cout << i << "| ";
                for(int j=0; j<10; j++) {
                    cout << ownGrid[i][j] << " ";
                }
                cout << "\t\t\t";

                cout << i << "| ";
                for(int j=0; j<10; j++) {
                    cout << opponentGrid[i][j] << " ";
                }

                cout << endl;
            }
            cout << endl << "\tMy grid\t\t\t\t    Opponent's grid" << endl;
        }


};

class Player {
    public:
        Grid povGrid;
        map<char,int> letters = {{'a',0}, {'b',1}, {'c',2}, {'d',3}, {'e',4}, {'f',5}, {'g',6}, {'h',7}, {'i',8}, {'j',9}};
        map<char,int> numbers = {{'0',0}, {'1',1}, {'2',2}, {'3',3}, {'4',4}, {'5',5}, {'6',6}, {'7',7}, {'8',8}, {'9',9}};
        Player* opponent;

        void shoot(int xx, int yy, string playername) {
            int myCell = opponent->povGrid.getCell(xx,yy);
            if (myCell==1) {
                cout << playername << " hit the target!\n";
                povGrid.setOpponentCell(xx,yy,1);
                opponent->povGrid.setOwnCell(xx,yy,7);
            }else {
                cout << playername << " missed!\n";
                povGrid.setOpponentCell(xx,yy,9);
            }
        }

};



int main() {
    Player user;
    Player computer;
    user.opponent = &computer;
    computer.opponent = &user;
    string coordinate;
    string username;
    int x, y;
    bool showMustGoOn = true;

    computer.povGrid.generate_ships(3,2,1); 
    user.povGrid.generate_ships(3,2,1);

    
    // Set up random integer generators
    random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_int_distribution<int> distr(0,9);

    cout << "GAME RULES" << endl << 
        "1) Every player makes one move and passes it to the opponent" << endl <<
        "2) If a player hits the target, she gets to keep the move" << endl << 
        "3) Numbers mean the following: 0 = default, 9 = confirmed empty, 1 = confirmed ship, 7 = ship injured" << endl;

    cout << "\n\n\nEnter your name: ";
    cin >> username; 
    cout << "Great, " << username << " let's start!" << endl;

    while (showMustGoOn) { 
       user.povGrid.print_grid();
       cout << "\n\n\n\n\n\nEnter a coordinate (e.g. 'e3' or 'f7'):";
       cin >> coordinate;
       y = user.letters[coordinate[0]];
       x = user.numbers[coordinate[1]];

       user.shoot(x,y, username);
       
       int shootX, shootY;
       shootX = distr(generator);
       shootY = distr(generator);

       computer.shoot(shootX,shootY, "Computer");
    }

    return 0;
}
