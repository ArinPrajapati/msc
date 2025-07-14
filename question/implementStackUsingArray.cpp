// implement stack with Array 
#include <vector>
#include <iostream>

using namespace std;

class ArrayStack {
public:
    vector<int>v;
    ArrayStack() {
      v= {};
    }
    
    void push(int x) {
      v.push_back(x);
    }
    
    int pop() {
    if (v.empty()) {
      cout << "Stack is empty" << endl;
      return -1;
    }
    int lastElement = v.size() - 1;
    int topElement = v[lastElement];

    v.pop_back();

      return topElement;
    }
    
    int top() {
    if (v.empty()) {
      cout << "Stack is empty" << endl;
      return -1;
    }
     return v[v.size() - 1];
    }
    
    bool isEmpty() {
    return v.empty();
    }
};
