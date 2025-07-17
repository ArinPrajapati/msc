#include <cstddef>
#include <vector>
#include <climits>

using namespace std;
class MinStack {
public:
    vector<int> stack;
    vector<int> minStack; // monotonic 

    MinStack() {
        stack = vector<int>();
        minStack = vector<int>();
    }
    
    void push(int val) {
        stack.push_back(val);
        if (minStack.empty() || val < minStack.back()) {
            minStack.push_back(val);
        }    
    }
    
    void pop() {
        if (stack.empty()) return;
        int topValue = stack.back();
        stack.pop_back();
        if (topValue == minStack.back()) {
            minStack.pop_back();
        }
    }
    
    int top() {
        if (stack.empty()) return NULL;
        return stack.back();
    }
    
    int getMin() {
        if (minStack.empty()) return NULL;
        return minStack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
