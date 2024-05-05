#include <iostream>
#include <deque>
#include <vector>
using std::cout, std::deque, std::vector, std::endl;

class Node {
    public:
        int x;
        int y;
        Node(int xx, int yy){
            x = xx;
            y = yy;
        };
};

class Snake {
    public:
        deque<Node> nodes; 
        Snake () {
            cout << "Snake created" << endl;
        }

       

};

class Nature {};



int main() {
    Snake mySnake;



    return 0;
}
