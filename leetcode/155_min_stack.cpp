#include <iostream>
#include <stack>

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (mins.empty() || mins.top()>=val) {
            mins.push(val);
        }
        values.push(val);
    }
    
    void pop() {
        if (mins.top()==values.top()) {
            mins.pop();
        }
        values.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return mins.top();
    }
private:
    std::stack<long> values {};
    std::stack<long> mins {}; // some have optimized using a pair of (val, counter) for this stack's entries
};


int main() {
    MinStack* obj = new MinStack();
    obj->push(3);
    obj->push(2);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();

    return 0;
}
