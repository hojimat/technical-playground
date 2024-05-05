#include <iostream>
#include <string>
#include <vector>
#include <stack>


class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> myStack {};

        for(const std::string& token : tokens) {
            if (token=="+" || token=="-" || token=="*" || token=="/") {
                if (myStack.size() <= 1) {
                    return 404;
                }

                int right = myStack.top();
                myStack.pop();
                int left = myStack.top();
                myStack.pop(); 
                
                int replacement = evaluate(left, right, token);
                myStack.push(replacement);
            } else {
                int intToken = std::stoi(token);
                myStack.push(intToken);
            }

        }

        if (myStack.size() == 1) {
            return myStack.top();
        } else {
            return 303;
        }
    }
private:
    int evaluate(int& left, int& right, const std::string& operation) {
        if (operation=="+") {
            return left+right;
        } else if (operation=="-") {
            return left-right;
        } else if (operation=="*") {
            return left*right;
        } else if (operation=="/") {
            return left/right;
        } else {
            return 404;
        }
    }
};


int main() {
    Solution mySol;
    std::vector<std::string> myTokens {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int result = mySol.evalRPN(myTokens);

    std::cout << "Result is: " << result << std::endl;

    return 0;
}